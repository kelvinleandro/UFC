#include <stdio.h>

int compara(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

void troca(int arr1[], int arr2[], int n){
    int aux;

    qsort(arr1, n, sizeof(int), compara);
    qsort(arr2, n, sizeof(int), compara);

    for(int i = 0; i < n; i++){
        if(arr1[i] > arr2[n-1-i]) return;

        if(arr1[i] < arr2[n-1-i]){
            aux = arr1[i];
            arr1[i] = arr2[n-1-i];
            arr2[n-1-i] = aux;
        }
    }

}

void imprime_array(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int l[] = {16,19,41,8,42,39,33,22,29,48};
    int v[] = {2,5,17,9,35,19,23,72,91,44};
    int n = sizeof(l) / sizeof(int);

    troca(l, v, n);
    imprime_array(l, n);
    puts("");
    imprime_array(v, n);
    // 8 16 19 22 29 33 39 41 42 48 (L ordenado)
    // 2 5 9 17 19 23 35 44 72 91 (V ordenado)
    // L = 91 72 44 35 29 33 39 41 42 48 
    // V = 2 5 9 17 19 23 22 19 16 8
}