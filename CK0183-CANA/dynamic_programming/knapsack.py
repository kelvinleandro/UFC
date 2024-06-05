# recursive
def knapsack_rec(w, v, n, W):
  if n == 0 or W == 0:
    return 0
  if w[n-1] > W:
    return knapsack_rec(w, v, n-1, W)
  a = knapsack_rec(w, v, n-1, W)
  b = knapsack_rec(w, v, n-1, W - w[n-1]) + v[n-1]
  return max(a, b)

# memoization
def knapsack_memo(w, v, n, W):
  t = [[float('inf')] * (W + 1) for _ in range(n + 1)]
  return knapsack_memo_rec(w, v, n, W, t)

def knapsack_memo_rec(w, v, i, Y, t):
  if t[i][Y] < float('inf'):
    return t[i][Y]
  
  if i == 0 or Y == 0:
    t[i][Y] = 0
  else:
    if w[i - 1] > Y:
      t[i][Y] = knapsack_memo_rec(w, v, i - 1, Y, t)
    else:
      a = knapsack_memo_rec(w, v, i - 1, Y, t)
      b = knapsack_memo_rec(w, v, i - 1, Y - w[i - 1], t) + v[i - 1]
      t[i][Y] = max(a, b)
  return t[i][Y]

# dynamic programming
def knapsack_dp(w, v, n, W):
  t = [[float('inf')] * (W + 1) for _ in range(n + 1)]
  for y in range(W+1):
    t[0][y] = 0 
    for i in range(1, n+1):
      a = t[i-1][y]
      if w[i-1] > y:
        b = 0
      else:
        b = t[i - 1][y - w[i - 1]] + v[i-1]
      t[i][y] = max(a, b)
  return t

def obtain_knapsack(w, n, W, t):
  y = W
  x = [0] * n
  for i in range(n, 0, -1):
    if t[i][y] == t[i - 1][y]:
      x[i - 1] = 0
    else:
      x[i - 1] = 1
      y -= w[i - 1]
  return x

if __name__ == "__main__":
  w = [4, 2, 1, 3]
  v = [500, 400, 300, 450]
  print(knapsack_rec(w, v, 4, 5))
  print(knapsack_memo(w, v, 4, 5))
  t = knapsack_dp(w, v, 4, 5)
  print(t[4][5])
  print(obtain_knapsack(w, 4, 5, t))
