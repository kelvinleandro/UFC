#include <opencv2/opencv.hpp>
#include <iostream>
#include <cstdint>

using namespace cv;
using namespace std;

void reduzirNiveisIntensidade(Mat imagemOriginal, Mat& imagemReduzida, int niveis) {
    imagemOriginal.convertTo(imagemReduzida, CV_8U);
    uint16_t fatorReducao = 256 / niveis;
    imagemReduzida = imagemReduzida / fatorReducao;
    imagemReduzida = imagemReduzida * fatorReducao;
}

int main() {
    Mat imagemReduzida;
    Mat imagemOriginal = imread("Fig2.21(a).jpg");
    if (imagemOriginal.empty()) {
        cerr << "Erro ao carregar a imagem!" << endl;
        return -1;
    }

    // Define o número de níveis de intensidade desejado (ex: 16)
    int niveis;
    cout << "Digite o número de níveis de intensidade (potência de 2): ";
    cin >> niveis;

    // Reduz a imagem para o número desejado de níveis de intensidade
    reduzirNiveisIntensidade(imagemOriginal, imagemReduzida, niveis);

    // Exibe a imagem original e a imagem reduzida
    imshow("Imagem Original", imagemOriginal);
    imshow("Imagem Reduzida", imagemReduzida);

    // Salva a imagem reduzida em um arquivo
    imwrite("imagem_reduzida.jpg", imagemReduzida);

    // Aguarda a tecla para fechar as janelas
    waitKey(0);
    return 0;
}
