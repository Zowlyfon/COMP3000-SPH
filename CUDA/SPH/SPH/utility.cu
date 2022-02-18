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