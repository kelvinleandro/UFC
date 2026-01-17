// ============================================================================
// Bibliotecas essenciais
// ============================================================================

// Inclui todo o módulo principal do OpenCV (parte CPU):
// - cv::Mat
// - cv::imread()
// - cv::imwrite()
// - cv::cvtColor() CPU (não usado aqui, mas vem no pacote)
// - funções utilitárias de processamento de imagem
#include <opencv2/opencv.hpp>

// Inclui os módulos CUDA do OpenCV relacionados à imagem:
// - cv::cuda::GpuMat          → matriz armazenada na memória da GPU
// - cv::cuda::cvtColor        → conversão de cores acelerada por CUDA
// - filtros CUDA (Gaussian, Sobel, Canny, resize, etc)
// OBS: essa biblioteca não contém kernels customizados, mas sim as versões
//      prontas e otimizadas que o OpenCV implementou para CUDA.
#include <opencv2/cudaimgproc.hpp>

// Biblioteca padrão de C++ para operações de entrada/saída,
// usada aqui para imprimir mensagens no console.
#include <iostream>

// ============================================================================
// Função principal do programa
// ============================================================================
int main(int argc, char** argv)
{
    // ------------------------------------------------------------------------
    // Verifica se o usuário passou o nome de uma imagem como argumento.
    // Exemplo esperado:
    //     ./programa imagem.jpg
    // Caso contrário, mostra a forma correta de uso e termina.
    // ------------------------------------------------------------------------
    if (argc < 2) {
        std::cout << "Uso: " << argv[0] << " <imagem>" << std::endl;
        return -1;
    }

    // ------------------------------------------------------------------------
    // 1) Carrega imagem na CPU
    //
    // cv::imread():
    //  - lê o arquivo de imagem do disco
    //  - armazena os pixels em uma matriz cv::Mat (na RAM)
    //
    // IMPORTANTE:
    // A imagem carregada está inicialmente em BGR (padrão OpenCV).
    // ------------------------------------------------------------------------
    cv::Mat img = cv::imread(argv[1]);

    // Verifica se a imagem realmente foi carregada
    if (img.empty()) {
        std::cout << "Erro ao abrir imagem!\n";
        return -1;
    }

    // ------------------------------------------------------------------------
    // 2) Envia a imagem para a GPU
    //
    // cv::cuda::GpuMat:
    //  - funciona como cv::Mat, mas armazena os dados na memória da GPU (VRAM)
    //
    // gpuImg.upload(img):
    //  - transfere os bytes da imagem (RAM → VRAM)
    //  - essa operação copia *toda* a imagem pela PCIe
    //
    // gpuGray é apenas alocado aqui; será preenchido no passo 3.
    // ------------------------------------------------------------------------
    cv::cuda::GpuMat gpuImg, gpuGray;

    // CPU → GPU
    gpuImg.upload(img);

    // ------------------------------------------------------------------------
    // 3) Conversão para cinza usando CUDA interna do OpenCV
    //
    // cv::cuda::cvtColor():
    //  - versão CUDA da função cvtColor do OpenCV
    //  - utiliza kernels altamente otimizados escritos em CUDA
    //  - roda 100% na GPU, paralelizando pixel a pixel
    //
    // Argumentos:
    //  - gpuImg   : imagem de entrada na GPU
    //  - gpuGray  : imagem de saída na GPU
    //  - cv::COLOR_BGR2GRAY : conversão BGR → GRAY (1 canal de intensidade)
    //
    // IMPORTANTE:
    // Nenhum dado volta para a CPU aqui; tudo ocorre na memória da GPU.
    // ------------------------------------------------------------------------
    cv::cuda::cvtColor(gpuImg, gpuGray, cv::COLOR_BGR2GRAY);

    // ------------------------------------------------------------------------
    // 4) Baixa imagem processada da GPU para a CPU
    //
    // gpuGray.download(gray):
    //  - transfere VRAM → RAM
    //  - após isso, gray passa a ser um cv::Mat "normal"
    //
    // Observe que a imagem agora terá apenas 1 canal (tons de cinza).
    // ------------------------------------------------------------------------
    cv::Mat gray;         // matriz destino na CPU
    gpuGray.download(gray);

    // ------------------------------------------------------------------------
    // 5) Salva imagem final processada em disco
    //
    // cv::imwrite():
    //  - escreve a imagem "gray" em formato JPEG, PNG, etc.
    //  - o OpenCV detecta o formato automaticamente pela extensão
    // ------------------------------------------------------------------------
    cv::imwrite("saida_gray.jpg", gray);

    std::cout << "Imagem salva como saida_gray.jpg" << std::endl;

    // Finaliza programa
    return 0;
}