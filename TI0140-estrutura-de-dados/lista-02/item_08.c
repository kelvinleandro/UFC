#include <stdio.h>

int comp(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

void topos_crescente(int arr[], int n){
    int topos[n], quant = 0;
    
    for(int i = 1; i < n-1; i++){
        if((arr[i] > arr[i-1]) && (arr[i] > arr[i+1])){
            topos[quant] = arr[i];
            quant++;
        }
    }

    qsort(topos, quant, sizeof(int), comp);

    for(int i = 0; i < quant; i++){
        printf("%d ", topos[i]);
    }
}

int main(){
    int l[] = {16,19,41,8,42,39,33,22,29,48};
    int n = sizeof(l) / sizeof(int);
    //saida esperada: 41, 42
    topos_crescente(l, n);
}