#include <stddef.h>
#include "array_utils.h"

int sum_array(const int *arr, int size) {
    if (arr == NULL || size <= 0) return 0;
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int find_max(const int *arr, int size) {
    if (arr == NULL || size <= 0) return 0;
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) max = arr[i];
    }
    return max;
}

int find_min(const int *arr, int size) {
    if (arr == NULL || size <= 0) return 0;
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
    }
    return min;
}
