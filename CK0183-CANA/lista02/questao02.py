# Uma subsequência contígua de uma sequência S é uma subsequência de elementos consecutivos de S. 
# Por exemplo, se S = (5 15 -30 10 -5 40 10), então (15 -30 10) é uma subsequência contígua de S, mas (5 15 40) não é.
# Escreva um algoritmo linear para a seguinte tarefa: receba como entrada uma sequência de números (a1, a2, ..., an) 
# e devolva a subsequência contígua cuja soma é máxima (uma subsequência de tamanho zero tem soma zero).
# No exemplo anterior, a resposta seria a subsequência (10 -5 40 10) cuja soma é 55. 
# (Dica: Para cada j ∈ {1, 2, . . . , n}, considere subsequências contíguas terminando exatamente na posição j).

def contiguo(S):
    n = len(S)
    
    if n == 0:
        return []

    # Criar vetor s e inicializar
    s = [0] * n
    s[0] = S[0]
    indice_maior = 0
    
    # Variáveis para rastrear a posição inicial e final da subsequência máxima
    inicio_seq = 0
    fim_seq = 0
    inicio_temp = 0

    for i in range(1, n):
        if S[i] > S[i] + s[i - 1]:
            s[i] = S[i]
            inicio_temp = i
        else:
            s[i] = S[i] + s[i - 1]
        
        if s[i] > s[indice_maior]:
            indice_maior = i
            inicio_seq = inicio_temp
            fim_seq = i
    
    # Retornar a subsequência contígua de soma máxima
    return S[inicio_seq: fim_seq + 1]

# Exemplo de uso
S = [5, 15, -30, 10, -5, 40, 10]
print(contiguo(S))  # Saída: [10, -5, 40, 10]
