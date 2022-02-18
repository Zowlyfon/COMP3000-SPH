#include <cmath>

struct Parameters {
	float DomainX = 100.0f;
	float DomainY = 100.0f;
	float DomainZ = 100.0f;
	float MaxParticles = 65536;
	float Mass = 6.25f;
	float H = 2.4f;
	float Visc = 10.0f;
	float DT = 0.0035f;
	float BoundDamp = -0.5f;
};

struct Particles {
	int numP;
	int numCells;
	float3* x;
	float3* v;
	float3* f;
	float* p;
	float* rho;
	int* cells;
	int* neighbourCells;
	int* particleCellID;
};