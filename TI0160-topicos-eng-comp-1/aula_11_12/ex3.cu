// Exemplo 3 — Volume 3D (Threads 3D)
// Volume_3d.cu
#include <iostream>
#include <cuda_runtime.h>

__global__ void preencherVolume(float *vol, int X, int Y, int Z) {
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;
    int z = blockIdx.z * blockDim.z + threadIdx.z;
    if (x < X && y < Y && z < Z) {
        int idx = (z * Y * X) + (y * X) + x;
        vol[idx] = x + y + z; // exemplo simples
    }
}

int main() {
    int X = 4, Y = 4, Z = 4;
    int N = X * Y * Z;
    float *h_vol = new float[N];
    float *d_vol;
    cudaMalloc(&d_vol, N * sizeof(float));

    dim3 block(2, 2, 2);
    dim3 grid((X+1)/2, (Y+1)/2, (Z+1)/2);

    preencherVolume<<<grid, block>>>(d_vol, X, Y, Z);
    cudaDeviceSynchronize();

    cudaMemcpy(h_vol, d_vol, N * sizeof(float), cudaMemcpyDeviceToHost);

    std::cout << "Valores do volume:\n";
    for (int i = 0; i < N; i++)
        std::cout << h_vol[i] << " ";
    std::cout << "\n";

    cudaFree(d_vol);
    delete[] h_vol;
}
