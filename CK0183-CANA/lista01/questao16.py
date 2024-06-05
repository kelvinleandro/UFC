# Seja X[1...n] um vetor de números reais. Dizemos que X tem um elemento popular x se mais de um terço de seus 
# elementos são iguais a x. Escreva um algoritmo de tempo linear O(n) que diz se X possui ou não um elemento popular. 
# Caso sim, devolva o seu valor. Dica: Use o algoritmo de Seleção do k-ésimo mínimo de tempo linear no pior caso.

import math

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quickselect(arr, low, high, k):
    if low <= high:
        pi = partition(arr, low, high)

        if pi == k:
            return arr[pi]
        elif pi < k:
            return quickselect(arr, pi + 1, high, k)
        else:
            return quickselect(arr, low, pi - 1, k)
    return None

def kth_smallest(arr, k):
    if k < 1 or k > len(arr):
        return None
    return quickselect(arr, 0, len(arr) - 1, k - 1)

def popular(arr):
    n = len(arr)
    prob = 1 / 3.0
    k = math.ceil(1.0 / prob)

    for i in range(1, k + 1):
        candidate = kth_smallest(arr, i * n // k)
        count = arr.count(candidate)
        if count > prob * n:
            return candidate
    
    return -1

# Exemplo de uso
X = [1, 2, 9, 3, 2, 8, 4, 2, 2, 5]
result = popular(X)
if result != -1:
    print(f"Elemento popular: {result}")
else:
    print("NAO existe elemento popular.")
