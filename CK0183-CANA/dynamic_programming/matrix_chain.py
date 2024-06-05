# recursive
def matrix_chain_rec(p, i, j):
  if i == j:
    return 0
  m_ij = float('inf')
  for k in range(i, j):
    q1 = matrix_chain_rec(p, i, k)
    q2 = matrix_chain_rec(p, k+1, j)
    q = q1 + p[i]*p[k+1]*p[j+1] + q2
    if q < m_ij:
      m_ij = q
  return m_ij

# memoization
def matrix_chain_memo(p, n):
  m = [[float('inf')] * n for _ in range(n)]
  return lookup_chain(m, p, 0, n-1)

def lookup_chain(m, p, i, j):
  if m[i][j] < float('inf'):
    return m[i][j]
  if i == j:
    m[i][j] = 0
  else:
    for k in range(i, j):
      q = (lookup_chain(m, p, i, k) +
           lookup_chain(m, p, k+1, j) +
           p[i]*p[k+1]*p[j+1])
      if q < m[i][j]:
        m[i][j] = q
  return m[i][j]


# dynamic programming
def matrix_chain_dp(p, n):
  m = [[None] * n for _ in range(n)]
  for i in range(n):
    m[i][i] = 0

  for i in reversed(range(n)):
    for j in range(i+1, n):
      m[i][j] = float('inf')
      for k in range(i, j):
        q = m[i][k] + p[i]*p[k+1]*p[j+1] + m[k+1][j]
        if q < m[i][j]:
          m[i][j] = q
  return m


if __name__ == "__main__":
  p = [10, 10, 20, 30, 10, 15, 30]
  n = len(p) - 1
  print(matrix_chain_rec(p, 0, n-1))
  print(matrix_chain_memo(p, n))
  m = matrix_chain_dp(p, n)
  for row in m:
    print(row)
