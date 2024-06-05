# recursive
def edit_rec(x, y, i, j):
  if i == 0:
    return j
  elif j == 0:
    return i
  else:
    dif_ij = 0 if x[i - 1] == y[j - 1] else 1
    a = edit_rec(x, y, i - 1, j - 1) + dif_ij
    b = edit_rec(x, y, i, j - 1) + 1
    c = edit_rec(x, y, i - 1, j) + 1
    return min(a, b, c)

# memoization
def edit_memo(x, y):
  m, n = len(x), len(y)
  ed = [[-1] * (n + 1) for _ in range(m + 1)]

  for i in range(m + 1):
    ed[i][0] = i
  for j in range(n + 1):
    ed[0][j] = j

  return edit_memo_rec(x, y, m, n, ed)

def edit_memo_rec(x, y, i, j, ed):
  if ed[i][j] >= 0:
    return ed[i][j]
  
  a = edit_memo_rec(x, y, i - 1, j - 1, ed) + (x[i - 1] != y[j - 1])
  b = edit_memo_rec(x, y, i - 1, j, ed) + 1
  c = edit_memo_rec(x, y, i, j - 1, ed) + 1
  ed[i][j] = min(a, b, c)

  return ed[i][j]

# dynamic programming
def edit_dp(x, y):
  m, n = len(x), len(y)
  ed = [[-1] * (n + 1) for _ in range(m + 1)]

  for i in range(m + 1):
    ed[i][0] = i
  for j in range(n + 1):
    ed[0][j] = j

  for i in range(1, m + 1):
    for j in range(1, n + 1):
      a = ed[i - 1][j] + 1
      b = ed[i][j - 1] + 1
      c = ed[i - 1][j - 1] + (x[i - 1] != y[j - 1])
      ed[i][j] = min(a, b, c)

  return ed[m][n]

def edit_dp_complete(x, y):
  m, n = len(x), len(y)
  ed = [[-1] * (n + 1) for _ in range(m + 1)]
  R = [[None] * (n + 1) for _ in range(m + 1)]

  for i in range(m + 1):
    ed[i][0] = i
    R[i][0] = "up"
  for j in range(n + 1):
    ed[0][j] = j
    R[0][j] = "left"

  for i in range(1, m + 1):
    for j in range(1, n + 1):
      dif_ij = int(x[i - 1] != y[j - 1])
      if ed[i - 1][j - 1] + dif_ij <= 1 + min(ed[i][j-1], ed[i-1][j]):
        ed[i][j] = ed[i - 1][j - 1] + dif_ij
        R[i][j] = "diag"
      elif ed[i][j - 1] <= ed[i - 1][j]:
        ed[i][j] = ed[i][j - 1] + 1
        R[i][j] = "left"
      else:
        ed[i][j] = ed[i - 1][j] + 1
        R[i][j] = "up"

  return ed[m][n], R

def print_opt(x, y, i, j, R):
  if i == 0 and j == 0:
    return
  if R[i][j] == "diag":
    print_opt(x, y, i-1, j-1, R)
    print(f'{x[i-1]} -> {y[j-1]}')
  elif R[i][j] == "left":
    print_opt(x, y, i, j-1, R)
    print(f'_ -> {y[j-1]}')
  elif R[i][j] == "up":
    print_opt(x, y, i-1, j, R)
    print(f'{x[i-1]} -> _')


if __name__ == "__main__":
  x = "sunny"
  y  = "snowy"
  m = len(x)
  n = len(y)
  print(edit_rec(x, y, m, n))
  print(edit_memo(x, y))
  print(edit_dp(x,y))
  ed, R = edit_dp_complete(x,y)
  print(ed)
  print_opt(x, y, m, n, R)
