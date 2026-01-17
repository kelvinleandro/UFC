#include <iostream>

// Cabeçalho principal do OpenCV (lado CPU):
// - cv::Mat
// - cv::imread()
// - cv::imwrite()
// - utilidades de imagem e matriz
#include <opencv2/opencv.hpp>

// Núcleo CUDA do OpenCV (define cv::cuda::GpuMat e infraestrutura base da GPU)
#include <opencv2/core/cuda.hpp>

// Módulo CUDA que contém warpAffine(), resize(), remap(), etc.
#include <opencv2/cudawarping.hpp>



int main(int argc, char** argv)
{
    // =======================================================================================
    // 1) Verificação dos argumentos de entrada
    // =======================================================================================
    // O programa exige que o usuário passe o caminho de um arquivo de imagem.
    if (argc < 2)
    {
        std::cout << "Uso: " << argv[0] << " <imagem>" << std::endl;
        return -1;
    }



    // =======================================================================================
    // 2) Carrega a imagem na CPU (RAM)
    // =======================================================================================
    // cv::imread() retorna um cv::Mat armazenado na memória do host (CPU)
    cv::Mat img = cv::imread(argv[1]);

    if (img.empty())
    {
        std::cout << "Erro ao carregar imagem!" << std::endl;
        return -1;
    }

    // Obtém largura e altura (dimensões da imagem)
    int width  = img.cols;
    int height = img.rows;



    // =======================================================================================
    // 3) Envio da imagem para a GPU (RAM → VRAM)
    // =======================================================================================
    // cv::cuda::GpuMat:
    //   - similar a cv::Mat, mas seus dados estão residentes na VRAM (memória da GPU).
    //   - Ao passar um cv::Mat no construtor, o OpenCV realiza automaticamente o upload.
    //
    // d_img: imagem de entrada na GPU
    // d_out: imagem de saída processada pela GPU
    cv::cuda::GpuMat d_img(img);
    cv::cuda::GpuMat d_out;



    // =======================================================================================
    // 4) Definição da MATRIZ DE TRANSFORMAÇÃO AFIM
    // =======================================================================================
    //
    // warpAffine() realiza transformações 2D da forma:
    //
    //    [x']   [ a11  a12  tx ] [x]
    //    [y'] = [ a21  a22  ty ] [y]
    //    [1 ]   [  0    0    1 ] [1]
    //
    // Para um FLIP HORIZONTAL:
    //
    //   x' = -x + width
    //   y' =  y
    //
    // Isso é equivalente à matriz:
    //
    //   [ -1   0   width ]
    //   [  0   1      0  ]
    //
    // Onde:
    //   - "-1" inverte (espelha) a coordenada x
    //   - "+ width" desloca a imagem invertida para a região visível (0..width)
    // =======================================================================================

    cv::Mat M = (cv::Mat_<double>(2,3) <<
        -1, 0, width,   // primeira linha: transformação de x → x'
         0, 1,     0);  // segunda linha: transformação de y → y'



    // =======================================================================================
    // 5) Execução do warpAffine na GPU
    // =======================================================================================
    //
    // cv::cuda::warpAffine():
    //    - Aplica a transformação afim usando CUDA.
    //    - Realiza amostragem bilinear ou nearest neighbor na GPU.
    //    - Processa cada pixel em paralelo usando milhares de threads CUDA.
    //
    // d_img   → entrada
    // d_out   → saída
    // M       → matriz de transformação afim 2×3
    // img.size() → tamanho final da imagem (mesmo tamanho da entrada)
    // =======================================================================================

    cv::cuda::warpAffine(
        d_img,      // imagem de entrada na GPU
        d_out,      // destino na GPU
        M,          // matriz de transformação
        img.size()  // tamanho final (mesmo da imagem original)
    );



    // =======================================================================================
    // 6) Download da imagem resultante (GPU → CPU)
    // =======================================================================================
    // d_out contém a imagem espelhada na GPU.
    // Para salvar em disco, é necessário trazê-la de volta à CPU.
    cv::Mat out;
    d_out.download(out);



    // =======================================================================================
    // 7) Salva imagem processada
    // =======================================================================================
    cv::imwrite("output_flip_cuda.jpg", out);

    std::cout << "Imagem espelhada salva como output_flip_cuda.jpg" << std::endl;

    return 0;
}
