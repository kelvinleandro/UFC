// Exemplo 1 — Soma de Vetores (Threads 1D)
// exemplo1_soma_vetores.cu
#include <iostream>         // Biblioteca padrão de C++ para entrada/saída
#include <cuda_runtime.h>   // Cabeçalho principal da API CUDA Runtime

// ============================================================================
// Kernel CUDA: é a função que roda na GPU
// ============================================================================

// __global__ indica que essa função será executada na GPU (disparada pela CPU)
__global__ void somaVetores(const int *A, const int *B, int *C, int n) {
    // Calcula o índice global da thread:
    // blockIdx.x → índice do bloco atual
    // blockDim.x → número de threads por bloco
    // threadIdx.x → índice da thread dentro do bloco
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Garante que o índice não ultrapasse o tamanho do vetor
    if (i < n)
        // Cada thread soma um elemento correspondente de A e B
        C[i] = A[i] + B[i];
}

// ============================================================================
// Função principal (executa na CPU, dispara o kernel na GPU)
// ============================================================================
int main() {
    int n = 16;                      // Tamanho do vetor
    size_t bytes = n * sizeof(int); // Número total de bytes (4 bytes por float)

    // Aloca memória no host (CPU)
    int *hA = new int[n];
    int *hB = new int[n];
    int *hC = new int[n];

    // Inicializa vetores A e B com valores simples
    for (int i = 0; i < n; i++) {
        hA[i] = i;       // Exemplo: 0, 1, 2, ...
        hB[i] = i * 2;   // Exemplo: 0, 2, 4, ...
    }

    // Ponteiros para memória da GPU (device)
    int *dA, *dB, *dC;

    // Aloca memória na GPU
    cudaMalloc(&dA, bytes);
    cudaMalloc(&dB, bytes);
    cudaMalloc(&dC, bytes);

    // Copia dados da CPU → GPU
    cudaMemcpy(dA, hA, bytes, cudaMemcpyHostToDevice);
    cudaMemcpy(dB, hB, bytes, cudaMemcpyHostToDevice);

    // Define o número de threads por bloco
    int threads = 8;

    // Calcula o número de blocos necessários para processar todos os elementos
    // Exemplo: se n=16 e threads=8 → blocks=2
    int blocks = (n + threads - 1) / threads;

    // ========================================================================
    // Execução do kernel na GPU
    // <<<blocks, threads>>> define a grade de execução
    // ========================================================================
    somaVetores<<<blocks, threads>>>(dA, dB, dC, n);

    // Garante que todas as threads terminaram
    cudaDeviceSynchronize();

    // Copia o resultado da GPU → CPU
    cudaMemcpy(hC, dC, bytes, cudaMemcpyDeviceToHost);

    // Exibe o resultado
    std::cout << "Resultado da soma de vetores:\n";
    for (int i = 0; i < n; i++)
        std::cout << "C[" << i << "] = " << hC[i] << "\n";

    // Libera a memória alocada na GPU
    cudaFree(dA);
    cudaFree(dB);
    cudaFree(dC);

    // Libera memória no host
    delete[] hA;
    delete[] hB;
    delete[] hC;
}
