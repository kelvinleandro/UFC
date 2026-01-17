#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/cuda.hpp>

int main() {
    std::cout << "OpenCV: " << CV_VERSION << std::endl;

    int n = cv::cuda::getCudaEnabledDeviceCount();
    std::cout << "GPUs CUDA detectadas: " << n << std::endl;

    if (n == 0) {
        std::cout << "Nenhuma GPU CUDA encontrada pelo OpenCV!" << std::endl;
        return 0;
    }

    cv::cuda::DeviceInfo info(0);
    std::cout << "GPU: " << info.name() << std::endl;
    std::cout << "Compute capability: " << info.majorVersion() << "." << info.minorVersion() << std::endl;
    return 0;
}
