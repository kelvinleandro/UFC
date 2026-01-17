// =======================================================
// vector_ops.cu
// Operações de soma e multiplicação de vetores usando
// CUDA + PyBind11
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
// KERNELS CUDA
// =======================================================

// Kernel de Soma: Cada thread soma um elemento do vetor
__global__ void add_kernel(float* a, float* b, float* c, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n)
        c[i] = a[i] + b[i];
}

// Kernel de Multiplicação: Cada thread multiplica um elemento
__global__ void mul_kernel(float* a, float* b, float* c, int n) {
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i < n)
        c[i] = a[i] * b[i];
}

// =======================================================
// FUNÇÕES HOST (C++)
// =======================================================

// -------------------------------------------------------
// SOMA DE VETORES
// -------------------------------------------------------
py::array_t<float> vector_add(py::array_t<float> a,
                              py::array_t<float> b) {

    auto bufA = a.request();
    auto bufB = b.request();

    if (bufA.size != bufB.size)
        throw std::runtime_error("Input arrays must have the same size");

    int n = bufA.size;
    py::array_t<float> c(n);
    auto bufC = c.request();

    float *h_a = (float*) bufA.ptr;
    float *h_b = (float*) bufB.ptr;
    float *h_c = (float*) bufC.ptr;

    float *d_a, *d_b, *d_c;
    cudaMalloc(&d_a, n * sizeof(float));
    cudaMalloc(&d_b, n * sizeof(float));
    cudaMalloc(&d_c, n * sizeof(float));

    cudaMemcpy(d_a, h_a, n * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, n * sizeof(float), cudaMemcpyHostToDevice);

    int threads = 256;
    int blocks = (n + threads - 1) / threads;
    add_kernel<<<blocks, threads>>>(d_a, d_b, d_c, n);

    cudaMemcpy(h_c, d_c, n * sizeof(float), cudaMemcpyDeviceToHost);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return c;
}

// -------------------------------------------------------
// MULTIPLICAÇÃO DE VETORES
// -------------------------------------------------------
py::array_t<float> vector_mul(py::array_t<float> a,
                              py::array_t<float> b) {

    auto bufA = a.request();
    auto bufB = b.request();

    if (bufA.size != bufB.size)
        throw std::runtime_error("Input arrays must have the same size");

    int n = bufA.size;
    py::array_t<float> c(n);
    auto bufC = c.request();

    float *h_a = (float*) bufA.ptr;
    float *h_b = (float*) bufB.ptr;
    float *h_c = (float*) bufC.ptr;

    float *d_a, *d_b, *d_c;
    cudaMalloc(&d_a, n * sizeof(float));
    cudaMalloc(&d_b, n * sizeof(float));
    cudaMalloc(&d_c, n * sizeof(float));

    cudaMemcpy(d_a, h_a, n * sizeof(float), cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, h_b, n * sizeof(float), cudaMemcpyHostToDevice);

    int threads = 256;
    int blocks = (n + threads - 1) / threads;
    mul_kernel<<<blocks, threads>>>(d_a, d_b, d_c, n);

    cudaMemcpy(h_c, d_c, n * sizeof(float), cudaMemcpyDeviceToHost);

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    return c;
}

// =======================================================
// MÓDULO PYTHON
// =======================================================
PYBIND11_MODULE(cuda_ops, m) {
    m.doc() = "Módulo com operações de vetores em CUDA (soma, multiplicação)";

    m.def("vector_add", &vector_add,
          "Soma elemento a elemento de dois vetores NumPy");

    m.def("vector_mul", &vector_mul,
          "Multiplica elemento a elemento de dois vetores NumPy");
}
