# considere o algoritmo abaixo. Determine o valor retornado em notação assintótica.

def questao4(n):
  if n <= 1: return 0
  valor = questao4(n//5) + questao4(n//5)
  valor += questao4(n//6) + questao4(n//6) + questao4(n//6)
  valor += questao4(n//10) + n
  return valor

print(questao4(10))