import numpy as np
# O nome do módulo deve ser o mesmo definido no PYBIND11_MODULE
# e no nome do arquivo de saída da compilação.
import cuda_ops

# Cria dois vetores de entrada
a = np.arange(1, 6, dtype=np.float32)
b = np.array([10, 20, 30, 40, 50], dtype=np.float32)

print("Vetores de Entrada:")
print("a =", a)
print("b =", b)
print("-" * 30)

# Chama a função de soma do módulo CUDA
soma = cuda_ops.vector_add(a, b)
print("Resultado da Soma (a + b):")
print("s =", soma)
print("-" * 30)

# Chama a função de multiplicação do módulo CUDA
mult = cuda_ops.vector_mul(a, b)
print("Resultado da Multiplicação (a * b):")
print("m =", mult)
