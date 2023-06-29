#include <stdio.h>
#define SIZE 10

void ordena_array(int arr[]){
    int aux;

    for(int i = 0, j= SIZE - 1; i < SIZE/2; i++, j--){
        if ((i % 2 != 0) && (j % 2 == 0)){
            aux = arr[i];
            arr[i] = arr[j];
            arr[j] = aux;
        }
    }

}

void imprime_array(int arr[]){
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int l[] = {16, 19, 41, 8, 42, 39, 33, 22, 29, 49};
    // l = [16, 39, 41, 33, 42, 22, 8, 29, 19, 49] (saída)
    ordena_array(l);
    imprime_array(l);
}
