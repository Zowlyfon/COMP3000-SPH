#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cub/cub.cuh>

#include "sph.cuh"
#include "utility.cuh"

__device__ float Poly6(const float H) {
	return 315.0 / (64.0f * M_PI * pow(H, 9.f));
}

__device__ float SpikyGrad(const float H) {
	return -15.f / (M_PI * pow(H, 6.f));
}

__device__ float ViscLap(const float H) {
	return 45.f / (M_PI * pow(H, 6.f));
}

__global__ void ComputeDensityPressure(Parameters Params, Particles* P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P->NumP) {

		// Compute Density Pressure
		float Rho = 0.0f;

		for (int k = 0; k < 27; k++) {
			// Cell is between 0 and NumCells
			if ((P->NeighbourCells[i * 27 + k] < P->NumCells && P->NeighbourCells[i * 27 + k] >= 0)) {
				continue;
			}


			int CellStart = P->Cells[P->NeighbourCells[i * 27 + k] * 2];
			int CellEnd = CellStart + P->Cells[P->NeighbourCells[i * 27 + k] * 2 + 1] - 1;

			// Number of particles in cell is atleast 1
			if (CellEnd < CellStart) {
				continue;
			}

			for (int j = CellStart; j <= CellEnd; j++) {
				float3 Rij;

				// Distance between particle i and j
				Rij = P->X[j] - P->X[i];

				// Squared distance
				float R2 = Sqr(Rij);

				// particle j is within the smoothing radius H
				if (R2 < Sqr(Params.H)) {
					Rho += Params.Mass * Poly6(Params.H) * powf(Sqr(Params.H) - R2, 3.0f);
				}
			}
		}

		P->Rho[i] = Rho;
		P->P[i] = Params.GasConst * (Rho - Params.RestDensity);
	}
}

__global__ void ComputeForces(Parameters Params, Particles* P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P->NumP) {
		float3 FPress = make_float3(0.0f, 0.0f, 0.0f);
		float3 FVisc = make_float3(0.0f, 0.0f, 0.0f);

		for (int k = 0; k < 27; k++) {
			// Cell is between 0 and NumCells
			if ((P->NeighbourCells[i * 27 + k] < P->NumCells && P->NeighbourCells[i * 27 + k] >= 0)) {
				continue;
			}


			int CellStart = P->Cells[P->NeighbourCells[i * 27 + k] * 2];
			int CellEnd = CellStart + P->Cells[P->NeighbourCells[i * 27 + k] * 2 + 1] - 1;

			// Number of particles in cell is atleast 1
			if (CellEnd < CellStart) {
				continue;
			}

			for (int j = CellStart; j <= CellEnd; j++) {
				if (i == j) {
					continue;
				}

				float3 Rij;
				Rij = P->X[j] - P->X[i];
				float R2 = Sqr(Rij);
				float R = sqrtf(R2);

				if (R < Params.H) {
					float3 RNorm = Rij / R;

					float Pij = P->P[i] + P->P[j];

					FPress = FPress + ((RNorm * -1.0f) * Params.Mass * Pij / (2.0f * P->Rho[j]) * SpikyGrad(Params.H) * powf(Params.H - R, 3.0f));

					float3 Vij = P->V[j] - P->V[i];

					FVisc = FVisc + (Params.Visc * Params.Mass * Vij / P->Rho[j] * ViscLap(Params.H) * (Params.H - R));
				}
			}
		}

		float3 FGrav = Params.G * Params.Mass / P->Rho[i];

		P->F[i] = FPress + FVisc + FGrav;
	}
}

__global__ void UpdateVelocityHalf(Parameters Params, Particles* P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P->NumP) {
		P->V[i] = P->V[i] + ((Params.DT / 2.0f) * P->F[i] / P->Rho[i]);
	}
}