// =======================================================
// vector_mul.cu
// Exemplo de multiplicação elemento a elemento de vetores
// usando CUDA + PyBind11
// Python (NumPy) → GPU (CUDA) → Python
// =======================================================

// Biblioteca do runtime CUDA (cudaMalloc, cudaMemcpy, etc.)
#include <cuda_runtime.h>

// Cabeçalhos do PyBind11 para integração com Python
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

// Namespace padrão do PyBind11
namespace py = pybind11;

// =======================================================
// KERNEL CUDA
// =======================================================
// __global__ indica que:
//  - esta função executa no GPU
//  - é chamada pelo CPU (host)
//
// Cada thread multiplica um elemento do vetor
__global__ void mul_kernel(float* a, float* b, float* c, int n) {

    // Cálculo do índice global da thread
    int i = blockIdx.x * blockDim.x + threadIdx.x;

    // Proteção contra acesso fora dos limites do vetor
    if (i < n)
        c[i] = a[i] * b[i];
}

// =======================================================
// FUNÇÃO HOST (C++)
// =======================================================
// Esta função:
//  - é chamada pelo Python
//  - recebe vetores NumPy
//  - gerencia memória no GPU
//  - lança o kernel CUDA
//  - retorna um vetor NumPy
py::array_t<float> vector_mul(py::array_t<float> a,
                              py::array_t<float> b) {

    // Obtém informações internas dos arrays NumPy --> py::buffer_info bufA = a.request();
    auto bufA = a.request();
    auto bufB = b.request();

    // Número de elementos do vetor
    int n = bufA.size;

    // Cria o vetor de saída (NumPy) no Python
    py::array_t<float> c(n);
    auto bufC = c.request();

    // ===================================================
    // Ponteiros HOST (CPU)
    // ===================================================
    float *h_a = (float*) bufA.ptr; // vetor A
    float *h_b = (float*) bufB.ptr; // vetor B
    float *h_c = (float*) bufC.ptr; // vetor C (resultado)

    // ===================================================
    // Ponteiros DEVICE (GPU)
    // ===================================================
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
    // CONFIGURAÇÃO DO GRID CUDA
    // ===================================================
    int threads = 128; // threads por bloco

    // Número de blocos necessários para cobrir o vetor
    int blocks = (n + threads - 1) / threads;

    // ===================================================
    // LANÇAMENTO DO KERNEL
    // ===================================================
    mul_kernel<<<blocks, threads>>>(d_a, d_b, d_c, n);

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

    // Retorna o vetor NumPy para o Python
    return c;
}

// =======================================================
// DEFINIÇÃO DO MÓDULO PYTHON
// =======================================================
// O nome "cuda_math" deve coincidir com o nome do arquivo .so
PYBIND11_MODULE(cuda_math, m) {

    // Expõe a função vector_mul para o Python
    m.def("vector_mul", &vector_mul,
          "Multiplicação elemento a elemento de vetores usando CUDA");
}