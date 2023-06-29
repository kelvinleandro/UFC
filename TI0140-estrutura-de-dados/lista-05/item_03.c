#include <stdio.h>

void bolha(int n ,int l[]){
    int aux;
    for(int i = 1; i < n-1; i+=2){
        for(int j = 1; j < n-i-1; j+=2){
            if(l[j] > l[j+2]){
                aux = l[j];
                l[j] = l[j+2];
                l[j+2] = aux;
            }
        }
    }
}

void selecao(int n, int l[]){
    int min_index, aux;
    for(int i=0; i < n-1; i+=2){
        min_index = i;
        for(int j = i+2; j < n; j+=2){
            if(l[j] < l[min_index]){
                min_index = j;
            }
        }

        aux = l[i];
        l[i] = l[min_index];
        l[min_index] = aux;
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

    selecao(n, l);
    bolha(n, l);
    imprime_array(l, n);
    // l = |8| 1 |17| 6 |33| 32 |41| 39 |53| 42 (saida esperada)
}