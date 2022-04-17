#pragma once

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "utility.cuh"

// float3 operators

__host__ __device__ float3 operator-(const float3& a, const float3& b) {
    return make_float3(a.x - b.x, a.y - b.y, a.z - b.z);
}

__host__ __device__ float3 operator+(const float3& a, const float3& b) {
    return make_float3(a.x + b.x, a.y + b.y, a.z + b.z);
}

__host__ __device__ float3 operator+(const float3& a, const float& b) {
    return make_float3(a.x + b, a.y + b, a.z + b);
}

__host__ __device__ float3 operator/(const float3& a, const float b) {
    return make_float3(a.x / b, a.y / b, a.z / b);
}

__host__ __device__ float3 operator/(const float a, const float3& b) {
    return make_float3(a / b.x, a / b.y, a / b.z);
}

__host__ __device__ float3 operator*(const float3& a, const float b) {
    return make_float3(a.x * b, a.y * b, a.z * b);
}

__host__ __device__ float3 operator*(const float b, const float3& a) {
    return make_float3(a.x * b, a.y * b, a.z * b);
}

__host__ __device__ float3 operator*(const float3 a, const float3 b) {
    return make_float3(a.x * b.x, a.y * b.y, a.z * b.z);
}

__host__ __device__ float Dot(float3 a, float3 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

__host__ __device__ float Sqr(float x) {
    return x * x;
}

__host__ __device__ float Sqr(float3 v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}

__host__ __device__ float3 Abs(float3 a) {
    return make_float3(fabs(a.x), fabs(a.y), fabs(a.z));
}

__host__ __device__ float Length(float3 a) {
    float R2 = Sqr(a);
    return sqrtf(R2);
}

__host__ __device__ float3 Normalise(float3 a) {
    float R = Length(a);
    return a / R;
}

__host__ __device__ float3 Max(float3 a, float3 b) {
    return make_float3(fmax(a.x, b.x), fmax(a.y, b.y), fmax(a.z, b.z));
}

__host__ __device__ float3 Min(float3 a, float3 b) {
    return make_float3(fmin(a.x, b.x), fmin(a.y, b.y), fmin(a.z, b.z));
}

__host__ __device__ int CalculateParticleCellID(Parameters Params, float3 Pos) {
    int numXCell = (Params.Domain.x / Params.H) + 1;
    int numYCell = (Params.Domain.y / Params.H) + 1;
    int numZCell = (Params.Domain.z / Params.H) + 1;

    int xCell = Pos.x / Params.H;
    int yCell = Pos.y / Params.H;
    int zCell = Pos.z / Params.H;

    return (((xCell * numYCell) + yCell) * numZCell) + zCell;
}


__host__ __device__ float3 BoxToSDF(float3 BoxStart, float3 BoxEnd) {
    return Abs(BoxStart) + BoxEnd;
}

// https://iquilezles.org/www/articles/distfunctions/distfunctions.htm
__host__ __device__ float BoxSDF(float3 X, float3 B, float r) {
    float3 Q = Abs(X) - (B / 2.0f);
    return Length(Max(Q, make_float3(0.0f, 0.0f, 0.0f))) + fmin(fmax(Q.x, fmax(Q.y, Q.z)), 0.0f) - r;
}

// https://www.iquilezles.org/www/articles/normalsSDF/normalsSDF.htm
__host__ __device__ float3 CalculateBoxSDFNormal(float3 X, float3 B, float r) {
    const float2 R = make_float2(0.0001, 0);
    return Normalise(make_float3(
        BoxSDF(X + make_float3(R.x, R.y, R.y), B, r) - BoxSDF(X - make_float3(R.x, R.y, R.y), B, r),
        BoxSDF(X + make_float3(R.y, R.x, R.y), B, r) - BoxSDF(X - make_float3(R.y, R.x, R.y), B, r),
        BoxSDF(X + make_float3(R.y, R.y, R.x), B, r) - BoxSDF(X - make_float3(R.y, R.y, R.x), B, r)));
}