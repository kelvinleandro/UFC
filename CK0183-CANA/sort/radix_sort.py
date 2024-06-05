def counting_sort_for_radix(arr, exp):
    n = len(arr)
    output_arr = [0] * n
    count_arr = [0] * 10

    for i in range(n):
        index = arr[i] // exp
        count_arr[index % 10] += 1

    for i in range(1, 10):
        count_arr[i] += count_arr[i - 1]

    for i in range(n - 1, -1, -1):
        index = arr[i] // exp
        output_arr[count_arr[index % 10] - 1] = arr[i]
        count_arr[index % 10] -= 1

    for i in range(n):
        arr[i] = output_arr[i]

def radix_sort(arr):
    max_val = max(arr)
    exp = 1
    while max_val // exp > 0:
        counting_sort_for_radix(arr, exp)
        exp *= 10
    return arr
