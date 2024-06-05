# Seja P: N -> N uma funçãao definida da seguinte forma: 
# P(0) = P(1) = P(2) = P(3) = P(4) = 0 e P(n) = P(n//2) + P(n//2 + 1) + P(n//2 + 2) + n, para todo n >= 5
# Escreva um algoritmo recursivo puro que recebe um número n como entrada e retorna o valor exato de
# P(n). Calcule a complexidade do seu algoritmo. Escreva agora um algoritmo de programação dinâmica
# para o mesmo problema e calcule a complexidade. Escreva também um algoritmo de memoização e calcule a complexidade.

# 1.a - Solução recursiva
def P_REC(n):
    if n <= 4:
        return 0
    return P_REC(n // 2) + P_REC(n // 2 + 1) + P_REC(n // 2 + 2) + n

# 1.b - Solução com programação dinâmica
def P_PD(n):
    p = [0] * (n + 1)
    for i in range(5, n + 1):
        p[i] = p[i // 2] + p[i // 2 + 1] + p[i // 2 + 2] + i
    return p[n]

# 1.c - Solução com memoização
def P_MEMO(n):
    p = [-1] * (n + 1)
    for i in range(5):
        p[i] = 0
    return P_MEMO_REC(n, p)

def P_MEMO_REC(n, p):
    if p[n] >= 0:
        return p[n]
    a = P_MEMO_REC(n // 2, p)
    b = P_MEMO_REC(n // 2 + 1, p)
    c = P_MEMO_REC(n // 2 + 2, p)
    p[n] = a + b + c + n
    return p[n]

# Teste
print(P_REC(10))
print(P_PD(10))
print(P_MEMO(10))
