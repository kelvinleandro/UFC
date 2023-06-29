#include <stdio.h>

void troca(int n, int vetA[n], int vetB[n]){
    int i, j, aux;

    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if((vetA[i] % 2 == 1) && (vetB[j] % 2 == 0)){
            aux = vetA[i];
            vetA[i] = vetB[j];
            vetB[j] = aux;
            }
        }
        
    }
}

int main(){
    int n, i;
    printf("Digite o valor de n: ", &n);
    scanf("%d", &n);
    int vetA[n], vetB[n];

    printf("Preencha o vetor A com metade pares e impares:\n");
    for(i=0; i < n; i++){
        scanf("%d", &vetA[i]);
    }

    printf("Preencha o vetor B com metade pares e impares:\n");
    for(i=0; i < n; i++){
        scanf("%d", &vetB[i]);
    }

    troca(n, vetA, vetB);

    printf("Vetor A:\n");
    for(i = 0; i < n; i++){
        printf("%d ", vetA[i]);
    }

    printf("\nVetor B:\n");
    for(i = 0; i < n; i++){
        printf("%d ", vetB[i]);
    }
}