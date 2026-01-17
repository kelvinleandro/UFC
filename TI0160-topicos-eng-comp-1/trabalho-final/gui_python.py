import tkinter as tk
from tkinter import filedialog, messagebox
from PIL import Image, ImageTk
import cv2
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg


class HistogramApp:
    def __init__(self, root: tk.Tk):
        self.root = root
        self.root.title("Visualizador de Histograma (Versão Python)")
        self.root.geometry("1000x600")

        # Configuração do Layout
        self.top_frame = tk.Frame(self.root, pady=10)
        self.top_frame.pack(side=tk.TOP, fill=tk.X)

        self.btn_load = tk.Button(
            self.top_frame,
            text="Selecionar Imagem",
            command=self.load_image,
            font=("Arial", 12),
        )
        self.btn_load.pack()

        self.main_frame = tk.Frame(self.root)
        self.main_frame.pack(fill=tk.BOTH, expand=True, padx=10, pady=10)

        # -- Lado Esquerdo: Imagem --
        self.left_frame = tk.LabelFrame(
            self.main_frame, text="Imagem Original", width=500
        )
        self.left_frame.pack(side=tk.LEFT, fill=tk.BOTH, expand=True)

        self.lbl_image = tk.Label(self.left_frame, text="Nenhuma imagem carregada")
        self.lbl_image.pack(expand=True)

        # -- Lado Direito: Histograma --
        self.right_frame = tk.LabelFrame(
            self.main_frame, text="Histograma (Processado via CPU/OpenCV)", width=500
        )
        self.right_frame.pack(side=tk.RIGHT, fill=tk.BOTH, expand=True)

        self.figure, self.ax = plt.subplots(figsize=(5, 4), dpi=100)
        self.canvas = FigureCanvasTkAgg(self.figure, master=self.right_frame)
        self.canvas.get_tk_widget().pack(fill=tk.BOTH, expand=True)

    def calculate_histogram_python(self, img_gray):
        """Substitui o histogram.cu usando OpenCV nativo"""
        # Calcula o histograma: [imagem], [canal 0], máscara, [bins], [alcance]
        hist = cv2.calcHist([img_gray], [0], None, [256], [0, 256])
        return hist.flatten()

    def load_image(self):
        file_path = filedialog.askopenfilename(
            filetypes=[("Imagens", "*.jpg *.jpeg *.png *.bmp *.ppm")]
        )

        if not file_path:
            return

        # 1. Carregar imagem
        img_gray = cv2.imread(file_path, cv2.IMREAD_GRAYSCALE)
        img_display = cv2.imread(file_path)

        if img_gray is None:
            messagebox.showerror("Erro", "Falha ao carregar a imagem.")
            return

        img_display = cv2.cvtColor(img_display, cv2.COLOR_BGR2RGB)

        # 2. Processamento (Agora 100% Python/CPU)
        try:
            hist_data = self.calculate_histogram_python(img_gray)
        except Exception as e:
            messagebox.showerror("Erro no Processamento", f"Erro:\n{str(e)}")
            return

        # 3. Atualizar Interface
        self.display_image(img_display)
        self.plot_histogram(hist_data)

    def display_image(self, cv_img):
        h, w, _ = cv_img.shape
        max_size = 450
        scale = min(max_size / w, max_size / h)

        if scale < 1:
            new_w = int(w * scale)
            new_h = int(h * scale)
            cv_img = cv2.resize(cv_img, (new_w, new_h))

        pil_img = Image.fromarray(cv_img)
        tk_img = ImageTk.PhotoImage(pil_img)

        self.lbl_image.config(image=tk_img, text="")
        self.lbl_image.image = tk_img

    def plot_histogram(self, hist_data):
        self.ax.clear()
        self.ax.bar(range(256), hist_data, color="#2c3e50", width=1.0)
        self.ax.set_title("Distribuição de Tons de Cinza")
        self.ax.set_xlim([0, 255])
        self.ax.grid(True, alpha=0.3)
        self.ax.set_xlabel("Valor do Pixel")
        self.ax.set_ylabel("Frequência")

        self.figure.tight_layout()
        self.canvas.draw()


if __name__ == "__main__":
    root = tk.Tk()
    app = HistogramApp(root)
    root.mainloop()
