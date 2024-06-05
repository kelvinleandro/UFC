# Escreva um algoritmo O(nT) que recebe um inteiro positivo T e uma lista com n inteiros positivos 
# (a1, a2, ..., an) e decide se existe algum subconjunto desses inteiros cuja soma é igual a T. 
# (Dica: Observe subconjuntos (a1, a2, . . . , ak) e verifique se a soma é s onde 1 <= k <= n e 1 <= s <= T).

def soma_t(lista, n, T):
    # Criar uma matriz de zeros de tamanho (n+1) x (T+1)
    V = [[0] * (T + 1) for _ in range(n + 1)]

    # Preencher a matriz
    for i in range(1, n + 1):
        for s in range(1, T + 1):
            V[i][s] = V[i - 1][s]
            if lista[i - 1] <= s and lista[i - 1] + V[i - 1][s - lista[i - 1]] > V[i][s]:
                V[i][s] = lista[i - 1] + V[i - 1][s - lista[i - 1]]

    # Verificar se a soma T foi encontrada
    if any(V[i][T] == T for i in range(n + 1)):
        return "SIM"
    else:
        return "NÃO"

# Exemplo de uso
lista = [3, 34, 4, 12, 5, 2]
T = 9
n = len(lista)
print(soma_t(lista, n, T))  # Output: SIM
