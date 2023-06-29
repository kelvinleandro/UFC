#include <stdio.h>

void print_vet(int vet[], int size){
    printf("[");
    for(int i = 0; i < size; i++){
        if(i == size-1){
            printf("%d", vet[i]);
        }
        else{
            printf("%d, ", vet[i]);
        }
    }
    printf("]\n");
}

int main(){
    int qtd = 0;
    int aux = 0;
    scanf("%d", &qtd);
    while(aux < qtd){
        int size = 0;
        scanf("%d", &size);
        int vet[size];
        for(int i = 0; i < size; i++)
            scanf("%d", &vet[i]);
        print_vet(vet, size);
        aux++;
    }
}