#include "sph.cuh"

__host__ __device__ float3 operator-(const float3& a, const float3& b);
__host__ __device__ float3 operator+(const float3& a, const float3& b);
__host__ __device__ float3 operator/(const float3& a, const float b);
__host__ __device__ float3 operator/(const float a, const float3& b);
__host__ __device__ float3 operator*(const float3& a, const float b);
__host__ __device__ float3 operator*(const float b, const float3& a);
__host__ __device__ float3 operator*(const float3 a, const float3 b);

__host__ __device__ int CalculateParticleCellID(Parameters Params, float3 Pos);
__host__ __device__ float Sqr(float x);
__host__ __device__ float Sqr(float3 v);
__host__ __device__ float Dot(float3 a, float3 b);
__host__ __device__ float3 CalculateBoxSDFNormal(float3 X, float3 B, float H);
__host__ __device__ float BoxSDF(float3 X, float3 B, float r);
__host__ __device__ float3 BoxToSDF(float3 BoxStart, float3 BoxEnd);