# Você recebe n números reais positivos X = (x1, x2, ..., xn) e uma sequência de n-1 operadores op = (op1, ..., opn-1) 
# em {+, x, ^}, onde + significa soma, x significa multiplicação e ^ significa exponenciação. Essas sequências de 
# números e operadores representam uma expressão matemática. Por exemplo, se X = (0.3, 1, 4, 0.7, 0.2) e a sequência 
# de operadores é (+, x, +, x), então temos a expressão: 0.3 + 1 x 4 + 0.7 x 0.2. Desejamos colocar parêntesis na 
# expressão de modo que o resultado final seja o mínimo possivel. Também desejamos colocar parêntesis na expressão 
# de modo que o resultado final seja o máximo possivel. Por exemplo, o máximo e o mínimo do exemplo são respectivamente 
# (0.3 + 1) x (4 + (0.7 x 0.2)) = 5.382 e (0.3 + (1 x 4) + 0.7) x 0.2 = 1. Escreva um algoritmo de programação dinâmica 
# que obtém o modo de colocar parêntesis para obter o valor máximo e o modo de colocar parêntesis para obter o valor 
# mínimo. A complexidade deve ser no máximo O(n^3)

def apply_op(a, b, op):
    if op == '+':
        return a + b
    elif op == 'x':
        return a * b
    elif op == '^':
        return a ** b

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
                M[i][j] = max(M[i][j], a)
                m[i][j] = min(m[i][j], b)
    
    return M[0][n-1], m[0][n-1]

# Exemplo de uso
X = [0.3, 1, 4, 0.7, 0.2]
op = ['+', 'x', '+', 'x']
n = len(X)
max_val, min_val = parentizacao(X, op, n)
print("Máximo:", max_val)
print("Mínimo:", min_val)  # Output: Máximo: 5.382, Mínimo: 1.0
