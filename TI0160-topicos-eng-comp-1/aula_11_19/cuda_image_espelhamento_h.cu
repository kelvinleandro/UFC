#include <iostream>
#include <fstream>
#include <cuda_runtime.h>

using namespace std;

// =====================================================
// Kernel CUDA — Espelhamento Horizontal usando grid 2D
// Cada thread cuida de UM pixel (x,y)
// =====================================================
__global__ void flipHorizontal(unsigned char *img, int width, int height)
{
    // Calcula coordenadas absolutas do thread na imagem
    int x = blockIdx.x * blockDim.x + threadIdx.x;  // coluna do pixel
    int y = blockIdx.y * blockDim.y + threadIdx.y;  // linha do pixel

    // Garantimos que estamos dentro da imagem,
    // e que só a metade ESQUERDA executa a troca,
    // para evitar trocar o pixel duas vezes.
    if (x < width / 2 && y < height)
    {
        // Cada pixel possui 3 bytes (RGB)
        // Fórmula para converter (x,y) em índice linear:
        // idx = (linha * largura + coluna) * 3
        int idx1 = (y * width + x) * 3;                     // pixel do lado esquerdo
        int idx2 = (y * width + (width - 1 - x)) * 3;       // pixel correspondente no lado direito

        // Troca os 3 canais (R, G, B) dos dois pixels
        for (int c = 0; c < 3; c++)
        {
            unsigned char temp = img[idx1 + c];
            img[idx1 + c] = img[idx2 + c];
            img[idx2 + c] = temp;
        }
    }
}

// =====================================================
// Função para carregar imagem PPM (formato P6 - binário)
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
    file >> header; // deve ler "P6"
    if (header != "P6")
    {
        cerr << "Formato PPM inválido\n";
        return false;
    }

    // Lê largura e altura da imagem
    file >> width >> height;

    int maxval;
    file >> maxval;   // geralmente 255
    file.ignore(1);   // descarta o '\n' após maxval

    // Calcula tamanho da imagem em bytes (RGB = 3 bytes por pixel)
    int size = width * height * 3;

    // Aloca imagem no host
    *data = new unsigned char[size];

    // Lê todos os bytes RGB diretamente
    file.read(reinterpret_cast<char *>(*data), size);

    file.close();
    return true;
}

// =====================================================
// Função para salvar imagem PPM (formato P6 - binário)
// =====================================================
void savePPM(const char *filename, unsigned char *data, int width, int height)
{
    ofstream file(filename, ios::binary);  // modo binário

    // Cabeçalho PPM P6
    file << "P6\n"
         << width << " " << height << "\n255\n";

    // Escreve os bytes RGB
    file.write(reinterpret_cast<char *>(data), width * height * 3);

    file.close();
}

// =====================================================
// Programa principal
// =====================================================
int main(int argc, char *argv[])
{
    unsigned char *h_img;  // imagem no host (CPU)
    int width, height;

    // Verifica se o usuário passou o nome da imagem
    if (argc < 2)
    {
        cout << "Uso: " << argv[0] << " <input_image.ppm>" << endl;
        return -1;
    }

    // Carrega a imagem para a memória da CPU
    if (!loadPPM(argv[1], &h_img, width, height))
        return -1;

    // Tamanho total da imagem (em bytes)
    int img_size = width * height * 3;

    unsigned char *d_img;  // ponteiro para GPU

    // Aloca imagem na GPU
    cudaMalloc(&d_img, img_size);

    // Copia imagem da CPU para a GPU
    cudaMemcpy(d_img, h_img, img_size, cudaMemcpyHostToDevice);

    // --------------------------------------------------
    // Configuração do grid 2D
    // Cada bloco tem 16×16 threads
    // O grid é dimensionado para cobrir a imagem inteira
    // --------------------------------------------------
    dim3 block(16, 16);
    dim3 grid((width  + block.x - 1) / block.x,
              (height + block.y - 1) / block.y);

    // Executa o kernel na GPU
    flipHorizontal<<<grid, block>>>(d_img, width, height);

    // Espera GPU terminar
    cudaDeviceSynchronize();

    // Copia imagem modificada de volta para o host
    cudaMemcpy(h_img, d_img, img_size, cudaMemcpyDeviceToHost);

    // Salva imagem final
    savePPM("output.ppm", h_img, width, height);

    cout << "Imagem espelhada salva como output_flip.ppm" << endl;

    // Libera memória
    cudaFree(d_img);
    delete[] h_img;

    return 0;
}
