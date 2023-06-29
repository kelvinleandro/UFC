#include <stdio.h>

void insercao(int arr[], int n){
    int i, key, j;
    for(i = 1; i < n; i++){
        key = arr[i];
        j = i-1;
  
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void ordem3invertida(int arr[], int n){
    insercao(arr, n);
    int j, aux;
    for(int i = 2; i < n; i+=3){
        aux = arr[i];
        arr[i] = arr[i-2];
        arr[i-2] = aux;
    }
}

void imprime_array(int l[], int n){
    for(int i=0; i < n; i++){
        printf("%d ", l[i]);
    }
}

int main(){
    int l[] = {4, 6, 1, 7, 3, 78, 15, 2, 37, 21, 18, 24};
    int n = sizeof(l) / sizeof(int);

    ordem3invertida(l, n);
    imprime_array(l, n);
    // 1 2 3 4 6 7 15 18 21 24 37 78 (ordenada)
    // 3 2 1 7 6 4 21 18 15 78 37 24 (ordem 3 invertida)
}