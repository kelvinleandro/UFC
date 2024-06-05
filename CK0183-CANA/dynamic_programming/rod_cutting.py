# recursive
def rod_rec(p, n):
  if n == 0:
    return 0
  q = float('-inf')
  for i in range(1, n + 1):
    q = max(q, p[i - 1] + rod_rec(p, n - i))
  return q

# memoization
def rod_memo(p,n):
  r = [-1] * (n+1)
  r[0] = 0
  return rod_memo_rec(p,n,r)

def rod_memo_rec(p,n,r):
  if r[n] >= 0:
    return r[n]
  q = float('-inf')
  for i in range(1, n+1):
    q = max(q, p[i - 1] + rod_memo_rec(p, n - i, r))
  r[n] = q
  return r[n]

# dynamic programming
def rod_dp(p,n):
  r = [0] * (n+1)
  for j in range(1, n+1):
    q = float('-inf')
    for i in range(1, j+1):
      q = max(q, p[i - 1] + r[j - i])
    r[j] = q
  return r[n]

def rod_dp_complete(p,n):
  r = [0] * (n+1)
  d = [-1] * (n+1)
  for j in range(1, n+1):
    q = float('-inf')
    for i in range(1, j+1):
      if q < p[i - 1] + r[j - i]:
        q = p[i - 1] + r[j - i]
        d[j] = i
    r[j] = q
  print(rod_list(d,n))
  return r, d

def rod_list(d, n):
  if n == 0 or d[n] == n:
    return []
  else:
    return [d[n]] + rod_list(d, n - d[n])

if __name__ == "__main__":
  p = [1, 5, 8, 9, 10, 17, 17, 20, 24]
  print(rod_rec(p, 4))
  print(rod_memo(p, 4))
  print(rod_dp(p, 4))
  print(rod_dp_complete(p, 4))
