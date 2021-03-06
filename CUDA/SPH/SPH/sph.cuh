#pragma once

#include <cmath>
#include "cuda_runtime.h"

//const float M_PI = 3.14159265358979323846;

struct Parameters {
	/*
	float DomainX = 100.0f;
	float DomainY = 100.0f;
	float DomainZ = 100.0f;
	*/
	float3 Domain = make_float3(100.0f, 100.0f, 100.0f);
	float MaxParticles = 65536;
	float RestDensity = 1000.0f;
	float GasConst = 100.0f;
	float3 G = make_float3(0.0f, 0.0f, -9.8f);
	float Mass = 6.25f;
	float H = 2.4f;
	float Visc = 10.0f;
	float DT = 0.0035f;
	float BoundDamp = -0.5f;
	bool DoCollisions = false;
	float3 CollisionBoxStart = make_float3(0, 0, 0);
	float3 CollisionBoxEnd = make_float3(0, 0, 0);
	float3 CollisionBox = make_float3(0, 0, 0);
	float3 CollisionBoxTransform = make_float3(0, 0, 0);
};

struct Particles {
	int NumP;
	int NumCells;
	float3* X;
	float3* V;
	float3* F;
	float* P;
	float* Rho;
	int* Cells;
	int* NeighbourCells;
	int* ParticleCellID;
};

struct BoxCollider {
	float3 Min;
	float3 Max;
};

Particles AllocateMemory(int NumP, int NumCells);
void FreeMemory(Particles P);
void InitSph(Parameters Params, Particles P, float3 Start, float3 End);
void FirstStep(Parameters Params, Particles P);
void SimStep(Parameters Params, Particles P);
void PutParticlesInCells(Parameters Params, Particles P);