#include <iostream>
#include <cuda_runtime.h>
using namespace std;

__global__ void helloFromGPU(){
    printf("Hello from GPU Thread %d\n", threadIdx.x);
}

int main () {
    cout << "Hello from CPU!" << endl;

    helloFromGPU <<<1, 5>>>(); //1 bloco, 5 threads
    cudaDeviceSynchronize();
    
    return 0;
}