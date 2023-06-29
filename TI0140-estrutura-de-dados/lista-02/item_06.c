#include <stdio.h>

int segundo_maior(int arr[], int n){
    int maior = arr[0], segundo = arr[0], aux;
    for(int i = 0; i < n; i++){
        if(arr[i] > maior){
            aux = arr[i];
            segundo = maior;
            maior = aux;
        }
        else if((arr[i] < maior) && (arr[i] > segundo)){
            segundo = arr[i];
        }
    }

    return segundo;
}

int main(){
    int l[] = {16,19,41,8,42,39,33,22,29,48};
    int n = sizeof(l) / sizeof(int);
    int res = segundo_maior(l, n);
    // saida esperada: 42
    printf("%d", res);
}