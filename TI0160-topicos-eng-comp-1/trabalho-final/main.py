import cv2
import numpy as np
import matplotlib.pyplot as plt
import sys
import os

try:
    import histogram_cuda
except ImportError:
    print("Erro: Módulo 'histogram_cuda' não encontrado.")
    sys.exit(1)

def main():
    image_path = "image.jpg"
    if len(sys.argv) > 1:
        image_path = sys.argv[1]

    if not os.path.exists(image_path):
        print(f"Erro: Imagem '{image_path}' não encontrada.")
        return

    print(f"Lendo imagem: {image_path}")
    img = cv2.imread(image_path, cv2.IMREAD_GRAYSCALE)

    if img is None:
        print("Erro ao decodificar a imagem.")
        return

    total_pixels = img.size
    print(f"Dimensões: {img.shape}, Total de Pixels: {total_pixels}")

    print("-" * 30)
    print("Calculando histograma na GPU...")
    try:
        # Retorno agora é uma lista de inteiros
        hist_list = histogram_cuda.calculate_histogram(img)
        # Converte explicitamente para numpy array
        hist_cuda = np.array(hist_list, dtype=np.int32)
    except Exception as e:
        print(f"ERRO CUDA: {e}")
        return

    print("-" * 30)

    # Visualização
    plt.figure(figsize=(12, 5))
    
    plt.subplot(1, 2, 1)
    plt.imshow(img, cmap='gray')
    plt.title("Imagem Grayscale")
    plt.axis('off')

    plt.subplot(1, 2, 2)
    # plt.bar é melhor para histogramas que plt.plot
    plt.bar(range(256), hist_cuda, width=1.0, color='black', alpha=0.7)
    plt.title("Histograma (CUDA)")
    plt.xlabel("Intensidade")
    plt.ylabel("Frequência")
    plt.xlim([-10, 255])
    plt.grid(True, alpha=0.3, axis='y')

    output_file = "histograma_output.png"
    plt.savefig(output_file)
    print(f"Gráfico salvo em '{output_file}'")
    plt.show()

if __name__ == "__main__":
    main()
