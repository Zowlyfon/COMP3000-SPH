#pragma once

#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include "utility.cuh"

// float3 operators

__device__ float3 operator-(const float3& a, const float3& b) {
    return make_float3(a.x - b.x, a.y - b.y, a.z - b.z);
}

__device__ float3 operator+(const float3& a, const float3& b) {
    return make_float3(a.x + b.x, a.y + b.y, a.z + b.z);
}

__device__ float3 operator/(const float3& a, const float b) {
    return make_float3(a.x / b, a.y / b, a.z / b);
}

__device__ float3 operator/(const float a, const float3& b) {
    return make_float3(a / b.x, a / b.y, a / b.z);
}

__device__ float3 operator*(const float3& a, const float b) {
    return make_float3(a.x * b, a.y * b, a.z * b);
}

__device__ float3 operator*(const float b, const float3& a) {
    return make_float3(a.x * b, a.y * b, a.z * b);
}

__device__ int CalculateParticleCellID(Parameters Params, float3 Pos) {
    int numXCell = (Params.DomainX / Params.H) + 1;
    int numYCell = (Params.DomainY / Params.H) + 1;
    int numZCell = (Params.DomainZ / Params.H) + 1;

    int xCell = Pos.x / Params.H;
    int yCell = Pos.y / Params.H;
    int zCell = Pos.z / Params.H;

    return (((xCell * numYCell) + yCell) * numXCell) + zCell;
}

__device__ float Sqr(float x) {
    return x * x;
}

__device__ float Sqr(float3 v) {
    return v.x * v.x + v.y * v.y + v.z * v.z;
}