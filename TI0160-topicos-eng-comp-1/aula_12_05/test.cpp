#include <iostream>
#include <opencv2/core.hpp>

int main() {
    std::cout << "OpenCV version: " << CV_VERSION << std::endl;

#ifdef HAVE_OPENCV_CUDAARITHM
    std::cout << "CUDA modules disponíveis." << std::endl;
#else
    std::cout << "OpenCV compilado SEM suporte a CUDA." << std::endl;
#endif

    return 0;
}