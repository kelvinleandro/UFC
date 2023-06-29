#include <stdio.h>

void repetido(int arr[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((j != i) && (arr[i] == arr[j])){
                printf("%d", arr[i]);
                return;
            }
        }
    }
}

int main(){
    int l[] = {16,19,22,8,42,39,33,22,29,48};
    int n = sizeof(l) / sizeof(int);  
    // saida esperada: 22
    repetido(l, n);
}