# Uma subsequência é palíndroma se ela é igual lendo da direita para esquerda ou lendo da esquerda
# para direita. Por exemplo, a sequência (ACGTGTCAAAATCG) possui muitas subsequências palíndromas,
# como (ACGCA) e (AGTGA). Mas a subsequência (ACT) não é palíndroma. Escreva um algoritmo O(n^2)
# que recebe uma sequência S[1...n] e retorna a subsequência palíndroma de tamanho máximo

def palind_max(S):
    n = len(S)
    
    # Criar uma matriz de zeros p[1...n, 1...n]
    p = [[0] * n for _ in range(n)]

    # Subsequências de comprimento 1 são palíndromas
    for i in range(n):
        p[i][i] = 1

    # Preencher a matriz p
    for i in reversed(range(n)):
        for j in range(i+1,n):
            if S[i] == S[j]:
                p[i][j] = 2 + p[i-1][j-1]
            else:
                p[i][j] = max(p[i-1][j], p[i][j - 1])

    # Reconstruir a subsequência palíndroma de tamanho máximo
    i, j = 0, n - 1
    res = []
    while i <= j:
        if S[i] == S[j]:
            res.append(S[i])
            i += 1
            j -= 1
        elif p[i + 1][j] > p[i][j - 1]:
            i += 1
        else:
            j -= 1

    # Montar a subsequência palíndroma
    palindroma = res + res[::-1]
    if len(palindroma) > len(res) * 2:
        palindroma = res + res[-2::-1]

    return ''.join(palindroma)

# Exemplo de uso
S = "ACGTGTCAAAATCG"
print(palind_max(S))  # Saída: "CTAAAATC" ou "ACGTTGCA"
