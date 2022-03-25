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

__global__ void CalculateNeighbours(Parameters Params, Particles* P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P->NumP) {
		int NumXCell = (Params.DomainX / Params.H) + 1;
		int NumYCell = (Params.DomainY / Params.H) + 1;
		int NumZCell = (Params.DomainZ / Params.H) + 1;

		int XCell = P->X->x / Params.H;
		int YCell = P->X->y / Params.H;
		int ZCell = P->X->z / Params.H;

		int Count = 0;

		for (int x = XCell - 1; x <= XCell + 1; x++) {
			for (int y = YCell - 1; y <= YCell + 1; y++) {
				for (int z = ZCell - 1; z <= ZCell + 1; z++) {
					int id = (((x * NumYCell) + y) * NumXCell) + z;
					P->NeighbourCells[(i * 27) + Count] = (x >= 0 && x < NumXCell&& y >= 0 && y < NumYCell&& z >= 0 && z < NumZCell) ? id : -1;
					Count++;
				}
			}
		}
	}
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

__global__ void UpdatePosition(Parameters Params, Particles* P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P->NumP) {
		P->X[i] = P->X[i] + (Params.DT * P->V[i]);
	}
}

__global__ void ComputeBoundries(Parameters Params, Particles* P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P->NumP) {
		if (P->X[i].x - Params.H < 0.0f) {
			P->V[i].x = P->V[i].x * Params.BoundDamp;
			P->X[i].x = Params.H;
		}
		if (P->X[i].x + Params.H > Params.DomainX) {
			P->V[i].x = P->V[i].x * Params.BoundDamp;
			P->X[i].x = Params.DomainX - Params.H;
		}

		if (P->X[i].y - Params.H < 0.0f) {
			P->V[i].y = P->V[i].y * Params.BoundDamp;
			P->X[i].y = Params.H;
		}
		if (P->X[i].y + Params.H > Params.DomainY) {
			P->V[i].y = P->V[i].y * Params.BoundDamp;
			P->X[i].y = Params.DomainY - Params.H;
		}

		if (P->X[i].z - Params.H < 0.0f) {
			P->V[i].z = P->V[i].z * Params.BoundDamp;
			P->X[i].z = Params.H;
		}
		if (P->X[i].z + Params.H > Params.DomainZ) {
			P->V[i].z = P->V[i].z * Params.BoundDamp;
			P->X[i].z = Params.DomainZ - Params.H;
		}
	}
}

__global__ void FindParticleCellIDs(Parameters Params, Particles* P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < P->NumP) {
		int CellID = CalculateParticleCellID(Params, P->X[i]);
		P->ParticleCellID[i] = CellID;
	}
}

__global__ void SetIndices(int* Indices, int N) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < N) {
		Indices[i] = i;
	}
}

__global__ void SortParticleData(int* Indices, Particles* P, float3* TX, float3* TV, float3* TF, float* TP, float* TRho) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < P->NumP) {
		TX[i] = P->X[i];
		TV[i] = P->V[i];
		TF[i] = P->F[i];
		TP[i] = P->P[i];
		TRho[i] = P->Rho[i];
	}
}

__global__ void CreateCells(int* Histogram, int* PrefixSum, int* Cells, int N) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < N) {
		Cells[i * 2] = PrefixSum[i];
		Cells[i * 2 + 1] = Histogram[i];
	}
}

void PutParticlesInCells(Parameters Params, Particles* P) {
	int BlockSize = 256;
	int NumBlocks = (P->NumP + BlockSize - 1) / BlockSize;

	FindParticleCellIDs << <NumBlocks, BlockSize >> > (Params, P);

	int* ParticleCellID_Out;
	int* Indices_In;
	int* Indices_Out;

	cudaMalloc(&ParticleCellID_Out, sizeof(int) * P->NumP);
	cudaMalloc(&Indices_In, sizeof(int) * P->NumP);
	cudaMalloc(&Indices_Out, sizeof(int) * P->NumP);

	SetIndices << <NumBlocks, BlockSize >> > (Indices_In, P->NumP);

	cudaDeviceSynchronize();

	void* TempStorage = NULL;
	size_t TempStorageBytes = 0;

	cub::DeviceRadixSort::SortPairs(TempStorage, TempStorageBytes, P->ParticleCellID, ParticleCellID_Out, Indices_In, Indices_Out, P->NumP);

	cudaMalloc(&TempStorage, TempStorageBytes);

	cub::DeviceRadixSort::SortPairs(TempStorage, TempStorageBytes, P->ParticleCellID, ParticleCellID_Out, Indices_In, Indices_Out, P->NumP);

	cudaDeviceSynchronize();
	
	cudaFree(TempStorage);

	cudaMemcpy(P->ParticleCellID, ParticleCellID_Out, sizeof(int) * P->NumP, cudaMemcpyDeviceToDevice);
	
	cudaFree(ParticleCellID_Out);
	cudaFree(Indices_In);

	float3* TX;
	float3* TV;
	float3* TF;
	float* TP;
	float* TRho;

	cudaMalloc(&TX, sizeof(float3) * P->NumP);
	cudaMalloc(&TV, sizeof(float3) * P->NumP);
	cudaMalloc(&TF, sizeof(float3) * P->NumP);
	cudaMalloc(&TP, sizeof(float) * P->NumP);
	cudaMalloc(&TRho, sizeof(float) * P->NumP);

	SortParticleData << <NumBlocks, BlockSize >> > (Indices_Out, P, TX, TV, TF, TP, TRho);
	cudaDeviceSynchronize();

	cudaMemcpy(P->X, TX, sizeof(float3) * P->NumP, cudaMemcpyDeviceToDevice);
	cudaMemcpy(P->V, TV, sizeof(float3) * P->NumP, cudaMemcpyDeviceToDevice);
	cudaMemcpy(P->F, TF, sizeof(float3) * P->NumP, cudaMemcpyDeviceToDevice);
	cudaMemcpy(P->P, TP, sizeof(float) * P->NumP, cudaMemcpyDeviceToDevice);
	cudaMemcpy(P->Rho, TRho, sizeof(float) * P->NumP, cudaMemcpyDeviceToDevice);

	cudaFree(TX);
	cudaFree(TV);
	cudaFree(TF);
	cudaFree(TP);
	cudaFree(TRho);

	cudaFree(Indices_Out);

	int* Histogram;
	cudaMalloc(&Histogram, sizeof(int) * P->NumCells);

	TempStorage = NULL;
	TempStorageBytes = 0;

	cub::DeviceHistogram::HistogramEven(TempStorage, TempStorageBytes, P->ParticleCellID, Histogram, P->NumCells, 0, P->NumCells, P->NumP);

	cudaMalloc(&TempStorage, TempStorageBytes);

	cub::DeviceHistogram::HistogramEven(TempStorage, TempStorageBytes, P->ParticleCellID, Histogram, P->NumCells, 0, P->NumCells, P->NumP);

	cudaDeviceSynchronize();

	cudaFree(TempStorage);

	int* PrefixSum;

	cudaMalloc(&PrefixSum, sizeof(int) * P->NumCells);

	TempStorage = NULL;
	TempStorageBytes = 0;

	cub::DeviceScan::ExclusiveSum(TempStorage, TempStorageBytes, Histogram, PrefixSum, P->NumCells);

	cudaMalloc(&TempStorage, TempStorageBytes);

	cub::DeviceScan::ExclusiveSum(TempStorage, TempStorageBytes, Histogram, PrefixSum, P->NumCells);
	cudaDeviceSynchronize();

	cudaFree(TempStorage);

	NumBlocks = (P->NumCells + BlockSize - 1) / BlockSize;

	CreateCells << <NumBlocks, BlockSize >> > (Histogram, PrefixSum, P->Cells, P->NumCells);
	cudaDeviceSynchronize();

	cudaFree(Histogram);
	cudaFree(PrefixSum);
}

Particles* allocateMemory(int NumP, int NumCells) {
	Particles* P;
	cudaMallocManaged(&P, sizeof(Particles));
	cudaMallocManaged(&(P->X), sizeof(float3) * NumP);
	cudaMallocManaged(&(P->F), sizeof(float3) * NumP);
	cudaMallocManaged(&(P->V), sizeof(float3) * NumP);
	cudaMallocManaged(&(P->P), sizeof(float) * NumP);
	cudaMallocManaged(&(P->Rho), sizeof(float) * NumP);
	cudaMallocManaged(&(P->Cells), sizeof(int) * NumCells);
	cudaMallocManaged(&(P->NeighbourCells), sizeof(int) * NumP * 27);
	cudaMallocManaged(&(P->ParticleCellID), sizeof(float) * NumP);

	P->NumP = NumP;
	P->NumCells = NumCells;

	return P;
}

void InitSph(Parameters Params, Particles* P) {
	for (int i = 0; i < P->NumP; i++) {
		P->V[i] = make_float3(0.0f, 0.0f, 0.0f);
		P->F[i] = make_float3(0.0f, 0.0f, 0.0f);
		P->P[i] = 0.0f;
		P->Rho[i] = 0.0f;
	}

	for (int i = 0; i < P->NumCells; i++) {
		P->Cells[i] = -1;
	}

	int nParticles = 0;

	for (float x = Params.DomainX / 2 - Params.DomainX / 4; x <= Params.DomainX / 2 + Params.DomainX / 4; x += Params.H) {
		for (float y = Params.DomainY / 2 - Params.DomainY / 4; y <= Params.DomainY / 2 + Params.DomainY / 4; y += Params.H) {
			for (float z = Params.H; z < Params.DomainZ - Params.H; z += Params.H) {
				if (nParticles < P->NumP) {
					float jitter = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
					P->X[nParticles].x = x + jitter;
					P->X[nParticles].y = y + jitter;
					P->X[nParticles].z = z;
					nParticles++;
				}
				else {
					return;
				}
			}
		}
	}
}

void FirstStep(Parameters Params, Particles* P) {
	int BlockSize = 256;
	int NumBlocks = (P->NumP + BlockSize - 1) / BlockSize;

	CalculateNeighbours << <NumBlocks, BlockSize >> > (Params, P);
	ComputeDensityPressure << <NumBlocks, BlockSize >> > (Params, P);
	ComputeForces << <NumBlocks, BlockSize >> > (Params, P);
	UpdateVelocityHalf << <NumBlocks, BlockSize >> > (Params, P);
	//UpdateVelocityHalf << <NumBlocks, BlockSize >> > (Params, P);
	UpdatePosition << <NumBlocks, BlockSize >> > (Params, P);
	ComputeBoundries << <NumBlocks, BlockSize >> > (Params, P);
	cudaDeviceSynchronize();
}

void SimStep(Parameters Params, Particles* P) {
	int BlockSize = 256;
	int NumBlocks = (P->NumP + BlockSize - 1) / BlockSize;

	CalculateNeighbours << <NumBlocks, BlockSize >> > (Params, P);
	ComputeDensityPressure << <NumBlocks, BlockSize >> > (Params, P);
	ComputeForces << <NumBlocks, BlockSize >> > (Params, P);
	UpdateVelocityHalf << <NumBlocks, BlockSize >> > (Params, P);
	UpdateVelocityHalf << <NumBlocks, BlockSize >> > (Params, P);
	UpdatePosition << <NumBlocks, BlockSize >> > (Params, P);
	ComputeBoundries << <NumBlocks, BlockSize >> > (Params, P);
	cudaDeviceSynchronize();
}