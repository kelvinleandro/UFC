#include <iostream>
#include <fstream>
#include <cuda_runtime.h>

using namespace std;

// =====================================================
// Kernel CUDA — Mistura (blend) de duas imagens
// Cada thread mistura UM byte (um canal R, G ou B)
// =====================================================
__global__ void blendImages(unsigned char *imgA, unsigned char *imgB,
                            unsigned char *imgOut, int size, float alpha)
{
    // Índice global do thread
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Apenas processa se estiver dentro da imagem
    if (i < size)
    {
        // Mistura linear:
        // alpha = peso da imagem A
        // (1 - alpha) = peso da imagem B
        imgOut[i] = alpha * imgA[i] + (1.0f - alpha) * imgB[i];
    }
}

// =====================================================
// Função para carregar imagem PPM (formato P6 - binário)
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
    file >> header;  // deve ler "P6"
    if (header != "P6")
    {
        cerr << "Formato PPM inválido\n";
        return false;
    }

    // Lê largura e altura
    file >> width >> height;

    int maxval;
    file >> maxval;     // geralmente 255
    file.ignore(1);     // ignora o '\n' após maxval

    // Número total de bytes da imagem RGB
    int size = width * height * 3;

    // Aloca vetor no host
    *data = new unsigned char[size];

    // Lê bytes RGB direto para o vetor (binário)
    file.read(reinterpret_cast<char *>(*data), size);

    file.close();
    return true;
}

// =====================================================
// Função para salvar imagem PPM (formato P6 - binário)
// =====================================================
void savePPM(const char *filename, unsigned char *data, int width, int height)
{
    ofstream file(filename, ios::binary);

    // Cabeçalho do PPM P6
    file << "P6\n"
         << width << " " << height << "\n255\n";

    // Escreve todos os bytes RGB
    file.write(reinterpret_cast<char *>(data), width * height * 3);

    file.close();
}

// =====================================================
// Programa principal
// =====================================================
int main(int argc, char *argv[])
{
    unsigned char *h_imgA, *h_imgB;   // imagens na CPU
    int widthA, heightA, widthB, heightB;

    // Espera dois nomes de arquivo
    if (argc < 3)
    {
        cout << "Uso: " << argv[0] << " <imagem1.ppm> <imagem2.ppm>" << endl;
        return -1;
    }

    // Carrega imagem A
    if (!loadPPM(argv[1], &h_imgA, widthA, heightA))
        return -1;

    // Carrega imagem B
    if (!loadPPM(argv[2], &h_imgB, widthB, heightB))
        return -1;

    // Verifica se possuem mesmo tamanho
    if (widthA != widthB || heightA != heightB)
    {
        cout << "As imagens devem ter o mesmo tamanho!" << endl;
        delete[] h_imgA;
        delete[] h_imgB;
        return -1;
    }

    int width = widthA;
    int height = heightA;
    int img_size = width * height * 3;   // bytes totais (RGB)

    // Ponteiros da GPU
    unsigned char *d_imgA, *d_imgB, *d_imgOut;

    // Aloca memória na GPU
    cudaMalloc(&d_imgA, img_size);
    cudaMalloc(&d_imgB, img_size);
    cudaMalloc(&d_imgOut, img_size);

    // Copia imagens da CPU → GPU
    cudaMemcpy(d_imgA, h_imgA, img_size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_imgB, h_imgB, img_size, cudaMemcpyHostToDevice);

    // ==========================================================
    // Configuração do kernel:
    // - cada thread trata 1 byte (um canal R, G ou B)
    // - 256 threads por bloco
    // - quantidade de blocos suficiente para percorrer todos bytes
    // ==========================================================
    int threads = 256;
    int blocks = (img_size + threads - 1) / threads;

    // Peso da mistura: 0.5 = 50% de cada imagem
    float alpha = 0.5f;

    // Execução do kernel de mistura
    blendImages<<<blocks, threads>>>(d_imgA, d_imgB, d_imgOut, img_size, alpha);
    cudaDeviceSynchronize();

    // Aloca imagem final no host
    unsigned char *h_imgOut = new unsigned char[img_size];

    // Copia resultado GPU → CPU
    cudaMemcpy(h_imgOut, d_imgOut, img_size, cudaMemcpyDeviceToHost);

    // Salva resultado
    savePPM("output_blend.ppm", h_imgOut, width, height);

    cout << "Imagem mesclada salva como output_blend.ppm" << endl;

    // Libera memória GPU
    cudaFree(d_imgA);
    cudaFree(d_imgB);
    cudaFree(d_imgOut);

    // Libera memória CPU
    delete[] h_imgA;
    delete[] h_imgB;
    delete[] h_imgOut;

    return 0;
}
