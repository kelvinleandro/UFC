#include <iostream>
#include <cuda_runtime.h>
using namespace std;

// ------------------------------------------------------
// Kernel: executado na GPU
// Cada thread soma UM elemento das matrizes A e B
// ------------------------------------------------------
__global__ void somaMatrizes(int *A, int *B, int *C, int N) {
    int row = threadIdx.y;  // linha atual
    int col = threadIdx.x;  // coluna atual

    // Cálculo do índice linear dentro do vetor 1D
    int index = row * N + col;
    printf("L = %d, C = %d, I = %d\n", threadIdx.y, threadIdx.x, index);

    // Soma elemento a elemento
    C[index] = A[index] + B[index];
}

int main() {
    // Tamanho da matriz (3x3)
    const int N = 3;
    const int SIZE = N * N * sizeof(int);

    // Matrizes na CPU (host)
    int h_A[N*N] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};

    int h_B[N*N] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};

    int h_C[N*N] = {0}; // Resultado

    // Matrizes na GPU (device)
    int *d_A, *d_B, *d_C;

    // ------------------------------------------------------
    // 1. Alocar memória na GPU
    // ------------------------------------------------------
    cudaMalloc(&d_A, SIZE);
    cudaMalloc(&d_B, SIZE);
    cudaMalloc(&d_C, SIZE);


    // ------------------------------------------------------
    // 2. Copiar dados CPU → GPU
    // ------------------------------------------------------
    cudaMemcpy(d_A, h_A, SIZE, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, SIZE, cudaMemcpyHostToDevice);

    // ------------------------------------------------------
    // 3. Configuração da execução do kernel
    // ------------------------------------------------------
    dim3 threadsPerBlock(N, N);  // Como a matriz é 3x3, teremos um bloco de 3x3 threads
    dim3 numBlocks(1, 1); // apenas um bloco é suficiente

    // ------------------------------------------------------
    // 4. Executar o kernel na GPU
    // ------------------------------------------------------
    somaMatrizes<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_C, N);

    // Espera o kernel terminar
    cudaDeviceSynchronize();

    // ------------------------------------------------------
    // 5. Copiar resultado GPU → CPU
    // ------------------------------------------------------
    cudaMemcpy(h_C, d_C, SIZE, cudaMemcpyDeviceToHost);

    // ------------------------------------------------------
    // 6. Mostrar o resultado
    // ------------------------------------------------------
    cout << "Resultado da soma de matrizes A + B:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << h_C[i * N + j] << "\t";
        }
        cout << "\n";
    }
}