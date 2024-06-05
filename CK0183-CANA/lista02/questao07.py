# Considere um conjunto de livros numerados de 1 a n. Suponha que o livro i tem peso pi e que 0 < pi < 1 para cada i. 
# Problema: Dado n e os números p1, ..., pn, acondicionar os livros no menor número possível de envelopes de modo que 
# cada envelope tenha no máximo 2 livros e o peso do conteúdo de cada envelope seja no máximo 1. 
# Escreva um algoritmo eficiente que resolva esse problema.

def agrupar_livros(n, p):
    # Ordena a lista de pesos
    p.sort()
    
    i = 0
    j = n - 1
    n_envelopes = 0

    while i <= j:
        if i != j and p[i] + p[j] <= 1:
            print(f'({i+1}, {j+1})')  # Imprime os índices (ajustando para 1 baseado)
            i += 1
            j -= 1
        else:
            print(f'({j+1})')  # Imprime o índice (ajustando para 1 baseado)
            j -= 1
        n_envelopes += 1

    return n_envelopes

# Exemplo de uso
pesos = [0.3, 0.5, 0.8, 0.4, 0.2, 1]
n = len(pesos)
total_envelopes = agrupar_livros(n, pesos)
print(f'Total de envelopes: {total_envelopes}')  # Output esperado depende dos pares formados
