#include <iostream>
#include <cuda_runtime.h>
using namespace std;

int main() {
    cudaDeviceProp prop;
    int device;
    cudaGetDevice(&device);
    cudaGetDeviceProperties(&prop, device);

    cout << "Nome da GPU: " << prop.name << endl;
    cout << "Multiprocessadores (SMs): " << prop.multiProcessorCount << endl;
    cout << "Threads por bloco (máx): " << prop.maxThreadsPerBlock << endl;
    cout << "Blocos por multiprocessador: " << prop.maxBlocksPerMultiProcessor << endl;
    cout << "Threads por multiprocessador: " << prop.maxThreadsPerMultiProcessor << endl;
}
