#include <iostream>
#include <cuda_runtime.h>
#include <chrono>   // para medir tempo da CPU

#define N 1000000  // tamanho do vetor
#define BLOCK_SIZE 256

// ----------------------------------------------------
// Kernel CUDA: soma dois vetores A e B em C
// ----------------------------------------------------
__global__ void vectorAddGPU(float *A, float *B, float *C, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n)
        C[i] = A[i] + B[i];
}

// ----------------------------------------------------
// Soma na CPU (sequencial)
// ----------------------------------------------------
void vectorAddCPU(float *A, float *B, float *C, int n) {
    for (int i = 0; i < n; i++)
        C[i] = A[i] + B[i];
}

int main() {
    size_t size = N * sizeof(float);

    // Alocação no host (CPU)
    float *h_A = new float[N];
    float *h_B = new float[N];
    float *h_C_cpu = new float[N];
    float *h_C_gpu = new float[N];

    // Inicializa vetores
    for (int i = 0; i < N; i++) {
        h_A[i] = i * 1.0f;
        h_B[i] = (N - i) * 1.0f;
    }

    // ----------------------------------------------------
    // Medir tempo na CPU
    // ----------------------------------------------------
    auto start_cpu = std::chrono::high_resolution_clock::now();
    vectorAddCPU(h_A, h_B, h_C_cpu, N);
    auto end_cpu = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float, std::milli> cpu_time = end_cpu - start_cpu;

    // ----------------------------------------------------
    // Medir tempo na GPU
    // ----------------------------------------------------
    float *d_A, *d_B, *d_C;
    cudaMalloc(&d_A, size);
    cudaMalloc(&d_B, size);
    cudaMalloc(&d_C, size);

    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, size, cudaMemcpyHostToDevice);

    // Criação de eventos para medir tempo na GPU
    cudaEvent_t start_gpu, stop_gpu;
    cudaEventCreate(&start_gpu);
    cudaEventCreate(&stop_gpu);

    cudaEventRecord(start_gpu); // início

    int gridSize = (N + BLOCK_SIZE - 1) / BLOCK_SIZE;
    vectorAddGPU<<<gridSize, BLOCK_SIZE>>>(d_A, d_B, d_C, N);
    cudaDeviceSynchronize(); // garante que o kernel terminou

    cudaEventRecord(stop_gpu); // fim
    cudaEventSynchronize(stop_gpu);

    float gpu_time = 0;
    cudaEventElapsedTime(&gpu_time, start_gpu, stop_gpu); // em ms

    // Copia resultado de volta
    cudaMemcpy(h_C_gpu, d_C, size, cudaMemcpyDeviceToHost);


    // ----------------------------------------------------
    // Mostra resultados e tempos
    // ----------------------------------------------------
    std::cout << "Tempo CPU: " << cpu_time.count() << " ms\n";
    std::cout << "Tempo GPU: " << gpu_time << " ms\n";
    std::cout << "Aceleração: " << cpu_time.count() / gpu_time << "x\n";

    // Libera memória
    delete[] h_A; delete[] h_B; delete[] h_C_cpu; delete[] h_C_gpu;
    cudaFree(d_A); cudaFree(d_B); cudaFree(d_C);

    return 0;
}
