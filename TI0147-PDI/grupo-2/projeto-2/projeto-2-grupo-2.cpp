#include <opencv2/opencv.hpp>
#include <iostream>
#include <cmath>

using namespace cv;
using namespace std;

Mat logTransform(const Mat& image) {
    Mat imageFloat;
    image.convertTo(imageFloat, CV_32F);
    
    double maxVal;
    minMaxLoc(imageFloat, nullptr, &maxVal);
    
    double c = 255 / log(1 + maxVal);
    Mat imageLog = c * (imageFloat + 1);
    log(imageLog, imageLog);
    
    imageLog = min(max(imageLog, 0.0f), 255.0f);
    Mat result;
    imageLog.convertTo(result, CV_8U);
    return result;
}

Mat powerTransform(const Mat& image, double gamma) {
    Mat imageFloat;
    image.convertTo(imageFloat, CV_32F);
    
    double maxVal;
    minMaxLoc(imageFloat, nullptr, &maxVal);
    
    double c = 255 / pow(maxVal, gamma);
    Mat imagePower;
    pow(imageFloat, gamma, imagePower);
    imagePower *= c;
    
    imagePower = min(max(imagePower, 0.0f), 255.0f);
    Mat result;
    imagePower.convertTo(result, CV_8U);
    return result;
}

int main() {
    Mat lua = imread("Fig0338(a)(blurry_moon).tif", IMREAD_GRAYSCALE);
    Mat quadrado = imread("Fig0326(a)(embedded_square_noisy_512).tif", IMREAD_GRAYSCALE);
    
    if (lua.empty() || quadrado.empty()) {
        cerr << "Erro ao carregar as imagens!" << endl;
        return -1;
    }
    
    Mat imgLog = logTransform(lua);
    Mat imgPower = powerTransform(lua, 2.0);
    
    imshow("Imagem Original", lua);
    imshow("Transformacao Logaritmica", imgLog);
    imshow("Transformacao Potencia", imgPower);
    
    waitKey(0);
    return 0;
}
