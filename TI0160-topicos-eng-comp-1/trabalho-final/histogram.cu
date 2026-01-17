#include <cuda_runtime.h>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <iostream>
#include <vector>
#include <cstdint>

namespace py = pybind11;

#define CHECK_CUDA(call) \
    do { \
        cudaError_t err = call; \
        if (err != cudaSuccess) { \
            std::cerr << "CUDA Error: " << cudaGetErrorString(err) << " at line " << __LINE__ << std::endl; \
            throw std::runtime_error(std::string("CUDA Error: ") + cudaGetErrorString(err)); \
        } \
    } while (0)

__global__ void histogram_kernel(const unsigned char *img, int32_t *hist, int size)
{
    int i = blockIdx.x * blockDim.x + threadIdx.x;
    int stride = blockDim.x * gridDim.x;

    while (i < size) {
        unsigned char val = img[i];
        atomicAdd(&hist[val], 1);
        i += stride;
    }
}

std::vector<int32_t> calculate_histogram(py::array_t<unsigned char, py::array::c_style | py::array::forcecast> input_image)
{
    py::buffer_info buf = input_image.request();
    
    int size = buf.size;
    unsigned char *h_img = (unsigned char *)buf.ptr;

    unsigned char *d_img = nullptr;
    int32_t *d_hist = nullptr;
    int hist_bytes = 256 * sizeof(int32_t);

    try {
        CHECK_CUDA(cudaMalloc(&d_img, size * sizeof(unsigned char)));
        CHECK_CUDA(cudaMalloc(&d_hist, hist_bytes));

        CHECK_CUDA(cudaMemcpy(d_img, h_img, size * sizeof(unsigned char), cudaMemcpyHostToDevice));
        CHECK_CUDA(cudaMemset(d_hist, 0, hist_bytes));

        int threads = 256;
        int blocks = (size + threads - 1) / threads;
        if (blocks > 256) blocks = 256;

        histogram_kernel<<<blocks, threads>>>(d_img, d_hist, size);

        CHECK_CUDA(cudaPeekAtLastError());
        CHECK_CUDA(cudaDeviceSynchronize());

        // Aloca vetor na CPU para receber os dados
        std::vector<int32_t> result_vec(256);
        
        // Copia da GPU para o vetor std::vector
        CHECK_CUDA(cudaMemcpy(result_vec.data(), d_hist, hist_bytes, cudaMemcpyDeviceToHost));

        cudaFree(d_img);
        cudaFree(d_hist);

        return result_vec;

    } catch (...) {
        if (d_img) cudaFree(d_img);
        if (d_hist) cudaFree(d_hist);
        throw;
    }
}

PYBIND11_MODULE(histogram_cuda, m) {
    m.doc() = "Módulo CUDA para cálculo de histograma (Safe Vector Return)";
    m.def("calculate_histogram", &calculate_histogram, "Calcula histograma retornando lista");
}
