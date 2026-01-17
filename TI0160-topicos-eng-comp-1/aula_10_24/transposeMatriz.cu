#include <iostream>
#include <cuda_runtime.h>
#include <chrono>
using namespace std;

#define N 8  // matriz 32x32 → 1024 threads (limite de 1 bloco)

// ----------------------------------------------------
// Kernel sem grid: um único bloco de N×N threads
// ----------------------------------------------------
__global__ void transposeGPU(int *A, int *B, int n) {
    //TO DO
}

// ----------------------------------------------------
// Transposição na CPU
// ----------------------------------------------------
void transposeCPU(int *A, int *B, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            B[j * n + i] = A[i * n + j];
}

int main() {
    const int SIZE = N * N;

    int *h_A = new int[SIZE];
    int *h_B = new int[SIZE];

    // Inicializa matriz
    for (int i = 0; i < SIZE; i++)
        h_A[i] = static_cast<float>(i);

    // CPU - Medir o tempo
    // TO DO
    transposeCPU(h_A, h_B, N);

    // Print resultado da CPU
    cout << "\nMatriz original A:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << h_A[i * N + j] << "\t";
        cout << "\n";
    }
    cout << "\nTransposta B:\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << h_B[i * N + j] << "\t";
        cout << "\n";
    }
    
    // GPU - Medir o tempo
    // TO DO


    //Libera memória new int
    delete[] h_A;
    delete[] h_B;
}
