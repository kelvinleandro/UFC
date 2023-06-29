#include <stdio.h>

void split(int arr[], int n){
    int pivot = arr[n/2];
    int index_pivot = n/2;
    int aux;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j != index_pivot){
                if((j < index_pivot) && (arr[j] > pivot)){
                    arr[index_pivot] = arr[j];
                    arr[j] = pivot;
                    index_pivot = j;
                }
                else if((j > index_pivot) && (arr[j]) < pivot){
                    arr[index_pivot] = arr[j];
                    arr[j] = pivot;
                    index_pivot = j;
                }
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
    int l[] = {48, 29, 22, 33, 39, 42, 8, 41, 19, 16};
    int n = sizeof(l) / sizeof(int);
    // 8 29 22 33 19 16 39 42 48 41 (saida esperada)

    split(l, n);
    imprime_array(l, n);
}