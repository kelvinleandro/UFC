#include <iostream>
#include <fstream>
#include <cuda_runtime.h>

using namespace std;

// =====================================================
// Kernel CUDA — inverte as cores da imagem
// Cada thread trata UM byte (um canal de cor)
// =====================================================
__global__ void invertColors(unsigned char *img, int size)
{
    // Calcula o índice global do thread:
    // blockIdx.x   -> qual bloco (em 1D)
    // blockDim.x   -> quantos threads por bloco
    // threadIdx.x  -> índice do thread dentro do bloco
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Garante que não passamos do fim do vetor de bytes
    if (i < size)
        // img[i] é um canal R, G ou B (0..255)
        // Negativo de cor: 255 - valor
        img[i] = 255 - img[i];
}

// =====================================================
// Função para carregar imagem PPM (formato P6, binário)
// Lê o cabeçalho (P6, largura, altura, maxval)
// e depois aloca e lê todos os bytes RGB da imagem.
// =====================================================
bool loadPPM(const char *filename, unsigned char **data, int &width, int &height)
{
    ifstream file(filename, ios::binary);  // abre arquivo em modo binário
    if (!file)
    {
        cerr << "Erro ao abrir arquivo " << filename << endl;
        return false;
    }

    string header;
    file >> header; // lê a "magic word", deve ser "P6"
    if (header != "P6")
    {
        cerr << "Formato PPM inválido\n";
        return false;
    }

    // Lê largura e altura da imagem
    file >> width >> height;

    int maxval;
    file >> maxval;   // normalmente 255
    file.ignore(1);   // ignora o '\n' após o maxval para posicionar no início dos dados binários

    // Cada pixel tem 3 canais: R, G e B
    int size = width * height * 3;

    // Aloca memória no host para armazenar a imagem inteira
    *data = new unsigned char[size];

    // Lê os 'size' bytes de uma vez só
    file.read(reinterpret_cast<char *>(*data), size);

    file.close();
    return true;
}

// =====================================================
// Função para salvar imagem PPM (formato P6, binário)
// Escreve o cabeçalho e depois o buffer RGB na ordem correta.
// =====================================================
void savePPM(const char *filename, unsigned char *data, int width, int height)
{
    ofstream file(filename, ios::binary);  // abre em modo binário

    // Cabeçalho P6:
    // P6
    // <largura> <altura>
    // 255
    file << "P6\n"
         << width << " " << height << "\n255\n";

    // Escreve todos os bytes (R,G,B,R,G,B,...)
    file.write(reinterpret_cast<char *>(data), width * height * 3);

    file.close();
}

// =====================================================
// Programa principal
// =====================================================
int main(int argc, char *argv[])
{
    unsigned char *h_img;  // ponteiro para imagem no host (CPU)
    int width, height;

    // Verifica se o usuário passou o caminho da imagem
    if(argc < 2) {
        cout << "Uso: " << argv[0] << " <path para input_image.ppm>" << endl;
        return -1;
    }
    
    // Carrega a imagem PPM para a memória da CPU
    // h_img: vai apontar para o buffer RGB
    // width, height: preenchidos pela função
    if (!loadPPM(argv[1], &h_img, width, height))
        return -1;

    // Tamanho total do buffer em bytes:
    // número de pixels (width * height) * 3 canais
    int img_size = width * height * 3;

    // Ponteiro da imagem na GPU (device)
    unsigned char *d_img;

    // Aloca memória na GPU para a imagem
    cudaMalloc(&d_img, img_size);

    // Copia imagem da CPU (h_img) para GPU (d_img)
    cudaMemcpy(d_img, h_img, img_size, cudaMemcpyHostToDevice);

    // Configuração do kernel:
    // - Usamos 256 threads por bloco
    // - Calculamos quantos blocos são necessários para cobrir img_size elementos
    int threads = 256;
    int blocks = (img_size + threads - 1) / threads;
    // Ex.: se img_size = 1000:
    // blocks = (1000 + 255) / 256 = 1255 / 256 = 4 blocos

    // Chamada do kernel:
    // Cada thread vai inverter UM byte (um canal R, G ou B)
    invertColors<<<blocks, threads>>>(d_img, img_size);

    // Garante que a GPU terminou antes de continuar
    cudaDeviceSynchronize();

    // Copia a imagem modificada de volta para o host
    cudaMemcpy(h_img, d_img, img_size, cudaMemcpyDeviceToHost);

    // Salva a imagem resultante em disco
    savePPM("output.ppm", h_img, width, height);

    cout << "Imagem processada e salva como output.ppm" << endl;

    // Libera memória na GPU
    cudaFree(d_img);

    // Libera memória no host
    delete[] h_img;

    return 0;
}
