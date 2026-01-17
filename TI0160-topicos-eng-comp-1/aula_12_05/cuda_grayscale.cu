#include <iostream>
#include <opencv2/opencv.hpp>
#include <cuda_runtime.h>

using namespace std;

// ====================================================================
// KERNEL CUDA — Conversão RGB → Grayscale
//
// Executa na GPU. Cada thread converte **1 pixel** da imagem.
//
// Fórmula de luminância (percepção humana):
//   Y = 0.299R + 0.587G + 0.114B
//
// uchar3 = estrutura CUDA com 3 bytes: x = R, y = G, z = B
// ====================================================================
__global__ void rgbToGrayKernel(uchar3 *input, unsigned char *output,
                                int width, int height)
{
    // ---------------------------------------------------------------
    // Cálculo das coordenadas (x, y) do pixel que esta thread irá processar
    //
    // blockIdx.x   = índice do bloco na direção X
    // blockDim.x   = número de threads por bloco em X
    // threadIdx.x  = índice da thread dentro do bloco
    //
    // Fórmula final:
    //     pixel_x = bloco_x * threads_por_bloco + thread_x
    // ---------------------------------------------------------------
    int x = blockIdx.x * blockDim.x + threadIdx.x;  // coluna
    int y = blockIdx.y * blockDim.y + threadIdx.y;  // linha

    // Garantia de que não acessaremos memória fora da imagem
    if (x >= width || y >= height)
        return;

    // índice linear no vetor da imagem
    int idx = y * width + x;

    // Lê o pixel RGB da GPU
    uchar3 pixel = input[idx];

    // ---------------------------------------------------------------
    // Conversão RGB → Gray
    //
    // Importante: multiplicadores em float, output em uchar.
    //---------------------------------------------------------------
    unsigned char gray =
        0.299f * pixel.x +   // R
        0.587f * pixel.y +   // G
        0.114f * pixel.z;    // B

    // Escreve o pixel convertido no buffer de saída
    output[idx] = gray;
}

// ====================================================================
// PROGRAMA PRINCIPAL
// ====================================================================
int main(int argc, char **argv)
{
    // ---------------------------------------------------------------
    // Verifica se o nome da imagem foi passado como argumento
    // ---------------------------------------------------------------
    if (argc < 2)
    {
        cout << "Uso: " << argv[0] << " <imagem.jpg/png/bmp>" << endl;
        return -1;
    }

    // ---------------------------------------------------------------
    // 1) Carrega imagem usando OpenCV (na CPU)
    // ---------------------------------------------------------------
    cv::Mat img = cv::imread(argv[1]);

    if (img.empty())
    {
        cout << "Erro ao carregar imagem!" << endl;
        return -1;
    }

    // OpenCV lê em BGR — nós convertemos para RGB porque o kernel usa RGB
    cv::cvtColor(img, img, cv::COLOR_BGR2RGB);

    int width = img.cols;
    int height = img.rows;

    cout << "Imagem carregada (" << width << " x " << height << ")" << endl;

    // ---------------------------------------------------------------
    // 2) Ponteiros no HOST (CPU)
    // ---------------------------------------------------------------
    // uchar3*: cada pixel tem 3 componentes de 1 byte
    uchar3 *h_input = (uchar3*)img.data;

    // Cria matriz para armazenar imagem de saída (1 canal: cinza)
    cv::Mat grayImg(height, width, CV_8UC1);
    unsigned char *h_output = grayImg.data;

    // ---------------------------------------------------------------
    // 3) Aloca memória na GPU (DEVICE)
    // ---------------------------------------------------------------
    uchar3 *d_input;
    unsigned char *d_output;

    // espaço para width * height * sizeof(uchar3)
    cudaMalloc(&d_input,  width * height * sizeof(uchar3));
    cudaMalloc(&d_output, width * height * sizeof(unsigned char));

    // copiar imagem CPU → GPU
    cudaMemcpy(d_input, h_input,
               width * height * sizeof(uchar3),
               cudaMemcpyHostToDevice);

    // ---------------------------------------------------------------
    // 4) Define configuração da GRID e do BLOCO
    // ---------------------------------------------------------------
    // Blocos 16×16 são comuns em processamento de imagem
    dim3 block(16, 16);

    // Cálculo da grid garantindo cobrir a imagem inteira
    dim3 grid((width  + block.x - 1) / block.x,
              (height + block.y - 1) / block.y);

    // ---------------------------------------------------------------
    // 5) Executa o kernel CUDA
    // ---------------------------------------------------------------
    rgbToGrayKernel<<<grid, block>>>(d_input, d_output, width, height);

    // Sincroniza para garantir que terminou
    cudaDeviceSynchronize();

    // ---------------------------------------------------------------
    // 6) Copia resultado GPU → CPU
    // ---------------------------------------------------------------
    cudaMemcpy(h_output, d_output,
               width * height * sizeof(unsigned char),
               cudaMemcpyDeviceToHost);

    // ---------------------------------------------------------------
    // 7) Salva a imagem convertida
    // ---------------------------------------------------------------
    cv::imwrite("output_gray.jpg", grayImg);
    cout << "Imagem cinza salva como output_gray.jpg" << endl;

    // ---------------------------------------------------------------
    // 8) Libera memória da GPU
    // ---------------------------------------------------------------
    cudaFree(d_input);
    cudaFree(d_output);

    return 0;
}
