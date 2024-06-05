# Seja X[1...n] um vetor qualquer (os elementos desse vetor não são necessariamente inteiros ou caracteres; 
# podem ser objetos quaisquer, como frutas ou arquivos executáveis). Suponha que você possui apenas um operador = que 
# permite comparar se um objeto é igual a outro. Dizemos que X tem um elemento majoritário x se mais da metade de 
# seus elementos são iguais a x. Escreva um algoritmo de tempo nlogn que diz se X possui ou não um elemento majoritário. 
# Caso sim, devolva o seu valor. Dica: Se x é majoritário em X, então x é majoritário na primeira ou na segunda metade de X.

def find_majority_element(arr):
    def count_elements(element, sub_arr):
        return sub_arr.count(element)

    def find_majority(p, r):
        if p == r:
            return arr[p]

        q = (p + r) // 2
        x1 = find_majority(p, q)
        x2 = find_majority(q + 1, r)

        if x1 == x2:
            return x1
        
        N1 = count_elements(x1, arr[p:r+1])
        N2 = count_elements(x2, arr[p:r+1])

        if N1 > (r - p + 1) // 2:
            return x1
        if N2 > (r - p + 1) // 2:
            return x2

        return -1

    return find_majority(0, len(arr) - 1)

# Example usage
X = [1, 2, 2, 3, 2, 2, 4, 2, 2, 5]
result = find_majority_element(X)
if result != -1:
    print(f"Majority element: {result}")
else:
    print("No majority element found.")
