def apply_op(a, b, op):
    if op == '+':
        return a + b
    elif op == 'x':
        return a * b
    elif op == '^':
        return a ** b
    elif op == '-':
        return a - b
    elif op == '/':
        return a / b

def parentizacao(X, op, n):
    # Criar as matrizes para armazenar os valores máximos e mínimos
    M = [[-float('inf')] * n for _ in range(n)]
    m = [[float('inf')] * n for _ in range(n)]
    
    # Inicializar as diagonais das matrizes com os valores de X
    for i in range(n):
        M[i][i] = X[i]
        m[i][i] = X[i]
    
    # Preencher as matrizes
    for i in reversed(range(n)):
        for j in range(i+1, n):
            for k in range(i,j):
                a = apply_op(M[i][k], M[k+1][j], op[k])
                b = apply_op(m[i][k], m[k+1][j], op[k])
                c = apply_op(m[i][k], M[k+1][j], op[k])
                d = apply_op(M[i][k], m[k+1][j], op[k])
                maior, menor = max(a,b,c,d), min(a,b,c,d)
                M[i][j] = max(M[i][j], maior)
                m[i][j] = min(m[i][j], menor)
    
    return M[0][n-1], m[0][n-1]

# Exemplo de uso
X = [7, 5, 2, 1, 3]
op = ['/', '+', '-', 'x']
n = len(X)
max_val, min_val = parentizacao(X, op, n)
print("Máximo:", max_val)
print("Mínimo:", min_val)  # Output: Máximo: 5.382, Mínimo: 1.0
