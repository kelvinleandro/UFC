#include <stdio.h>

void merge(int arr[], int arr2[], int n){
    int i=0, j = n/2, k=0;
    while (k < n){
        if((i < n/2) && (arr[i] < arr[j])){
            arr2[k] = arr[i];
            i++;
            k++;
        }
        else if(j < n){
            arr2[k] = arr[j];
            j++;
            k++;
        }
    }
}

void bolha(int l[], int ini, int fim){
    int aux;
    for(int i = 0; i < fim-1; i++){
        for(int j = ini; j < fim-i-1; j++){
            if(l[j] > l[j+1]){
                aux = l[j];
                l[j] = l[j+1];
                l[j+1] = aux;
            }
        }
    }
}

void imprime_array(int arr[], int n){
    for(int i=0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int l[] = {17, 32, 41, 42, 8, 39, 33, 1, 53, 6};
    int n = sizeof(l) / sizeof(int);
    int r[n];

    bolha(l, 0, n/2);
    bolha(l, n/2, n);
    merge(l, r, n);
    imprime_array(l, n);
    printf("\n");
    imprime_array(r, n);
    // l = 8 17 32 41 42 | 1 6 33 39 53 (bubble sort nas duas metades)
    // r = 1 6 8 17 32 33 39 41 42 53 (saida esperada)
}