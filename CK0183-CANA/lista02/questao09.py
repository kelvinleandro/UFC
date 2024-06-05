# Um aluno de CANA deseja fazer uma festa e está decidindo quem deve chamar. Ele tem n amigos para convidar e 
# tem uma lista dos pares de amigos que se conhecem. Ele quer que ninguém se sinta deslocado, mas também quer que 
# a festa seja interessante e que pessoas que não se conhecem façam amizade. Assim ele se colocou as seguintes restrições: 
# Para cada convidado, devem existir pelo menos dez pessoas na festa que ele conhece e dez pessoas na festa que ele não 
# conhece. Faça um algoritmo que receba uma lista com n pessoas e uma lista com os pares dessas pessoas que se conhecem 
# e devolva o maior número pessoas que poderão ser convidadas sob estas restrições. 

def festa_interessante(n, pares):
    # Cria uma lista de adjacência para representar o grafo
    grafo = [[] for _ in range(n)]
    
    # Preenche a lista de adjacência com os pares fornecidos
    for (a, b) in pares:
        grafo[a].append(b)
        grafo[b].append(a)
    
    # Lista para marcar os nós removidos
    removidos = [False] * n

    while True:
        mudou = False
        # Itera sobre todos os nós do grafo
        for i in range(n):
            if not removidos[i]:
                conhecidos = len(grafo[i]) # Número de amigos que i conhece
                desconhecidos = n - conhecidos - 1 # Número de pessoas que i não conhece
                # Verifica se a pessoa i não satisfaz as restrições
                if conhecidos < 10 or desconhecidos < 10:
                    removidos[i] = True # Marca a pessoa i como removida
                    # Remove i da lista de adjacência de todos os seus amigos
                    for amigo in grafo[i]:
                        grafo[amigo].remove(i)
                    mudou = True
        
        # Se não houve nenhuma remoção na última iteração, quebra o laço
        if not mudou:
            break
    
    # Conta quantas pessoas não foram removidas
    convidados = 0
    for i in range(n):
        if not removidos[i]:
            convidados += 1
    
    return convidados

# Exemplo de uso
n = 20
pares = [(0, 1), (0, 2), (0, 3), (0, 4), (0, 5), (0, 6), (0, 7), (0, 8), (0, 9),
         (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (1, 7), (1, 8), (1, 9), (2, 3),
         (2, 4), (2, 5), (2, 6), (2, 7), (2, 8), (2, 9), (3, 4), (3, 5), (3, 6),
         (3, 7), (3, 8), (3, 9), (4, 5), (4, 6), (4, 7), (4, 8), (4, 9), (5, 6),
         (5, 7), (5, 8), (5, 9), (6, 7), (6, 8), (6, 9), (7, 8), (7, 9), (8, 9)]
print(festa_interessante(n, pares))  # Exemplo de saída
