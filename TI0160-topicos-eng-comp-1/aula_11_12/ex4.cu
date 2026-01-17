// Exemplo 4 — Identificadores de Thread e Block
// Identificadores.cu
#include <iostream>
#include <cuda_runtime.h>

__global__ void mostrarIDs() {
    printf("Grid(%d,%d,%d) Block(%d,%d,%d) Thread(%d,%d,%d)\n",
        gridDim.x, gridDim.y, gridDim.z,
        blockIdx.x, blockIdx.y, blockIdx.z,
        threadIdx.x, threadIdx.y, threadIdx.z);
}

int main() {
    dim3 grid(2, 2, 1);
    dim3 block(4, 4, 1);
    mostrarIDs<<<grid, block>>>();
    cudaDeviceSynchronize();
}
