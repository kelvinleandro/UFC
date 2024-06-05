# Escreva um algoritmo eficiente que receba como entrada um conjunto de variáveis x1, ..., xn e dois conjuntos I e D 
# de pares (xi, xj) de variáveis. Os pares (xi, xj) em I representam restrições de igualdade xi = xj e os pares (xa, xb) 
# em D representam restrições de desigualdade xa != xb. Seu algoritmo deve responder se é possível ou não satisfazer 
# todas as restrições em I e em D. Por exemplo, a seguinte entrada não é satisfatível: 
# I = {(x1, x2),(x2, x3),(x3, x4)} e D = {(x1, x4)}.

def union_find(n, I, D):
    parent = [i for i in range(n+1)]
    rank = [0]*(n+1)

    def find(x):
        if parent[x] != x:
            parent[x] = find(parent[x])  # Compressão de caminho
        return parent[x]

    def union(x, y):
        rootX = find(x)
        rootY = find(y)
        if rootX != rootY:
            if rank[rootX] > rank[rootY]:
                parent[rootY] = rootX
            elif rank[rootX] < rank[rootY]:
                parent[rootX] = rootY
            else:
                parent[rootY] = rootX
                rank[rootX] += 1

    # Processar as restrições de igualdade
    for (x_i, x_j) in I:
        union(x_i, x_j)

    # Verificar as restrições de desigualdade
    for (x_a, x_b) in D:
        if find(x_a) == find(x_b):
            return False

    return True

# Exemplo de uso
n = 4
I = [(1, 2), (2, 3), (3, 4)]
D = [(1, 4)]
print(union_find(n, I, D))  # Output: False, pois não é possível satisfazer todas as restrições
