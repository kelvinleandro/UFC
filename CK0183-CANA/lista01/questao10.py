# Sejam X[1...n] e Y[1...n] dois vetores ordenados. Escreva um algoritmo O(logn) para encontrar a mediana de todos
# os 2n elementos nos vetores X e Y.

def questao10(v1, v2, p1, r1, p2, r2):
    if (r1 - p1 <= 1) and (r2 - p2 <= 1):
        n = (r1 - p1 + 1) + (r2 - p2 + 1)
        aux = [0] * n
        j = 0
        for i in range(p1, r1 + 1):
            aux[j] = v1[i]
            j += 1
        for i in range(p2, r2 + 1):
            aux[j] = v2[i]
            j += 1
        aux.sort()  # Using Python's built-in sorting function
        med = aux[n // 2]
        return med

    q1 = (p1 + r1) // 2
    q2 = (p2 + r2) // 2
    med1 = v1[q1]
    med2 = v2[q2]

    if med1 == med2:
        return med1
    elif med1 < med2:
        return questao10(v1, v2, q1, r1, p2, q2)
    else:
        return questao10(v1, v2, p1, q1, q2, r2)

def find_median_sorted_arrays(X, Y):
    # Merge the two sorted arrays into a single sorted array
    combined = sorted(X + Y)
    n = len(combined)
    
    # Calculate the median index
    mid = n // 2
    
    # If the total number of elements is even, average the middle two elements
    if n % 2 == 0:
        return (combined[mid - 1] + combined[mid]) / 2
    else:
        return combined[mid]

# Example usage:
X = [1, 3, 5]
Y = [2, 4]
result = questao10(X, Y, 0, len(X) - 1, 0, len(Y) - 1)
print(f"Median: {result}")
result = find_median_sorted_arrays(X, Y)
print(f"Median: {result}")
