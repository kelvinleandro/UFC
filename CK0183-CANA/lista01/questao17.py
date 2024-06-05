# Dizemos que um algoritmo é de quase-ordenação se, para qualquer vetor A[1...n], o algoritmo rearranja os valores
# do vetor A de modo que i<j implica A[i] < A[j] + 0.1. Por exemplo, o vetor A=[1.5 1.45 2.4 2.35 3] está quase-ordenado.
# Sabendo que os valores do vetor de entrada são números reais menores que 100, faça um algoritmo de tempo O(n) para quase-ordenar o vetor.

def counting_sort(arr, k):
    n = len(arr)

    b = [0] * (n)
    c = [0] * (k + 1)

    for i in range(n):
        c[int(arr[i])] += 1

    for i in range(1, k):
        c[i] += c[i - 1]
    
    for j in range(n - 1, -1, -1):
        b[c[int(arr[j])] - 1] = arr[j]
        c[int(arr[j])] -= 1

    for j in range(n):
        arr[j] = b[j]

def quase_ordenado(v, relax):
    """
    Quase-ordena o vetor `v` com um fator de relaxamento `relax`.
    """
    n = len(v)
    
    k = 100

    # Ajusta os valores do vetor para serem inteiros
    for i in range(n):
        v[i] = v[i] / relax
    
    k = int(k / relax)

    # Aplica o Counting Sort
    counting_sort(v, k)
    
    # Restaura os valores originais
    for i in range(n):
        v[i] *= relax
    
    return v

# Exemplo de uso
X = [1.5, 2.35, 3.0, 1.45, 2.4]
relax = 0.1
result = quase_ordenado(X, relax)
print(result)
