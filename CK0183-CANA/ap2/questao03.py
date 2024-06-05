def contiguo(S):
  n = len(S)
  M = [0]*n
  m = [0]*n
  M[0] = m[0] = S[0]

  for i in range(1,n):
    M[i] = max(S[i], S[i]*m[i-1], S[i]*M[i-1])
    m[i] = min(S[i], S[i]*m[i-1], S[i]*M[i-1])

  fim_maior = M.index(max(M))
  fim_menor = m.index(min(m))
  ini_maior = fim_maior
  ini_menor = fim_menor

  prod = 1
  while prod != max(M):
    prod *= S[ini_maior]
    if prod == max(M): break
    ini_maior -= 1

  prod = 1
  while prod != min(m):
    prod *= S[ini_menor]
    if prod == min(m): break
    ini_menor -= 1

  return max(M), min(m), S[ini_maior:fim_maior+1], S[ini_menor:fim_menor+1]

arr = [10, 20, 30, -1, -10, 50]
resultado = contiguo(arr)
print(f'Maior: {resultado[0]}')
print(f'Subsequencia Maior: {resultado[2]}')
print(f'Menor: {resultado[1]}')
print(f'Subsequencia Menor: {resultado[3]}')
