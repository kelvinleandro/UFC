#include <iostream>
#include <opencv2/opencv.hpp>
#include <cuda_runtime.h>

using namespace std;

// =====================================================
// KERNEL CUDA — Espelhamento Horizontal (flip)
// Cada thread processa UM pixel (x,y)
// =====================================================
__global__ void flipHorizontalKernel(uchar3 *img, int width, int height)
{
    // Calcula posição 2D do pixel
    int x = blockIdx.x * blockDim.x + threadIdx.x;  // coluna (0..width-1)
    int y = blockIdx.y * blockDim.y + threadIdx.y;  // linha  (0..height-1)

    // Apenas processa se estiver dentro da metade esquerda
    if (x < width / 2 && y < height)
    {
        // Índice linear no vetor de uchar3
        int idx1 = y * width + x;                   // pixel na esquerda
        int idx2 = y * width + (width - 1 - x);     // pixel espelhado à direita

        // Troca os dois pixels
        uchar3 temp = img[idx1];
        img[idx1] = img[idx2];
        img[idx2] = temp;
    }
}

// =====================================================
// PROGRAMA PRINCIPAL — OpenCV + CUDA com kernel próprio
// =====================================================
int main(int argc, char** argv)
{
    if (argc < 2)
    {
        cout << "Uso: " << argv[0] << " <imagem.jpg/png/bmp>" << endl;
        return -1;
    }

    // --------------------------------------------------
    // 1) Carrega imagem usando OpenCV (qualquer formato)
    // --------------------------------------------------
    cv::Mat img = cv::imread(argv[1]);
    if (img.empty())
    {
        cout << "Erro ao carregar imagem!" << endl;
        return -1;
    }

    int width  = img.cols;
    int height = img.rows;

    cout << "Imagem carregada (" << width << " x " << height << ")" << endl;

    // Converte BGR → RGB (CUDA usa normalmente RGB)
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    // --------------------------------------------------
    // 2) Converte cv::Mat para uchar3* contíguo
    // --------------------------------------------------
    uchar3* h_img = reinterpret_cast<uchar3*>(img.data);

    // --------------------------------------------------
    // 3) Aloca imagem na GPU
    // --------------------------------------------------
    uchar3 *d_img;
    cudaMalloc(&d_img, width * height * sizeof(uchar3));

    // CPU → GPU
    cudaMemcpy(d_img, h_img, width * height * sizeof(uchar3),
               cudaMemcpyHostToDevice);

    // --------------------------------------------------
    // 4) Configuração do GRID e BLOCO (2D)
    // --------------------------------------------------
    dim3 block(16, 16);
    dim3 grid((width  + block.x - 1) / block.x,
              (height + block.y - 1) / block.y);

    // --------------------------------------------------
    // 5) Executa kernel CUDA
    // --------------------------------------------------
    flipHorizontalKernel<<<grid, block>>>(d_img, width, height);
    cudaDeviceSynchronize();

    // --------------------------------------------------
    // 6) Copia imagem de volta GPU → CPU
    // --------------------------------------------------
    cudaMemcpy(h_img, d_img, width * height * sizeof(uchar3),
               cudaMemcpyDeviceToHost);

    // Converte de volta RGB → BGR para salvar com OpenCV
    cv::cvtColor(img, img, cv::COLOR_RGB2BGR);

    // --------------------------------------------------
    // 7) Salva imagem final
    // --------------------------------------------------
    cv::imwrite("output_flip_cuda.jpg", img);

    cout << "Imagem espelhada salva como output_flip_cuda.jpg" << endl;

    // --------------------------------------------------
    // 8) Libera recursos
    // --------------------------------------------------
    cudaFree(d_img);

    return 0;
}