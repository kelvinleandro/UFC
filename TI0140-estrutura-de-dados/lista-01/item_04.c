#include <stdio.h>
#define SIZE 10

void inverte_array(int arr[]){
    int aux;
    for(int i = 0, j = SIZE-1; i < SIZE/2; i++, j--){
        aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
    }
}

void imprime_array(int arr[]){
    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int l[] = {16, 19, 41, 8, 42, 39, 33, 22, 29, 48};
    // l = [48, 29, 22, 33, 39, 42, 8, 41, 19, 16] (saída)
    inverte_array(l);
    imprime_array(l);
}