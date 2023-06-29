#include <stdio.h>

void bolha(int n ,int l[]){
    int aux;
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-i-1; j++){
            if(l[j] > l[j+1]){
                aux = l[j];
                l[j] = l[j+1];
                l[j+1] = aux;
            }
        }
    }
}

void insercao(int n, int l[]){
    int i, key, j;
    for(i = 1; i < n; i++){
        key = l[i];
        j = i-1;
  
        while(j >= 0 && l[j] > key){
            l[j+1] = l[j];
            j--;
        }
        l[j+1] = key;
    }
}

void selecao(int n, int l[]){
    int min_index, aux;
    for(int i=0; i < n-1; i++){
        min_index = i;
        for(int j = i+1; j < n; j++){
            if(l[j] < l[min_index]){
                min_index = j;
            }
        }

        aux = l[i];
        l[i] = l[min_index];
        l[min_index] = aux;
    }
}

void imprime_array(int l[], int n){
    for(int i=0; i < n; i++){
        printf("%d ", l[i]);
    }
}

int main(){
    int l[] = {4, 6, 1, 7, 3, 78, 15, 2, 37, 21, 18};
    int n = sizeof(l) / sizeof(int);

    // bolha(n, l);
    // selecao(n, l);
    // insercao(n, l);
    imprime_array(l, n);
}