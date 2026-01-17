import matplotlib.pyplot as plt
import numpy as np

P = int(input("Valor de P: "))
A = int(input("Valor de A: "))

graus = np.arange(0, 91)
radiano = np.deg2rad(graus)

sigma_avg = (P / A) * np.sin(radiano)
tau_avg = (P / (2 * A)) * np.sin(2 * radiano)

fig, axes = plt.subplots(1, 2, figsize=(13, 6))

axes[0].plot(graus, sigma_avg)
axes[0].set_xlabel("Ângulo (graus)")
axes[0].set_ylabel(r"$\sigma_{avg}$")
axes[0].set_title("Tensão normal média")
axes[0].set_xticks(np.arange(0, 91, 15))
axes[0].grid(True)

axes[1].plot(graus, tau_avg)
axes[1].set_xlabel("Ângulo (graus)")
axes[1].set_ylabel(r"$\tau_{avg}$")
axes[1].set_title("Tensão de cisalhamento média")
axes[1].set_xticks(np.arange(0, 91, 15))
axes[1].grid(True)

plt.show()