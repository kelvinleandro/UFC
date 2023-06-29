#include <stdio.h>
#define SIZE 10

void ordena_array(int arr[]){
    int pos_impar[SIZE/2], pos_par[SIZE/2];
    int j = 0;
    int k = 0;

    //guarda valores em arrays separados
    for(int i = 0; i < SIZE; i++){
        if (i < SIZE/2){
            pos_par[j] = arr[i];
            j++;
        }
        else{
            pos_impar[k] = arr[i];
            k++;
        }
    }

    j = 0;
    k = 0;
    //reorganiza o array principal
    for(int i = 0; i < SIZE; i++){
        if(i % 2 == 0){
            arr[i] = pos_par[j];
            j++;
        }
        else{
            arr[i] = pos_impar[k];
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
    int l[] = {16, 19, 41, 8, 42, 39, 33, 22, 29, 49};
    // l = [16, 39, 19, 33, 41, 22, 8, 29, 42, 49] (saída)
    ordena_array(l);
    imprime_array(l);
}