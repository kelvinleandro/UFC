#include <iostream>
#include <cuda_runtime.h>
#include <cmath>

// --------------------------------------------------------------------
// Kernel CUDA: processa uma matriz 2D (por exemplo, uma imagem)
// Cada thread processa um elemento (pixel) da matriz
// --------------------------------------------------------------------
__global__ void processMatrix2D(float *matrix, int width, int height)
{
    // Cálculo das coordenadas globais (x, y)
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;

    // Verifica se a thread está dentro da área válida
    if (x < width && y < height)
    {
        // Cálculo do índice linear correspondente
        int idx = y * width + x;

        // Exemplo: aplica uma função matemática sobre (x, y)
        matrix[idx] = sinf(x * 0.1f) * cosf(y * 0.1f);
    }
}

// --------------------------------------------------------------------
// Função principal (host)
// --------------------------------------------------------------------
int main()
{
    // Dimensões da matriz (ex: imagem 512x512)
    const int width = 512;
    const int height = 512;
    const int totalElements = width * height;
    const size_t size = totalElements * sizeof(float);

    std::cout << "Total de pixels (threads): " << totalElements << std::endl;

    // Alocação de memória no host e no device
    float *h_matrix = new float[totalElements];
    float *d_matrix = nullptr;
    cudaMalloc(&d_matrix, size);

    // Definição do grid e do bloco 2D
    dim3 block(16, 16);  // 16x16 threads = 256 threads por bloco
    dim3 grid(32, 32);  // grid 32x32 blocos

    std::cout << "Grid: (" << grid.x << ", " << grid.y << ")  "
              << "Block: (" << block.x << ", " << block.y << ")" << std::endl;

    // Execução do kernel
    processMatrix2D<<<grid, block>>>(d_matrix, width, height);
    cudaDeviceSynchronize();

    // Copia o resultado para o host
    cudaMemcpy(h_matrix, d_matrix, size, cudaMemcpyDeviceToHost);

    // Exibe alguns valores para validação
    std::cout << "\nAlguns valores processados:" << std::endl;
    for (int i = 0; i < 5; i++)
        std::cout << "h_matrix[" << i << "] = " << h_matrix[i] << std::endl;

    // Libera memória
    cudaFree(d_matrix);
    delete[] h_matrix;

    std::cout << "\nProcessamento 2D concluído com sucesso!" << std::endl;
    return 0;
}
