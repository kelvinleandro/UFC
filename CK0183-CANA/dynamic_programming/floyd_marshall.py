# recursive
def allshortest_rec(w, i, j, k):
  if i == j:
    return 0
  if k == 0:
    return w[i][j]
  a = allshortest_rec(w, i, j, k - 1)
  b = allshortest_rec(w, i, k, k - 1)
  c = allshortest_rec(w, k, j, k - 1)
  return min(a, b, c)

# memoization
def allshortest_memo(w, n):
  d = [[[float('inf')] * n for _ in range(n)] for _ in range(n)]
  for i in range(n):
    for j in range(n):
      dist = allshortest_memo_rec(w, i, j, n, d)
      print(f'd_{i}_{j} = {dist}')

def allshortest_memo_rec(w, i, j, k, d):
  if d[k][i][j] < float('inf'):
    return d[k][i][j]
  if i == j:
    return 0
  if k == 0:
    return w[i][j]
  
  a = allshortest_memo_rec(w, i, j, k-1, d)
  b = allshortest_memo_rec(w, i, k, k-1, d)
  c = allshortest_memo_rec(w, k, j, k-1, d)
  
  d[k][i][j] = min(a, b + c)
  return d[k][i][j]

# dynamic programming
def floyd_marshall(w, n):
  d = [[None] * n for _ in range(n)]
  for i in range(n):
    for j in range(n):
      d[i][j] = w[i][j]

  for k in range(n):
    for i in range(n):
      for j in range(n):
        if d[i][j] > d[i][k] + d[k][j]:
          d[i][j] = d[i][k] + d[k][j]
  return d

if __name__ == "__main__":
  pass