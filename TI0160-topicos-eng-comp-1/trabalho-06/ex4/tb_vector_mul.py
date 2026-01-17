import numpy as np, cuda_math

x = np.array([1,2,3,4,5], dtype=np.float32)
y = np.array([10,20,30,40,50], dtype=np.float32)
print("x = ", x)
print("y = ", y)
print("m = ", cuda_math.vector_mul(x, y))
