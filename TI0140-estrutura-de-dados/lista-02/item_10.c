#include <stdio.h>

void soma(int arr[], int n, int k){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((j != i) && (arr[i] + arr[j] == k)){
                printf("%d e %d", arr[i], arr[j]);
                return;
            }
        }
    }

    printf("Nao possuem 2 numeros na lista que a soma resultem em %d.", k);

}

int main(){
    int l[] = {16,19,41,8,42,39,33,22,29,48};
    int n = sizeof(l) / sizeof(int);
    int k = 30;
    //saida esperada: 8 e 22
    soma(l, n, k);
}