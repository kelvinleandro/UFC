#include <iostream>
#include <fstream>
#include <cuda_runtime.h>

using namespace std;

// =====================================================
// Kernel CUDA — Negativo Parcial (metade esquerda da imagem)
// Usamos grid 2D (x,y), onde cada thread processa UM pixel.
// Só aplicamos o negativo na metade esquerda.
// =====================================================
__global__ void invertHalf(unsigned char *img, int width, int height)
{
    // Calcula coordenadas (x,y) do pixel correspondente a este thread
    int x = blockIdx.x * blockDim.x + threadIdx.x;  // coluna
    int y = blockIdx.y * blockDim.y + threadIdx.y;  // linha

    // Condição para processar somente a metade ESQUERDA da imagem:
    //
    // x < width/2  → processa só colunas da metade esquerda
    // y < height   → garante que não passamos do limite vertical
    if (x < width / 2 && y < height)
    {
        // Cada pixel tem 3 bytes (R,G,B)
        // Fórmula para converter (x,y) em índice linear:
        // idx = (linha * largura + coluna) * 3
        int idx = (y * width + x) * 3;

        // Aplica negativo RGB:
        // novo = 255 - original
        img[idx]     = 255 - img[idx];       // R
        img[idx + 1] = 255 - img[idx + 1];   // G
        img[idx + 2] = 255 - img[idx + 2];   // B
    }
}

// =====================================================
// Função para carregar imagem PPM (formato P6 - BINÁRIO)
// =====================================================
bool loadPPM(const char *filename, unsigned char **data, int &width, int &height)
{
    ifstream file(filename, ios::binary);  // abre em modo binário
    if (!file)
    {
        cerr << "Erro ao abrir arquivo " << filename << endl;
        return false;
    }

    string header;
    file >> header;  // deve ler "P6"
    if (header != "P6")
    {
        cerr << "Formato PPM inválido\n";
        return false;
    }

    // Lê largura e altura
    file >> width >> height;

    int maxval;
    file >> maxval;   // geralmente 255
    file.ignore(1);   // ignora o '\n'

    // Tamanho total da imagem (3 bytes por pixel)
    int size = width * height * 3;

    // Aloca vetor da imagem no host (CPU)
    *data = new unsigned char[size];

    // Lê bytes RGB diretamente do arquivo
    file.read(reinterpret_cast<char *>(*data), size);

    file.close();
    return true;
}

// =====================================================
// Função para salvar imagem PPM (formato P6 - BINÁRIO)
// =====================================================
void savePPM(const char *filename, unsigned char *data, int width, int height)
{
    ofstream file(filename, ios::binary);

    // Cabeçalho padrão do PPM P6
    file << "P6\n"
         << width << " " << height << "\n255\n";

    // Escreve todos os bytes RGB na ordem natural
    file.write(reinterpret_cast<char *>(data), width * height * 3);

    file.close();
}

// =====================================================
// Programa principal
// =====================================================
int main(int argc, char *argv[])
{
    unsigned char *h_img;  // ponteiro para imagem no host
    int width, height;

    // Verifica se o usuário passou o nome da imagem
    if (argc < 2) {
        cout << "Uso: " << argv[0] << " <input_image.ppm>" << endl;
        return -1;
    }
    
    // Carrega imagem PPM no host
    if (!loadPPM(argv[1], &h_img, width, height))
        return -1;

    // Tamanho total da imagem em bytes
    int img_size = width * height * 3;

    unsigned char *d_img;

    // Aloca memória para imagem na GPU
    cudaMalloc(&d_img, img_size);

    // Copia imagem CPU → GPU
    cudaMemcpy(d_img, h_img, img_size, cudaMemcpyHostToDevice);

    // -----------------------------------------------------------
    // Configuração do GRID 2D
    // Cada bloco tem 16x16 threads (256 threads)
    // Grid suficiente para cobrir toda a imagem
    // -----------------------------------------------------------
    dim3 block(16, 16);
    dim3 grid((width  + 15) / 16,   // ceil(width / 16)
              (height + 15) / 16);  // ceil(height / 16)
    
    // Chamada do kernel
    invertHalf<<<grid, block>>>(d_img, width, height);

    // Aguarda GPU terminar
    cudaDeviceSynchronize();

    // Copia imagem processada GPU → CPU
    cudaMemcpy(h_img, d_img, img_size, cudaMemcpyDeviceToHost);

    // Salva imagem final
    savePPM("output.ppm", h_img, width, height);

    cout << "Imagem processada e salva como output.ppm" << endl;

    // Libera memória GPU e CPU
    cudaFree(d_img);
    delete[] h_img;

    return 0;
}
