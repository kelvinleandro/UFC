# Considere vetores que satisfazem a propriedade: o subvetor dos indices [impares esta ordenado crescentemente 
# e o dos indices pares esta ordenado decrescentemente. Exemplo: A = [1 50 2 40 3 30 4 20 5 10]. Faça
# um algoritmo de tempo O(logn) que receba um vetor desse tipo e um inteiro x, e informe se x esta no vetor,
# retornando sua posição, se for o caso.

def buscar_par(arr, p, r, x):
    if p > r:
        return -1
    
    q = (p + r) // 2
    if q % 2 == 1:
        q += 1
    
    if q > r:
        return -1
    
    if arr[q] == x:
        return q
    elif arr[q] < x:
        return buscar_par(arr, q + 2, r, x)
    else:
        return buscar_par(arr, p, q - 2, x)

def buscar_impar(arr, p, r, x):
    if p > r:
        return -1
    
    q = (p + r) // 2
    if q % 2 == 0:
        q += 1
    
    if q > r:
        return -1
    
    if arr[q] == x:
        return q
    elif arr[q] > x:
        return buscar_impar(arr, q + 2, r, x)
    else:
        return buscar_impar(arr, p, q - 2, x)

def modified_binary_search(arr, x):
    result_par = buscar_par(arr, 0, len(arr) - 1, x)
    if result_par != -1:
        return result_par
    
    result_impar = buscar_impar(arr, 0, len(arr) - 1, x)
    return result_impar

# Testando a função com o vetor fornecido
arr = [1, 50, 2, 40, 3, 30, 4, 20, 5, 10]
elements_to_search = [1, 50, 2, 40, 3, 30, 4, 20, 5, 10]

results = {element: modified_binary_search(arr, element) for element in elements_to_search}
print(results)