nvcc -O3 -shared -Xcompiler "-fPIC" $(python3 -m pybind11 --includes) vector_sum.cu -o cuda_vector$(python3-config --extension-suffix)
