#include <iostream>
#include <fstream>
#include <cuda_runtime.h>

using namespace std;

// =====================================================
// Kernel CUDA — filtro simples em áudio (média de 2 amostras)
// Cada thread trata UMA amostra (float)
// =====================================================
__global__ void audioFilter(float *samples, float *out, int N)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    if (i < N)
    {
        float acc = 0.0f;
        int count = 0;

        // Soma até 6 amostras (ordem 5)
        for (int k = 0; k < 6; k++)
        {
            int idx = i - k;
            if (idx >= 0)   // evita acessar memória negativa
            {
                acc += samples[idx];
                count++;
            }
        }

        out[i] = acc / count;
    }
}

// =====================================================
// Função para carregar arquivo RAW (float32)
// RAW contém somente floats binários sequenciais
// =====================================================
bool loadRAW(const char *filename, float **data, int &N)
{
    ifstream file(filename, ios::binary);
    if (!file)
    {
        cerr << "Erro ao abrir arquivo " << filename << endl;
        return false;
    }

    // move para o fim e pega tamanho
    file.seekg(0, ios::end);
    size_t fileSize = file.tellg();
    file.seekg(0, ios::beg);

    // número de amostras
    N = fileSize / sizeof(float);

    // aloca memória no host
    *data = new float[N];

    // lê todas as amostras
    file.read(reinterpret_cast<char *>(*data), fileSize);
    file.close();

    return true;
}

// =====================================================
// Função para salvar RAW (float32)
// =====================================================
void saveRAW(const char *filename, float *data, int N)
{
    ofstream file(filename, ios::binary);
    file.write(reinterpret_cast<char *>(data), N * sizeof(float));
    file.close();
}

// =====================================================
// Programa principal — igual ao exemplo PPM
// =====================================================
int main(int argc, char *argv[])
{
    float *h_in;   // áudio de entrada no host
    float *h_out;  // áudio filtrado no host
    int N;         // número total de amostras (float)

    // Verifica argumentos
    if (argc < 2)
    {
        cout << "Uso: " << argv[0] << " <input.raw>" << endl;
        return -1;
    }

    // Carrega arquivo RAW para memória da CPU
    if (!loadRAW(argv[1], &h_in, N))
        return -1;

    cout << "Arquivo carregado com " << N << " amostras." << endl;

    // Aloca saída no host
    h_out = new float[N];

    // Ponteiros na GPU
    float *d_in, *d_out;

    cudaMalloc(&d_in,  N * sizeof(float));
    cudaMalloc(&d_out, N * sizeof(float));

    // Copia entrada para GPU
    cudaMemcpy(d_in, h_in, N * sizeof(float), cudaMemcpyHostToDevice);

    // Configuração do kernel
    int threads = 256;
    int blocks  = (N + threads - 1) / threads;

    // Chama kernel (igual ao invertColors)
    audioFilter<<<blocks, threads>>>(d_in, d_out, N);
    cudaDeviceSynchronize();

    // Copia resultado para CPU
    cudaMemcpy(h_out, d_out, N * sizeof(float), cudaMemcpyDeviceToHost);

    // Salva o áudio filtrado
    saveRAW("output.raw", h_out, N);
    cout << "Áudio processado e salvo como output.raw" << endl;

    // Libera GPU
    cudaFree(d_in);
    cudaFree(d_out);

    // Libera CPU
    delete[] h_in;
    delete[] h_out;

    return 0;
}
