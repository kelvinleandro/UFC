# Faça um algoritmo de tempo nlogn para resolver o seguinte problema: dado um vetor com n números inteiros positivos 
# e um outro número inteiro positivo x, determine se existem ou não dois elementos cuja soma é igual a x.

def binary_search(arr, key):
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1

def soma_2(arr, x):
    n = len(arr)
    arr.sort()
    for i in range(n):
        complement = x - arr[i]
        q = binary_search(arr, complement)
        if q >= 0 and q != i:
            return arr[i], arr[q]
    return None

# Exemplo de uso
X = [1, 6, 4, 2, 5, 3]
x = 9
result = soma_2(X, x)
if result:
    print(f"Existem os elementos: {result[0]} + {result[1]} = {x}")
else:
    print(f"NAO existem elementos com soma = {x}")
