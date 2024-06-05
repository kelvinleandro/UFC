# recursive
def fibo_rec(n):
  if n <= 1:
    return n
  return fibo_rec(n-1) + fibo_rec(n-2)

# memoization
def memoized_fibo(n):
  f = [-1]*(n+1)
  return lookup_fibo(f,n)

def lookup_fibo(f,n):
  if f[n] >= 0:
    return f[n]

  if n <= 1:
    f[n] = n
  else:
    f[n] = lookup_fibo(f, n-1) + lookup_fibo(f, n-2)

  return f[n]

# dynamic programming
def dp_fibo(n):
  if n == 0:
    return 0
  prev = 0
  current = 1
  for _ in range(2,n+1):
    next = current + prev
    prev = current
    current = next
  return current


if __name__ == "__main__":
  print(fibo_rec(5))
  print(memoized_fibo(5))
  print(dp_fibo(5))
