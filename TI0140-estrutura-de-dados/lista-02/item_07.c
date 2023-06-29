#include <stdio.h>

void topos(int arr[], int n){
    for(int i = 1; i < n-1; i++){
        if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1]))
            printf("%d ", arr[i]);
    }
}

int main(){
    int l[] = {16,19,42,8,41,39,33,22,29,48};
    int n = sizeof(l) / sizeof(int);
    //saida esperada: 42, 41
    topos(l, n);
}