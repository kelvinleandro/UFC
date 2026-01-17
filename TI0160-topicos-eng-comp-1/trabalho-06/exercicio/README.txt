# Comando para compilar o módulo Python "cuda_ops" a partir do código CUDA.
#
# -O3: Nível de otimização
# -shared: Cria uma biblioteca compartilhada (.so no Linux, .pyd no Windows)
# -Xcompiler "-fPIC": Gera código de posição independente, necessário para libs compartilhadas
# $(python3 -m pybind11 --includes): Adiciona os cabeçalhos do PyBind11
# -o cuda_ops...: Nome do arquivo de saída, ex: cuda_ops.cpython-310-x86_64-linux-gnu.so
#
nvcc -O3 -shared -Xcompiler "-fPIC" $(python3 -m pybind11 --includes) vector_ops.cu -o cuda_ops$(python3-config --extension-suffix)
