import sys
import subprocess
import os
import pybind11
import sysconfig

def build():
    # Detecta parâmetros do Python
    python_include = sysconfig.get_path('include')
    pybind_include = pybind11.get_include()
    
    # Nome do arquivo de saída
    # No Windows, extensões CCP geralmente são .pyd
    if sys.platform == "win32":
        ext_suffix = ".pyd"
        # Flags específicas para MSVC
        cflags = ['-Xcompiler', '/MD']
        
        # Precisamos da biblioteca python para linkar
        # Ex: python310.lib
        py_ver_major = sys.version_info.major
        py_ver_minor = sys.version_info.minor
        lib_name = f"python{py_ver_major}{py_ver_minor}.lib"
        lib_path = os.path.join(sys.prefix, 'libs')
        
        lflags = [f'-L"{lib_path}"', f'-lpython{py_ver_major}{py_ver_minor}']
        
    else:
        # Linux/Mac (comportamento similar ao README do trabalho-06)
        # Tenta obter sufixo via sysconfig ou hardcoded
        ext_suffix = sysconfig.get_config_var('EXT_SUFFIX')
        if not ext_suffix:
            ext_suffix = ".so"
            
        cflags = ['-Xcompiler', '-fPIC']
        lflags = [] # Geralmente não precisa linkar libpython explicitamente no Linux com -shared
    
    output_filename = f"histogram_cuda{ext_suffix}"
    
    # Monta o comando
    # nvcc -O3 -shared [cflags] -I... -I... source.cu -o output [lflags]
    
    cmd = [
        "nvcc",
        "-O3",
        "-shared",
    ] + cflags + [
        f'-I"{python_include}"',
        f'-I"{pybind_include}"',
        "histogram.cu",
        "-o", output_filename
    ] + lflags

    print("=== Compilando Módulo CUDA ===")
    print("Comando:")
    print(" ".join(cmd))
    print("==============================")

    try:
        subprocess.check_call(cmd, shell=(sys.platform == "win32"))
        print(f"\nSucesso! Gerado: {output_filename}")
    except subprocess.CalledProcessError as e:
        print("\nErro na compilação.")
        sys.exit(1)
    except FileNotFoundError:
        print("\nErro: 'nvcc' não encontrado. Verifique se o CUDA Toolkit está instalado e no PATH.")
        sys.exit(1)

if __name__ == "__main__":
    build()
