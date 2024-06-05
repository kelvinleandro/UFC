# Suponha que você tem k vetores ordenados de tamanho n e deseja combiná-los em um único vetor ordenado de tamanho kn. 
# (a) Uma ideia é usar o algoritmo Intercala, intercalando o primeiro e o segundo, depois intercalando o resultado 
# com o terceiro, depois com o quarto e etc. Qual a complexidade desse procedimento em termos de k e n? (b) Mostre 
# uma solução mais eficiente usando divisão e conquista.

def merge(v, p, q, r):
    infinito = float('inf')
    esq = v[p:q + 1] + [infinito]
    dir = v[q + 1:r + 1] + [infinito]

    i, j = 0, 0
    for k in range(p, r + 1):
        if esq[i] <= dir[j]:
            v[k] = esq[i]
            i += 1
        else:
            v[k] = dir[j]
            j += 1

def questao14a(v, n, k):
    for i in range(1, k):
        merge(v, 0, i * n - 1, (i + 1) * n - 1)

def questao14bb(v, n, k):
    tam = k * n
    while k > 1:
        i = 0
        while i + 2 <= k:
            end_idx = min((i + 2) * n - 1, tam - 1)
            merge(v, i * n, (i + 1) * n - 1, v, i * n, (i + 1) * n - 1, end_idx)
            i += 2
        k = int(k / 2.0)
        n = 2 * n

def questao14b(v, n, k1, k2):
    if k2 - k1 < 1:
        return

    k = (k1 + k2) // 2
    questao14b(v, n, k1, k)
    questao14b(v, n, k + 1, k2)

    p = (k1 - 1) * n
    q = min(k * n - 1, len(v) - 1)  # Limit q to the last element of v
    r = min(k2 * n - 1, len(v) - 1)  # Limit r to the last element of v
    merge(v, p, q, r)

# Example usage:
X = [3, 1, 4, 2, 5]
n = len(X)
k = 2
questao14b(X, n, 1, k)
print(f"Merged array: {X}")
