# Voce recebe uma sequencia S[1...n] com n dgitos de 0 a 9 e deseja saber se e possível
# quebra-la em EXATAMENTE SEIS numeros primos. Por exemplo, se S = 23571113, entao a resposta
# é SIM, pois S pode ser quebrada da seguinte forma 2,3,5,7,11,13, que contem exatamente seis numeros
# primos. O seguinte modo 23,571,113 contem apenas numeros primos, mas não é válido, pois não tem seis
# numeros. Escreva uma algoritmo de programacao dinamica que determina se sua sequencia S satisfaz ou
# nao esta condicao. A complexidade deve ser no maximo O(n^2).

def is_prime(n):
    if n <= 1: return False
    for i in range(2,n):
        if (n%i) == 0:
            return False
    return True

def divide_em_primos(S, n):
    # Inicializa a matriz com zeros
    m = [[0] * 7 for _ in range(n + 1)]
    primos = [[[] for _ in range(7)] for _ in range(n+1)]
    m[0][0] = 1 # uma sequência vazia pode ser dividida em zero números primos

    for i in range(1, n + 1):
        for j in range(1, 7):
            for k in range(i):
                if m[k][j - 1] == 1 and is_prime(int(S[k:i])):
                    m[i][j] = 1
                    primos[i][j] = primos[k][j-1] + [int(S[k:i])]
                    break
    if m[n][6] == 1:
        return True, primos[n][6]
    return False, []

S = "23571113"
n = len(S)
print(divide_em_primos(S,n))