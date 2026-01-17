#include <iostream>
#include <cuda_runtime.h>
using namespace std;

__global__ void somaVetores(int *a, int *b, int *c, int n){
    int i = threadIdx.x; //Indice da thread dentro do bloco
    printf("ThreadIdx.x = %d\n", threadIdx.x);
    if( i < n){
        c[i] = a[i] + b[i];
    }
}

int main() {
    const int N = 5;
    int h_a[N] = {1, 2, 3, 4, 5};
    int h_b[N] = {10, 20, 30, 40, 50};
    int h_c[N] = {0, 0, 0, 0, 0};

    int *d_a, *d_b, *d_c;

    //Aloca memória na GPU
    cudaMalloc(&d_a, N *sizeof(int));
    cudaMalloc(&d_b, N *sizeof(int));
    cudaMalloc(&d_c, N *sizeof(int));

    
    
    //Copia dados CPU -> GPU
    cudaMemcpy(d_a, h_a, N * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, N * sizeof(int), cudaMemcpyHostToDevice);
    /*cudaMemcpy(
    void *dst,                 // destino (CPU ou GPU)
    const void *src,           // origem (CPU ou GPU)
    size_t count,              // número de bytes a copiar
    cudaMemcpyKind kind        // direção da cópia
    );*/

    // Executa o kernel
    somaVetores<<<1, N>>>(d_a, d_b, d_c, N);
    cudaDeviceSynchronize();

    // Copia resultado GPU → CPU
    cudaMemcpy(h_c, d_c, N * sizeof(int), cudaMemcpyDeviceToHost);

    // Mostra o resultado
    cout << "Resultado da soma:" << endl;
    for (int i = 0; i < N; i++){
        cout << h_a[i] << " + " << h_b[i] << " = " << h_c[i] << endl;
    }
        
    // Libera memória da GPU
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return 0;
}