// ============================================================================
// exemplo2a_inverter_imagem_gray.cu
// Exemplo simples de uso de threads 2D em CUDA para processar uma imagem
// em tons de cinza (1 byte por pixel).
// Cada thread processa 1 pixel (x, y) e inverte o valor: pixel = 255 - pixel.
// ============================================================================
#include <iostream>
#include <cuda_runtime.h>

// ============================================================================
// Kernel CUDA — executado na GPU
// ============================================================================
__global__ void inverterImagem(unsigned char *img, int width, int height) {
    // Cálculo das coordenadas (x, y) globais da thread
    int x = blockIdx.x * blockDim.x + threadIdx.x;  // coluna
    int y = blockIdx.y * blockDim.y + threadIdx.y;  // linha


    // Verificação de limites — evita que threads fora da imagem acessem memória inválida
    if (x < width && y < height) {
        // Cálculo do índice linear (imagem armazenada em vetor 1D)
        int idx = y * width + x;

        // Inversão simples: pixel = 255 - pixel
        img[idx] = 255 - img[idx];
    }
}

// ============================================================================
// Função principal — executada na CPU
// ============================================================================
int main() {
    // -------------------------------
    // 1. Definir tamanho da imagem
    // -------------------------------
    int width = 8;      // número de colunas
    int height = 8;     // número de linhas
    int size = width * height;  // total de pixels

    // -------------------------------
    // 2. Alocar imagem no host (CPU)
    // -------------------------------
    unsigned char *h_img = new unsigned char[size];

    // Criar imagem sintética: valores crescentes (0, 1, 2, ...)
    for (int i = 0; i < size; i++) {
        h_img[i] = i * 4;  // 0, 4, 8, 12... até 255
    }

    // -------------------------------
    // 3. Alocar imagem no device (GPU)
    // -------------------------------
    unsigned char *d_img;
    cudaMalloc(&d_img, size);  // alocar na GPU
    cudaMemcpy(d_img, h_img, size, cudaMemcpyHostToDevice);  // copiar CPU → GPU

    // -------------------------------
    // 4. Definir grade e blocos
    // -------------------------------
    // Bloco com 4x4 threads
    dim3 block(4, 4);
    // Grade calculada para cobrir toda a imagem
    dim3 grid(
        (width  + block.x - 1) / block.x,
        (height + block.y - 1) / block.y
    );

    // -------------------------------
    // 5. Executar kernel na GPU
    // -------------------------------
    inverterImagem<<<grid, block>>>(d_img, width, height);
    cudaDeviceSynchronize();  // aguarda GPU terminar

    // -------------------------------
    // 6. Copiar imagem processada de volta (GPU → CPU)
    // -------------------------------
    cudaMemcpy(h_img, d_img, size, cudaMemcpyDeviceToHost);

    // -------------------------------
    // 7. Mostrar resultado
    // -------------------------------
    std::cout << "Imagem invertida (tons de cinza):\n";
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int idx = y * width + x;
            std::cout << (int)h_img[idx] << "\t";
        }
        std::cout << "\n";
    }

    // -------------------------------
    // 8. Liberar memória
    // -------------------------------
    cudaFree(d_img);
    delete[] h_img;
}
