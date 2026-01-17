#include <iostream>
#include <cuda_runtime.h>
using namespace std;

// ----------------------------
// Kernel que roda na GPU
// ----------------------------
__global__ void multiplicaMatrix(int *A, int *B, int *C, int N) {
    // Cada thread calcula UM elemento da matriz C
    int row = threadIdx.y;  // linha atual
    int col = threadIdx.x;  // coluna atual

    int sum = 0;

    // Multiplica linha de A pela coluna de B
    for (int k = 0; k < N; k++) {
        sum += A[row * N + k] * B[k * N + col];
    }

    // Escreve o resultado na posição correspondente
    C[row * N + col] = sum;
}

int main() {
    // Tamanho da matriz (3x3)
    const int N = 3;
    const int SIZE = N * N * sizeof(int);

    // Matrizes da CPU (host)
    int h_A[N*N] = {1, 2, 3,
                    4, 5, 6,
                    7, 8, 9};

    int h_B[N*N] = {9, 8, 7,
                    6, 5, 4,
                    3, 2, 1};

    int h_C[N*N]; // Resultado

    // Matrizes na GPU (device)
    int *d_A, *d_B, *d_C;

    // ----------------------------
    // 1. Alocar memória na GPU
    // ----------------------------
    cudaMalloc((void**)&d_A, SIZE);
    cudaMalloc((void**)&d_B, SIZE);
    cudaMalloc((void**)&d_C, SIZE);

    // ----------------------------
    // 2. Copiar dados CPU → GPU
    // ----------------------------
    cudaMemcpy(d_A, h_A, SIZE, cudaMemcpyHostToDevice);
    cudaMemcpy(d_B, h_B, SIZE, cudaMemcpyHostToDevice);

    // ----------------------------
    // 3. Definir configuração de execução
    // ----------------------------
    // Queremos uma thread por elemento de saída.
    // Como a matriz é 3x3, usamos um bloco 3x3.
    dim3 threadsPerBlock(N, N);  // 3 threads em X e 3 em Y
    dim3 numBlocks(1, 1);        // apenas um bloco

    // ----------------------------
    // 4. Executar o kernel na GPU
    // ----------------------------
    multiplicaMatrix<<<numBlocks, threadsPerBlock>>>(d_A, d_B, d_C, N);

    // Espera a GPU terminar
    cudaDeviceSynchronize();

    // ----------------------------
    // 5. Copiar resultado GPU → CPU
    // ----------------------------
    cudaMemcpy(h_C, d_C, SIZE, cudaMemcpyDeviceToHost);

    // ----------------------------
    // 6. Mostrar o resultado
    // ----------------------------
    cout << "Resultado da multiplicação A x B:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << h_C[i * N + j] << "\t";
        }
        std::cout << "\n";
    }

    // ----------------------------
    // 7. Liberar memória
    // ----------------------------
    cudaFree(d_A);
    cudaFree(d_B);
    cudaFree(d_C);

    return 0;
}
