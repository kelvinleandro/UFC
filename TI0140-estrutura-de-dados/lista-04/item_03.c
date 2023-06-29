#include <stdio.h>

void inserir(int arr[], int n, int *tam, int num){
    int aux;
    if(tam >= n) return;

    int i = 0;
    for(; i < (int*)tam && arr[i] < num; i++){}
    if(i == tam){
        arr[(int*)tam] = num;
        tam++;
        return;
    };
    int hold = arr[i];
    arr[i] = num;
    i++;
    for(; i < tam+1; i++){
        aux = hold;
        hold = arr[i];
        arr[i] = aux;
    }
    tam++;
}

void remover(int arr[], int n, int *tam, int num){
    int aux;
    if(tam == n) return;

    int i = 0;
    for(; i < (int*)tam && arr[i] != num; i++){}
    if(i >= tam) return;
    arr[i] = 0;
    for(; i < tam-1; i++){
        aux = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = aux;
    }
    tam--;
}

void imprime_array(int arr[], int n){
    for(int i=0; i < n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int n = 9;
    int tam = n;
    // int* arr = (int*) malloc(m*sizeof(int*));
    // for(int i = 0; i < n; i++){
    //     arr[i] = (i+1)*2;
    // }
    int arr[20] = {1,5,9,10,12,13,15,19,22};

    int num = 3;
    // printf("O que deseja fazer: \n1 - Inserir elemento \n2 - Remover elemento\n");
    // scanf("%d", &op);
    // if(op == 1){
    //     printf("Digite o numero que deseja inserir: ");
    //     scanf("%d", &num);
    //     inserir(arr, num, &tam);
    // }
    // else if(op == 2){
    //     printf("Digite o numero que deseja remover da lista: ");
    //     scanf("%d");
    //     remover(arr, num, &tam);

    // }

    inserir(arr, n, &tam, num);
    imprime_array(arr, tam);
}