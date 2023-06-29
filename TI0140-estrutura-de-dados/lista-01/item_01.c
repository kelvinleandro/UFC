#include <stdio.h>
#define SIZE 10

void ordena_array(int arr[]){
    int impar[SIZE/2], par[SIZE/2];
    int j = 0;
    int k = 0;

    //guarda valores em arrays separados
    for(int i = 0; i < SIZE; i++){
        if (arr[i] % 2 == 0){
            par[j] = arr[i];
            j++;
        }
        else{
            impar[k] = arr[i];
            k++;
        }
    }

    j = 0;
    k = 0;
    //reorganiza o array principal
    for(int i = 0; i < SIZE; i++){
        if(i % 2 == 0){
            arr[i] = par[j];
            j++;
        }
        else{
            arr[i] = impar[k];
            k++;
        }
    }

}

void imprime_array(int arr[]){
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int l[] = {16, 19, 41, 8, 42, 39, 33, 22, 29, 48};
    // l = [16, 19, 8, 41, 42, 39, 22, 33, 48, 29] (saída)
    ordena_array(l);
    imprime_array(l);
}