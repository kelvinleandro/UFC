import numpy as np, cuda_vector

a = np.arange(5, dtype=np.float32)
b = np.ones(5, dtype=np.float32)
print("a = ", a)
print("b = ", b)

print("s = ", cuda_vector.vector_add(a, b))
