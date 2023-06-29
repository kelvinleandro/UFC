#include <stdio.h>

int inversao(int arr[], int n){
    int i = 0, j = n-1, aux;
    int quant = 0;
    while((i < j) && (arr[i] > arr[j])){
        aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
        quant++;
        i++;
        j--;
    }

    return quant;
}

void imprime_array(int arr[], int n){
    for(int i=0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int l[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(l) / sizeof(int);
    int res = inversao(l, n);

    // 1 2 3 4 5 6 7 8 9 10
    // quant de inversoes = 5 (saida esperada)
    printf("%d \n", res);
    imprime_array(l, n);
}