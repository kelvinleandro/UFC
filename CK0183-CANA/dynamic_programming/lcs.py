# recursive
def lcs_rec(x, y, i, j):
  if i == 0 or j == 0:
    return 0
  elif x[i - 1] == y[j - 1]:
    return lcs_rec(x, y, i - 1, j - 1) + 1
  else:
    return max(lcs_rec(x, y, i - 1, j), lcs_rec(x, y, i, j - 1))

# memoization
def lcs_memo(x, y):
  m = len(x)
  n = len(y)
  lcs = [[-1] * (n + 1) for _ in range(m + 1)]
  for i in range(m + 1):
    lcs[i][0] = 0
  for j in range(n + 1):
    lcs[0][j] = 0
  return lcs_memo_rec(x, y, m, n, lcs)
  
def lcs_memo_rec(x, y, i, j, lcs):
  if lcs[i][j] >= 0:
    return lcs[i][j]
  
  if x[i - 1] == y[j - 1]:
    lcs[i][j] = lcs_memo_rec(x, y, i - 1, j - 1, lcs) + 1
  else:
    lcs[i][j] = max(lcs_memo_rec(x, y, i - 1, j, lcs), lcs_memo_rec(x, y, i, j - 1, lcs))
  return lcs[i][j]

# dynamic programming
def lcs_dp(x, y):
  m = len(x)
  n = len(y)
  
  lcs = [[0] * (n + 1) for _ in range(m + 1)]
  
  for i in range(1, m + 1):
    for j in range(1, n + 1):
      if x[i - 1] == y[j - 1]:
        lcs[i][j] = lcs[i - 1][j - 1] + 1
      else:
        lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1])
  
  return lcs[m][n]

def lcs_dp_complete(x, y):
  m = len(x)
  n = len(y)
  
  lcs = [[0] * (n + 1) for _ in range(m + 1)]
  R = [[None] * (n + 1) for _ in range(m + 1)]
  for i in range(m + 1):
    R[i][0] = 'up'
  for j in range(n + 1):
    R[0][j] = 'left'
  
  for i in range(1, m + 1):
    for j in range(1, n + 1):
      if x[i - 1] == y[j - 1]:
        lcs[i][j] = lcs[i - 1][j - 1] + 1
        R[i][j] = 'diag'
      elif lcs[i - 1][j] >= lcs[i][j - 1]:
        lcs[i][j] = lcs[i - 1][j]
        R[i][j] = 'up'
      else:
        lcs[i][j] = lcs[i][j - 1]
        R[i][j] = 'left'
  
  return lcs[m][n], R

def print_lcs(x, y, i, j, R):
  if i == 0 or j == 0:
    return
  if R[i][j] == "diag":
    print_lcs(x, y, i - 1, j - 1, R)
    print(x[i - 1], end=' ')
  elif R[i][j] == "left":
    print_lcs(x, y, i, j - 1, R)
  else:  # R[i][j] == "up"
    print_lcs(x, y, i - 1, j, R)

if __name__ == "__main__":
  x = "ABCBDAB"
  y = "BDCAB"
  m = len(x)
  n = len(y)
  print(lcs_rec(x, y, m, n))
  print(lcs_memo(x, y))
  print(lcs_dp(x, y))
  tam, R = lcs_dp_complete(x,y)
  print_lcs(x, y, m, n, R)
