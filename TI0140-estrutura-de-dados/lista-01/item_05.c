#include <stdio.h>
#define SIZE 10

void rotaciona_array(int arr[], int n){
    int aux;
    int last = arr[n-1];
    for(int i = n-1; i > 0; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = last;
}

void imprime_array(int arr[]){
    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int l[] = {16, 39, 10, 50, 0, 0, 0, 0, 0, 0};
    // l = [50, 16, 39, 10, 0, 0, 0, 0, 0, 0, 0] (saída)
    int n = 4;
    rotaciona_array(l, n);
    imprime_array(l);
}