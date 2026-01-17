// ============================================================================
//  BIBLIOTECAS ESSENCIAIS PARA O PROGRAMA
// ============================================================================

// OpenCV principal (lado CPU):
// - cv::Mat           → matriz de imagem na memória RAM
// - cv::imread        → leitura de arquivos de imagem
// - cv::imwrite       → salvamento de imagens
// - funções utilitárias para buscar máximos, desenhar gráficos etc.
#include <opencv2/opencv.hpp>

// Módulo CUDA para processamento de imagem:
// - contém funções como cv::cuda::cvtColor(), cv::cuda::resize()
// - implementadas com kernels CUDA altamente otimizados
#include <opencv2/cudaimgproc.hpp>

// Módulo CUDA para operações aritméticas e estatísticas:
// - fornece cv::cuda::calcHist(), operações de soma, multiplicação etc.
// - é a base matemática para muitos kernels CUDA do OpenCV
#include <opencv2/cudaarithm.hpp>

// Biblioteca padrão de C++ para saída de texto
#include <iostream>



// ============================================================================
//  FUNÇÃO PRINCIPAL (ponto de entrada do programa)
// ============================================================================
int main(int argc, char** argv)
{
    // ------------------------------------------------------------------------
    // Verificação dos argumentos de entrada
    //
    // O usuário deve executar o programa assim:
    //    ./histograma imagem.png
    //
    // Se nenhum nome de arquivo for passado, exibimos instruções.
    // ------------------------------------------------------------------------
    if (argc < 2) {
        std::cout << "Uso: " << argv[0] << " <imagem>" << std::endl;
        return -1;
    }



    // ========================================================================
    // 1) CARREGA A IMAGEM EM ESCALA DE CINZA (CPU)
    // ========================================================================
    // cv::imread():
    // - Lê o arquivo em disco.
    // - cv::IMREAD_GRAYSCALE converte automaticamente para 1 canal (0–255).
    //
    // Motivo para usar escala de cinza:
    // - O histograma de intensidade é definido para 1 canal.
    // - É mais simples para ilustrar cálculos de distribuição tonal.
    // ========================================================================
    cv::Mat img = cv::imread(argv[1], cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cout << "Erro ao abrir imagem!\n";
        return -1;
    }



    // ========================================================================
    // 2) TRANSFERE A IMAGEM PARA A GPU (CPU → GPU)
    // ========================================================================
    // cv::cuda::GpuMat:
    // - Equivalente a cv::Mat, mas armazenado na VRAM da GPU.
    //
    // upload():
    // - copia os dados da RAM (memória do host) para a VRAM (memória do device)
    // - essa operação passa pelo barramento PCI Express
    // ========================================================================
    cv::cuda::GpuMat gpuImg;
    gpuImg.upload(img);   // upload da imagem: RAM → VRAM



    // ========================================================================
    // 3) CÁLCULO DO HISTOGRAMA NA GPU
    // ========================================================================
    // Definimos o tamanho do histograma (256 níveis de cinza).
    //
    // cv::cuda::calcHist():
    // - é a função oficial suportada pelo OpenCV CUDA.
    // - percorre os pixels em paralelo usando milhares de threads CUDA.
    // - retorna um GpuMat de 256 linhas e 1 coluna contendo contagens.
    //
    // gpuHist:
    // - será um vetor coluna de inteiros na GPU.
    // ========================================================================
    int histSize = 256;
    cv::cuda::GpuMat gpuHist;

    cv::cuda::calcHist(gpuImg, gpuHist);



    // ========================================================================
    // 4) TRANSFERE O HISTOGRAMA DA GPU PARA A CPU (GPU → CPU)
    // ========================================================================
    // download():
    // - copia os dados do histograma da VRAM para a RAM.
    // - necessário porque vamos desenhar o gráfico no lado da CPU.
    //
    // histCPU:
    // - matriz 256 × 1 contendo o número de pixels para cada intensidade.
    // ========================================================================
    cv::Mat histCPU;
    gpuHist.download(histCPU);



    // ========================================================================
    // 5) NORMALIZAÇÃO DO HISTOGRAMA PARA EXIBIÇÃO
    // ========================================================================
    // O histograma real pode ter valores muito grandes.
    // Para desenhá-lo em uma imagem, precisamos saber o valor máximo (pico).
    //
    // cv::minMaxLoc():
    // - retorna o valor mínimo e máximo dentro do histograma.
    //
    // Usaremos maxVal para escalar as barras verticalmente.
    // ========================================================================
    double maxVal = 0;
    cv::minMaxLoc(histCPU, nullptr, &maxVal);

    // Criar imagem para desenhar o histograma (512 × 400 pixels)
    int width = 512;
    int height = 400;

    // Cria canvas branco (imagem RGB)
    cv::Mat histImg(height, width, CV_8UC3, cv::Scalar(255,255,255));

    // Fator de escala vertical:
    //   valor_maximo_do_bin → altura_total_da_imagem
    float scale = height / maxVal;

    // Cada barra terá uma largura proporcional ao tamanho do gráfico:
    int binWidth = width / histSize;



    // ========================================================================
    // 6) DESENHA O GRÁFICO DO HISTOGRAMA (CPU)
    // ========================================================================
    // Para cada um dos 256 níveis:
    // - pegamos a contagem no histograma
    // - calculamos a altura da barra
    // - desenhamos um retângulo na imagem histImg
    //
    // cv::rectangle():
    // - desenha um retângulo preenchido representando a barra do histograma.
    // ========================================================================
    for (int i = 0; i < histSize; i++)
    {
        // Contagem de pixels daquele nível de cinza
        int binVal = histCPU.at<int>(i);

        // Altura proporcional da barra
        int h = static_cast<int>(binVal * scale);

        // Desenha barra preta vertical
        cv::rectangle(histImg,
                      cv::Point(i * binWidth, height - h),        // canto superior da barra
                      cv::Point((i + 1) * binWidth, height),      // canto inferior da barra
                      cv::Scalar(0, 0, 0),                        // cor preta
                      cv::FILLED);                                // preenchido
    }



    // ========================================================================
    // 7) SALVA O GRÁFICO DO HISTOGRAMA COMO IMAGEM
    // ========================================================================
    // cv::imwrite():
    // - salva a imagem histImg como "histograma.png".
    // ========================================================================
    cv::imwrite("histograma.png", histImg);

    std::cout << "Histograma salvo como histograma.png\n";

    return 0;
}
