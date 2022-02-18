#include "sph.cuh"

__device__ float3 operator-(const float3& a, const float3& b);
__device__ float3 operator+(const float3& a, const float3& b);
__device__ float3 operator/(const float3& a, const float b);
__device__ float3 operator/(const float a, const float3& b);
__device__ float3 operator*(const float3& a, const float b);
__device__ float3 operator*(const float b, const float3& a);

__device__ int CalculateParticleCellID(Parameters Params, Particles* P);
__device__ float Sqr(float x);
__device__ float Sqr(float3 v);
