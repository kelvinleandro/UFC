# Solução recursiva
def P_REC(n):
    if n <= 10:
        return 0
    return 7*n +sum(P_REC(n//2 + k) for k in range(0,6))

# Solução com programação dinâmica
def P_PD(n):
    p = [0] * (n + 1)
    for i in range(11, n + 1):
        p[i] = 7*i + sum(p[i//2 + k] for k in range(0,6))
    return p[n]

# Solução com memoização
def P_MEMO(n):
    p = [-1] * (n + 1)
    for i in range(11):
        p[i] = 0
    return P_MEMO_REC(n, p)

def P_MEMO_REC(n, p):
    if p[n] >= 0:
        return p[n]
    p[n] = 7*n + sum(P_MEMO_REC(n//2 + k, p) for k in range(0,6))
    return p[n]

# Teste
print(P_REC(100))
print(P_PD(100))
print(P_MEMO(100))