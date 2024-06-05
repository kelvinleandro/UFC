# Você recebe uma sequência S[1...n] com n dígitos de 0 a 9 e deseja saber se é possível quebrá-la em
# números que sejam quadrados ou cubos perfeitos. Por exemplo, se S = 125271448164, então a resposta é
# SIM, pois S pode ser quebrada da seguinte forma 125, 27, 144, 81, 64, cujos números são quadrados ou cubos
# perfeitos (125 = 5^3, 27 = 3^3, 144 = 12^2, 81 = 9^2, 64 = 8^2). Outra possibilidade seria: 
# 1, 25, 27, 144, 8, 16, 4. Escreva um algoritmo de programação dinâmica que determina se sua sequência S satisfaz 
# ou não esta condição. O tempo do algoritmo deve ser O(n^2), onde iremos assumir que existe um algoritmo que retorna
# em tempo constante se um número qualquer dado é quadrado ou cubo perfeito. Caso a resposta seja SIM,
# faça seu algoritmo escrever a sequência correta de quadrados e/ou cubos perfeitos.

def eh_quadrado_perfeito(num):
    raiz = int(num ** (1/2))
    return raiz * raiz == num

def eh_cubo_perfeito(num):
    raiz = int(num ** (1/3))
    return raiz * raiz * raiz == num

def quebravel(S):
    n = len(S)
    S = ' ' + S  # Para facilitar o índice 1-based

    # Vetor de DP
    q = [0] * (n + 1)
    q[0] = 1

    for k in range(1, n + 1):
        for i in range(k, 0, -1):
            if q[i - 1] == 1:
                numero = int(S[i:k + 1])
                if eh_quadrado_perfeito(numero) or eh_cubo_perfeito(numero):
                    q[k] = 1
                    break

    # Se a sequência não pode ser quebrada, retorne "NÃO"
    if q[n] == 0:
        return "NÃO"

    # Se pode ser quebrada, vamos reconstruir a sequência
    resultado = []
    k = n
    while k > 0:
        for i in range(k, 0, -1):
            if q[i - 1] == 1:
                numero = int(S[i:k + 1])
                if eh_quadrado_perfeito(numero) or eh_cubo_perfeito(numero):
                    resultado.append(numero)
                    k = i - 1
                    break

    resultado.reverse()
    return "SIM", resultado

# Exemplo de uso
S = "125271448164"
resultado = quebravel(S)
print(resultado)
