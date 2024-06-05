# Seja X[1...n] um vetor de inteiros. Dados i<j em {1,...,n}, dizemos que (i,j) é uma inversão de X se X[i]>X[j]. 
# Escreva um algoritmo O(nlogn) que devolva o número de inversões em um vetor X. Dica: Tenta fazer essa contagem 
# enquanto ordena o vetor no Merge-Sort.

def merge_cont(v, p, q, r):
    infinito = float('inf')
    N1 = q - p + 1
    N2 = r - q
    esq = [0] * (N1 + 1)
    dir = [0] * (N2 + 1)
    for i in range(N1):
        esq[i] = v[p + i]
    for j in range(N2):
        dir[j] = v[q + j + 1]
    esq[N1] = infinito
    dir[N2] = infinito

    i, j = 0, 0
    cont = 0
    for k in range(p, r + 1):
        if esq[i] <= dir[j]:
            v[k] = esq[i]
            cont += j
            i += 1
        else:
            v[k] = dir[j]
            j += 1
    return cont

def questao12(v, p, r):
    if p >= r:
        return 0
    q = (p + r) // 2
    cont1 = questao12(v, p, q)
    cont2 = questao12(v, q + 1, r)
    cont3 = merge_cont(v, p, q, r)
    return cont1 + cont2 + cont3

# Example usage:
X = [3, 1, 4, 2, 5]
result = questao12(X, 0, len(X) - 1)
print(f"Number of inversions: {result}")
