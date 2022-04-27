#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include <cub/cub.cuh>

#include "sph.cuh"
#include "utility.cuh"

// https://stackoverflow.com/questions/14038589/what-is-the-canonical-way-to-check-for-errors-using-the-cuda-runtime-api
#define CudaErrorCheck(ans) { gpuAssert((ans), __FILE__, __LINE__); }
inline void gpuAssert(cudaError_t code, const char* file, int line, bool abort = true)
{
	if (code != cudaSuccess)
	{
		fprintf(stderr, "GPUassert: %s %s %d\n", cudaGetErrorString(code), file, line);
		if (abort) exit(code);
	}
}

__device__ float Poly6(const float H) {
	return 315.0 / (64.0f * M_PI * pow(H, 9.f));
}

__device__ float SpikyGrad(const float H) {
	return -15.f / (M_PI * pow(H, 6.f));
}

__device__ float ViscLap(const float H) {
	return 45.f / (M_PI * pow(H, 6.f));
}

__global__ void CalculateNeighbours(Parameters Params, Particles P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P.NumP) {
		int NumXCell = (Params.Domain.x / Params.H) + 1;
		int NumYCell = (Params.Domain.y / Params.H) + 1;
		int NumZCell = (Params.Domain.z / Params.H) + 1;

		int XCell = P.X[i].x / Params.H;
		int YCell = P.X[i].y / Params.H;
		int ZCell = P.X[i].z / Params.H;

		int Count = 0;

		for (int x = XCell - 1; x <= XCell + 1; x++) {
			for (int y = YCell - 1; y <= YCell + 1; y++) {
				for (int z = ZCell - 1; z <= ZCell + 1; z++) {
					int id = (((x * NumYCell) + y) * NumZCell) + z;
					P.NeighbourCells[(i * 27) + Count] = (x >= 0 && x < NumXCell&& y >= 0 && y < NumYCell&& z >= 0 && z < NumZCell) ? id : -1;
					Count++;
				}
			}
		}
	}
}

__global__ void ComputeDensityPressure(Parameters Params, Particles P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P.NumP) {

		// Compute Density Pressure
		float Rho = 0.0f;

		for (int k = 0; k < 27; k++) {
			// Cell is between 0 and NumCells
			if (!(P.NeighbourCells[i * 27 + k] < P.NumCells && P.NeighbourCells[i * 27 + k] >= 0)) {
				continue;
			}


			int CellStart = P.Cells[P.NeighbourCells[i * 27 + k] * 2];
			int CellEnd = CellStart + P.Cells[P.NeighbourCells[i * 27 + k] * 2 + 1] - 1;

			// Number of particles in cell is atleast 1
			if (CellEnd < CellStart) {
				continue;
			}

			for (int j = CellStart; j <= CellEnd; j++) {
				float3 Rij;

				// Distance between particle i and j
				Rij = P.X[j] - P.X[i];

				// Squared distance
				float R2 = Sqr(Rij);

				// particle j is within the smoothing radius H
				if (R2 < Sqr(Params.H)) {
					Rho += Params.Mass * Poly6(Params.H) * powf(Sqr(Params.H) - R2, 3.0f);
				}
			}
		}

		P.Rho[i] = Rho;
		P.P[i] = Params.GasConst * (Rho - Params.RestDensity);
	}
}

__global__ void ComputeForces(Parameters Params, Particles P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P.NumP) {
		float3 FPress = make_float3(0.0f, 0.0f, 0.0f);
		float3 FVisc = make_float3(0.0f, 0.0f, 0.0f);

		for (int k = 0; k < 27; k++) {
			// Cell is between 0 and NumCells
			if (!(P.NeighbourCells[i * 27 + k] < P.NumCells && P.NeighbourCells[i * 27 + k] >= 0)) {
				continue;
			}


			int CellStart = P.Cells[P.NeighbourCells[i * 27 + k] * 2];
			int CellEnd = CellStart + P.Cells[P.NeighbourCells[i * 27 + k] * 2 + 1] - 1;

			// Number of particles in cell is atleast 1
			if (CellEnd < CellStart) {
				continue;
			}

			for (int j = CellStart; j <= CellEnd; j++) {
				if (i == j) {
					continue;
				}

				float3 Rij;
				Rij = P.X[j] - P.X[i];
				float R2 = Sqr(Rij);
				float R = sqrtf(R2);

				if (R < Params.H) {
					float3 RNorm = Rij / R;

					float Pij = P.P[i] + P.P[j];

					FPress = FPress + ((RNorm * -1.0f) * Params.Mass * Pij / (2.0f * P.Rho[j]) * SpikyGrad(Params.H) * powf(Params.H - R, 3.0f));

					float3 Vij = P.V[j] - P.V[i];

					FVisc = FVisc + (Params.Visc * Params.Mass * Vij / P.Rho[j] * ViscLap(Params.H) * (Params.H - R));
				}
			}
		}

		float3 FGrav = Params.G * Params.Mass / P.Rho[i];

		P.F[i] = FPress + FVisc + FGrav;
	}
}

__global__ void UpdateVelocityHalf(Parameters Params, Particles P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P.NumP) {
		P.V[i] = P.V[i] + ((Params.DT / 2.0f) * P.F[i] / P.Rho[i]);
	}
}

__global__ void UpdatePosition(Parameters Params, Particles P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P.NumP) {
		P.X[i] = P.X[i] + (Params.DT * P.V[i]);
	}
}

__global__ void ComputeBoundries(Parameters Params, Particles P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P.NumP) {
		if (P.X[i].x - Params.H < 0.0f) {
			P.V[i].x = P.V[i].x * Params.BoundDamp;
			P.X[i].x = Params.H;
		}
		if (P.X[i].x + Params.H > Params.Domain.x) {
			P.V[i].x = P.V[i].x * Params.BoundDamp;
			P.X[i].x = Params.Domain.x - Params.H;
		}

		if (P.X[i].y - Params.H < 0.0f) {
			P.V[i].y = P.V[i].y * Params.BoundDamp;
			P.X[i].y = Params.H;
		}
		if (P.X[i].y + Params.H > Params.Domain.y) {
			P.V[i].y = P.V[i].y * Params.BoundDamp;
			P.X[i].y = Params.Domain.y - Params.H;
		}

		if (P.X[i].z - Params.H < 0.0f) {
			P.V[i].z = P.V[i].z * Params.BoundDamp;
			P.X[i].z = Params.H;
		}
		if (P.X[i].z + Params.H > Params.Domain.z) {
			P.V[i].z = P.V[i].z * Params.BoundDamp;
			P.X[i].z = Params.Domain.z - Params.H;
		}
	}
}


/*
__global__ void ComputeCollisions(Parameters Params, Particles* P, float3 ColliderStart, float3 ColliderEnd) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P.NumP) {
		if (P.X[i].x >= ColliderStart.x && P.X[i].x <= ColliderEnd.x &&
			P.X[i].y >= ColliderStart.y && P.X[i].y <= ColliderEnd.y &&
			P.X[i].z >= ColliderStart.z && P.X[i].z <= ColliderEnd.z) {
			float RX = P.X[i].x - ColliderStart.x;
			float NRX = ColliderEnd.x - P.X[i].x;

			float RY = P.X[i].y - ColliderStart.y;
			float NRY = ColliderEnd.y - P.X[i].y;

			float RZ = P.X[i].z - ColliderStart.z;
			float NRZ = ColliderEnd.z - P.X[i].z;

			if (RX < NRX && RX < RY && RX < NRY && RX < RZ && RX < NRZ) {
				P.X 
			}
		}
	}
}
*/

__global__ void ComputeCollisions(Parameters Params, Particles P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;

	if (i < P.NumP) {
		float3 NX = P.X[i] - Params.CollisionBoxTransform;
		float Distance = BoxSDF(NX, Params.CollisionBox, Params.H / 2.0f);
		if (Distance < 0.0f) {
#ifndef NDEBUG
			float3 X = P.X[i];
			float3 V = P.V[i];
#endif
			/*
			float3 R = (Params.CollisionBoxEnd - Params.CollisionBoxStart) / 2.0f;
			float3 BoxStart = -1.0f * R;
			//float3 BoxStart = Params.CollisionBoxStart - (Params.CollisionBoxStart + R);
			float3 BoxEnd = R;
			//float3 BoxEnd = Params.CollisionBoxEnd - (Params.CollisionBoxStart + R);
			float3 Box = BoxToSDF(BoxStart, BoxEnd);
			*/
			
			float3 Normal = CalculateBoxSDFNormal(NX, Params.CollisionBox, Params.H / 2.0f);
#ifndef NDEBUG
			float3 NormDist = Normal * Distance;
#endif
			P.X[i] = P.X[i] + Normal * Distance * -1.0f;
			float3 DampFactor = Normal * (Params.BoundDamp * -1.0f);
			//P.V[i] = P.V[i] - (P.V[i] * Normal * (Params.BoundDamp * -1.0f));
			P.V[i] = P.V[i] - 2 * Dot(P.V[i], Normal) * (Normal * 0.75);
#ifndef NDEBUG
			float3 UV = P.V[i];
			float3 UX = P.X[i];
			if (Normal.y >= 0.99 || Normal.y <= -0.99) {
				UV = P.V[i];
			}
#endif
			//P.V[i] = P.V[i] * Params.BoundDamp;
		}
	}
}

__global__ void FindParticleCellIDs(Parameters Params, Particles P) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < P.NumP) {
		int CellID = CalculateParticleCellID(Params, P.X[i]);
		P.ParticleCellID[i] = CellID;
	}
}

__global__ void SetIndices(int* Indices, int N) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < N) {
		Indices[i] = i;
	}
}

__global__ void SortParticleData(int* Indices, Particles P, float3* TX, float3* TV, float3* TF, float* TP, float* TRho) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < P.NumP) {
		TX[i] = P.X[Indices[i]];
		TV[i] = P.V[Indices[i]];
		TF[i] = P.F[Indices[i]];
		TP[i] = P.P[Indices[i]];
		TRho[i] = P.Rho[Indices[i]];
	}
}

__global__ void CreateCells(int* Histogram, int* PrefixSum, int* Cells, int N) {
	int i = blockIdx.x * blockDim.x + threadIdx.x;
	if (i < N) {
		Cells[i * 2] = PrefixSum[i];
		Cells[i * 2 + 1] = Histogram[i];
	}
}

void PutParticlesInCells(Parameters Params, Particles P) {
	int BlockSize = 256;
	int NumBlocks = (P.NumP + BlockSize - 1) / BlockSize;

	FindParticleCellIDs << <NumBlocks, BlockSize >> > (Params, P);
	//cudaDeviceSynchronize();

	int* ParticleCellID_Out;
	int* Indices_In;
	int* Indices_Out;

	CudaErrorCheck(cudaMalloc(&ParticleCellID_Out, sizeof(int) * P.NumP));
	CudaErrorCheck(cudaMalloc(&Indices_In, sizeof(int) * P.NumP));
	CudaErrorCheck(cudaMalloc(&Indices_Out, sizeof(int) * P.NumP));

	SetIndices << <NumBlocks, BlockSize >> > (Indices_In, P.NumP);

	//cudaDeviceSynchronize();

	void* TempStorage = NULL;
	size_t TempStorageBytes = 0;

	cub::DeviceRadixSort::SortPairs(TempStorage, TempStorageBytes, P.ParticleCellID, ParticleCellID_Out, Indices_In, Indices_Out, P.NumP);

	CudaErrorCheck(cudaMalloc(&TempStorage, TempStorageBytes));

	cub::DeviceRadixSort::SortPairs(TempStorage, TempStorageBytes, P.ParticleCellID, ParticleCellID_Out, Indices_In, Indices_Out, P.NumP);

	//cudaDeviceSynchronize();
	
	CudaErrorCheck(cudaFree(TempStorage));

	CudaErrorCheck(cudaMemcpy(P.ParticleCellID, ParticleCellID_Out, sizeof(int) * P.NumP, cudaMemcpyDeviceToDevice));
	
	CudaErrorCheck(cudaFree(ParticleCellID_Out));
	CudaErrorCheck(cudaFree(Indices_In));

	float3* TX;
	float3* TV;
	float3* TF;
	float* TP;
	float* TRho;

	CudaErrorCheck(cudaMalloc(&TX, sizeof(float3) * P.NumP));
	CudaErrorCheck(cudaMalloc(&TV, sizeof(float3) * P.NumP));
	CudaErrorCheck(cudaMalloc(&TF, sizeof(float3) * P.NumP));
	CudaErrorCheck(cudaMalloc(&TP, sizeof(float) * P.NumP));
	CudaErrorCheck(cudaMalloc(&TRho, sizeof(float) * P.NumP));

	SortParticleData << <NumBlocks, BlockSize >> > (Indices_Out, P, TX, TV, TF, TP, TRho);
	//cudaDeviceSynchronize();

	CudaErrorCheck(cudaMemcpy(P.X, TX, sizeof(float3) * P.NumP, cudaMemcpyDeviceToDevice));
	CudaErrorCheck(cudaMemcpy(P.V, TV, sizeof(float3) * P.NumP, cudaMemcpyDeviceToDevice));
	CudaErrorCheck(cudaMemcpy(P.F, TF, sizeof(float3) * P.NumP, cudaMemcpyDeviceToDevice));
	CudaErrorCheck(cudaMemcpy(P.P, TP, sizeof(float) * P.NumP, cudaMemcpyDeviceToDevice));
	CudaErrorCheck(cudaMemcpy(P.Rho, TRho, sizeof(float) * P.NumP, cudaMemcpyDeviceToDevice));

	CudaErrorCheck(cudaFree(TX));
	CudaErrorCheck(cudaFree(TV));
	CudaErrorCheck(cudaFree(TF));
	CudaErrorCheck(cudaFree(TP));
	CudaErrorCheck(cudaFree(TRho));

	CudaErrorCheck(cudaFree(Indices_Out));

	int* Histogram;
	CudaErrorCheck(cudaMalloc(&Histogram, sizeof(int) * P.NumCells));

	TempStorage = NULL;
	TempStorageBytes = 0;

	cub::DeviceHistogram::HistogramEven(TempStorage, TempStorageBytes, P.ParticleCellID, Histogram, P.NumCells, 0, P.NumCells, P.NumP);

	CudaErrorCheck(cudaMalloc(&TempStorage, TempStorageBytes));

	cub::DeviceHistogram::HistogramEven(TempStorage, TempStorageBytes, P.ParticleCellID, Histogram, P.NumCells, 0, P.NumCells, P.NumP);

	//cudaDeviceSynchronize();

	CudaErrorCheck(cudaFree(TempStorage));

	int* PrefixSum;

	CudaErrorCheck(cudaMalloc(&PrefixSum, sizeof(int) * P.NumCells));

	TempStorage = NULL;
	TempStorageBytes = 0;

	cub::DeviceScan::ExclusiveSum(TempStorage, TempStorageBytes, Histogram, PrefixSum, P.NumCells);

	CudaErrorCheck(cudaMalloc(&TempStorage, TempStorageBytes));

	cub::DeviceScan::ExclusiveSum(TempStorage, TempStorageBytes, Histogram, PrefixSum, P.NumCells);
	//cudaDeviceSynchronize();

	CudaErrorCheck(cudaFree(TempStorage));

	NumBlocks = (P.NumCells + BlockSize - 1) / BlockSize;

	CreateCells << <NumBlocks, BlockSize >> > (Histogram, PrefixSum, P.Cells, P.NumCells);
	//cudaDeviceSynchronize();

	cudaError_t err = cudaGetLastError();
	if (err != cudaSuccess) {
		printf("CUDA error: %s\n", cudaGetErrorString(err));
	}

	CudaErrorCheck(cudaFree(Histogram));
	CudaErrorCheck(cudaFree(PrefixSum));
}

Particles AllocateMemory(int NumP, int NumCells) {
	//Particles* P;
	//cudaMallocManaged(&P, sizeof(Particles));
	Particles P;
	CudaErrorCheck(cudaMallocManaged(&(P.X), sizeof(float3) * NumP));
	CudaErrorCheck(cudaMallocManaged(&(P.F), sizeof(float3) * NumP));
	CudaErrorCheck(cudaMallocManaged(&(P.V), sizeof(float3) * NumP));
	CudaErrorCheck(cudaMallocManaged(&(P.P), sizeof(float) * NumP));
	CudaErrorCheck(cudaMallocManaged(&(P.Rho), sizeof(float) * NumP));
	CudaErrorCheck(cudaMallocManaged(&(P.Cells), sizeof(int) * NumCells * 2));
	CudaErrorCheck(cudaMallocManaged(&(P.NeighbourCells), sizeof(int) * NumP * 27));
	CudaErrorCheck(cudaMallocManaged(&(P.ParticleCellID), sizeof(float) * NumP));

	P.NumP = NumP;
	P.NumCells = NumCells;

	return P;
}

void FreeMemory(Particles P) {
	CudaErrorCheck(cudaFree(P.ParticleCellID));
	CudaErrorCheck(cudaFree(P.NeighbourCells));
	CudaErrorCheck(cudaFree(P.Cells));
	CudaErrorCheck(cudaFree(P.Rho));
	CudaErrorCheck(cudaFree(P.P));
	CudaErrorCheck(cudaFree(P.V));
	CudaErrorCheck(cudaFree(P.F));
	CudaErrorCheck(cudaFree(P.X));
}

void InitSph(Parameters Params, Particles P, float3 Start, float3 End) {
	for (int i = 0; i < P.NumP; i++) {
		P.V[i] = make_float3(0.0f, 0.0f, 0.0f);
		P.F[i] = make_float3(0.0f, 0.0f, 0.0f);
		P.P[i] = 0.0f;
		P.Rho[i] = 0.0f;
	}

	for (int i = 0; i < P.NumCells; i++) {
		P.Cells[i] = -1;
	}

	int nParticles = 0;

	for (float x = Start.x; x <= End.x; x += Params.H) {
		for (float y = Start.y; y <= End.y; y += Params.H) {
			for (float z = Start.z; z <= End.z; z += Params.H) {
				if (nParticles < P.NumP) {
					float jitter = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
					P.X[nParticles].x = x + jitter;
					P.X[nParticles].y = y + jitter;
					P.X[nParticles].z = z;
					nParticles++;
				}
				else {
					return;
				}
			}
		}
	}
}

void FirstStep(Parameters Params, Particles P) {
	int BlockSize = 256;
	int NumBlocks = (P.NumP + BlockSize - 1) / BlockSize;

	CalculateNeighbours << <NumBlocks, BlockSize >> > (Params, P);
	ComputeDensityPressure << <NumBlocks, BlockSize >> > (Params, P);
	ComputeForces << <NumBlocks, BlockSize >> > (Params, P);
	UpdateVelocityHalf << <NumBlocks, BlockSize >> > (Params, P);
	//UpdateVelocityHalf << <NumBlocks, BlockSize >> > (Params, P);
	UpdatePosition << <NumBlocks, BlockSize >> > (Params, P);
	ComputeBoundries << <NumBlocks, BlockSize >> > (Params, P);
	if (Params.DoCollisions) {
		ComputeCollisions << <NumBlocks, BlockSize >> > (Params, P);
	}
	CudaErrorCheck(cudaDeviceSynchronize());
}

void SimStep(Parameters Params, Particles P) {
	int BlockSize = 256;
	int NumBlocks = (P.NumP + BlockSize - 1) / BlockSize;

	CalculateNeighbours << <NumBlocks, BlockSize >> > (Params, P);
	ComputeDensityPressure << <NumBlocks, BlockSize >> > (Params, P);
	ComputeForces << <NumBlocks, BlockSize >> > (Params, P);
	UpdateVelocityHalf << <NumBlocks, BlockSize >> > (Params, P);
	UpdateVelocityHalf << <NumBlocks, BlockSize >> > (Params, P);
	UpdatePosition << <NumBlocks, BlockSize >> > (Params, P);
	ComputeBoundries << <NumBlocks, BlockSize >> > (Params, P);
	if (Params.DoCollisions) {
		ComputeCollisions << <NumBlocks, BlockSize >> > (Params, P);
	}
	//CudaErrorCheck(cudaDeviceSynchronize());
}

#ifndef NDEBUG
int main() {
	Parameters Params;
	Params.Domain = make_float3(500.0, 500.0, 500.0);
	float3 SpawnBoxStart = make_float3((Params.Domain.x / 2) - (Params.Domain.x / 4), (Params.Domain.y / 2) - (Params.Domain.y / 4), (Params.Domain.z / 2) - (Params.Domain.z / 4));
	float3 SpawnBoxEnd = make_float3((Params.Domain.x / 2) + (Params.Domain.x / 4), (Params.Domain.y / 2) + (Params.Domain.y / 4), (Params.Domain.z / 2) + (Params.Domain.z / 4));
	int numP = ((SpawnBoxEnd.x - SpawnBoxStart.x) / Params.H) * ((SpawnBoxEnd.y - SpawnBoxStart.y) / Params.H) * ((SpawnBoxEnd.z - SpawnBoxStart.z) / Params.H);
	int numCells = ((Params.Domain.x / Params.H) + 1) * ((Params.Domain.y / Params.H) + 1) * ((Params.Domain.z / Params.H) + 1);
	Particles P = AllocateMemory(numP, numCells);
	bool ShouldRun = true;

	Params.CollisionBoxStart = make_float3(-1.0f, 70.f, -1.0f);
	Params.CollisionBoxEnd = make_float3(101.0f, 100.0f, 15.0f);
	float3 R = (Params.CollisionBoxEnd - Params.CollisionBoxStart) / 2.0f;
	Params.CollisionBox = BoxToSDF(-1.0f * R, R);
	Params.CollisionBoxTransform = Params.CollisionBoxStart + R;
	Params.DoCollisions = true;


	InitSph(Params,
		P,
		SpawnBoxStart,
		SpawnBoxEnd);
	PutParticlesInCells(Params, P);
	CudaErrorCheck(cudaDeviceSynchronize());
	FirstStep(Params, P);

	int steps = 0;
	while (ShouldRun) {
		PutParticlesInCells(Params, P);
		SimStep(Params, P);
		CudaErrorCheck(cudaDeviceSynchronize());
		//steps++;
		if (steps >= 2) {
			ShouldRun = false;
		}
	}

	FreeMemory(P);
}
#endif