#include <iostream>
#include <cmath>
#include <cuda_runtime.h>

// --------------------------------------------------------------------
// Kernel CUDA para processar um volume 3D
// Cada thread processa 1 voxel do volume
// --------------------------------------------------------------------
__global__ void processVolume(float *volume, int width, int height, int depth)
{
    // Cálculo das coordenadas globais (x, y, z)
    int x = blockIdx.x * blockDim.x + threadIdx.x;
    int y = blockIdx.y * blockDim.y + threadIdx.y;
    int z = blockIdx.z * blockDim.z + threadIdx.z;

    // Verifica se a thread está dentro dos limites do volume
    if (x < width && y < height && z < depth)
    {
        // Cálculo do índice linear correspondente (1D)
        int idx = (z * height * width) + (y * width) + x;

        // Exemplo de processamento — função matemática 3D
        volume[idx] = sinf(x * 0.1f) * cosf(y * 0.1f) * expf(-z / 10.0f);
    }
}

// --------------------------------------------------------------------
// Função principal (host)
// --------------------------------------------------------------------
int main()
{
    // Dimensões do volume (64³ voxels)
    const int width = 64;
    const int height = 64;
    const int depth = 64;
    const int totalVoxels = width * height * depth;
    const size_t volumeSize = totalVoxels * sizeof(float);

    std::cout << "Total de voxels (threads): " << totalVoxels << std::endl;

    // Ponteiros para o volume no host e device
    float *h_volume = new float[totalVoxels];
    float *d_volume = nullptr;

    // Aloca memória na GPU
    cudaMalloc((void**)&d_volume, volumeSize);

    // Define as dimensões do grid e do bloco
    dim3 block(8, 8, 8);  // 512 threads por bloco
    dim3 grid(8, 8, 8);   // 512 blocos → 262.144 threads no total

    std::cout << "Lançando kernel com grid(" << grid.x << "," << grid.y << "," << grid.z
              << ") e block(" << block.x << "," << block.y << "," << block.z << ")" << std::endl;

    // Executa o kernel na GPU
    processVolume<<<grid, block>>>(d_volume, width, height, depth);

    // Sincroniza execução e checa erros
    cudaDeviceSynchronize();

    // Copia resultados de volta para o host
    cudaMemcpy(h_volume, d_volume, volumeSize, cudaMemcpyDeviceToHost);

    // Exibe alguns valores para verificação
    std::cout << "\nAlguns valores processados:" << std::endl;
    for (int i = 0; i < 5; ++i)
        std::cout << "h_volume[" << i << "] = " << h_volume[i] << std::endl;

    // Libera memória
    cudaFree(d_volume);
    delete[] h_volume;

    std::cout << "\nProcessamento concluído com sucesso!" << std::endl;
    return 0;
}
