// =======================================================
// vector_sum.cu
// Exemplo de soma de vetores usando CUDA + PyBind11
// Python (NumPy) → GPU (CUDA) → Python
// =======================================================

// Biblioteca principal do CUDA Runtime
#include <cuda_runtime.h>

// Cabeçalhos do PyBind11 para criar módulos Python em C++
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

// Namespace usado pelo PyBind11
namespace py = pybind11;

// =======================================================
// KERNEL CUDA
// =======================================================
// __global__ indica que esta função:
//  - roda no GPU
//  - é chamada pelo CPU (host)
//
// Cada thread soma um elemento do vetor
__global__ void add_kernel(float* a, float* b, float* c, int n) {

    // Calcula o índice global da thread
    // blockIdx.x  → índice do bloco
    // blockDim.x  → número de threads por bloco
    // threadIdx.x → índice da thread dentro do bloco
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Garante que a thread não acesse fora do vetor
    if (i < n)
        c[i] = a[i] + b[i];
}

// =======================================================
// FUNÇÃO HOST (C++)
// =======================================================
// Esta função:
//  - é chamada pelo Python
//  - recebe arrays NumPy
//  - executa CUDA
//  - retorna um array NumPy
py::array_t<float> vector_add(py::array_t<float> a,
                              py::array_t<float> b) {

    // Obtém informações internas dos arrays NumPy
    // (ponteiro, tamanho, formato, etc.)
    auto bufA = a.request();
    auto bufB = b.request();

    // Verifica se os vetores têm o mesmo tamanho
    if (bufA.size != bufB.size)
        throw std::runtime_error("Tamanhos diferentes!");

    // Número de elementos do vetor
    int n = bufA.size;

    // Cria o array de saída (NumPy) no Python
    py::array_t<float> c(n);
    auto bufC = c.request();

    // Ponteiros para a memória HOST (CPU)
    float *h_a = (float*) bufA.ptr;
    float *h_b = (float*) bufB.ptr;
    float *h_c = (float*) bufC.ptr;

    // Ponteiros para a memória DEVICE (GPU)
    float *d_a, *d_b, *d_c;

    // ===================================================
    // ALOCAÇÃO DE MEMÓRIA NO GPU
    // ===================================================
    cudaMalloc(&d_a, n * sizeof(float));
    cudaMalloc(&d_b, n * sizeof(float));
    cudaMalloc(&d_c, n * sizeof(float));

    // ===================================================
    // CÓPIA CPU → GPU
    // ===================================================
    cudaMemcpy(d_a, h_a, n * sizeof(float),
               cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, n * sizeof(float),
               cudaMemcpyHostToDevice);

    // ===================================================
    // CONFIGURAÇÃO E EXECUÇÃO DO KERNEL
    // ===================================================
    int threads = 256; // threads por bloco

    // Número de blocos necessários
    int blocks = (n + threads - 1) / threads;

    // Lançamento do kernel CUDA
    add_kernel<<<blocks, threads>>>(d_a, d_b, d_c, n);

    // ===================================================
    // CÓPIA GPU → CPU
    // ===================================================
    cudaMemcpy(h_c, d_c, n * sizeof(float),
               cudaMemcpyDeviceToHost);

    // ===================================================
    // LIBERAÇÃO DE MEMÓRIA DO GPU
    // ===================================================
    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    // Retorna o array NumPy para o Python
    return c;
}

// =======================================================
// MÓDULO PYTHON
// =======================================================
// Define o módulo chamado "cuda_vector"
// Deve coincidir com o nome do arquivo .so
PYBIND11_MODULE(cuda_vector, m) {

    // Exposição da função vector_add ao Python
    m.def("vector_add", &vector_add,
          "Soma de vetores usando CUDA");
}