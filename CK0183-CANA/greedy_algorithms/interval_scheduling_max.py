def ism(s, f, n):
  # Sort s and f based on the ending times such that f[1] <= f[2] <= ... <= f[n]
  intervals = sorted(zip(s, f), key=lambda x: x[1])
  s = [interval[0] for interval in intervals]
  f = [interval[1] for interval in intervals]

  # Initialize the maximum set of disjoint intervals
  A = [1] # A contains the indices of the selected intervals
  i = 0 # i keeps track of the last added interval index

  # Iterate over the intervals
  for j in range(1, n):
    if s[j] >= f[i]: # Check if the start time of the current interval is greater than or equal to the end time of the last added interval
      A.append(j + 1) # Add the index of the current interval to A
      i = j # Update i to the current interval index

  return A

# Example usage
s = [1, 2, 3, 0, 5, 8] # Start times of the intervals
f = [2, 4, 6, 7, 9, 9] # End times of the intervals
n = len(s)
result = ism(s, f, n)
print("Maximum set of disjoint intervals:", result)
