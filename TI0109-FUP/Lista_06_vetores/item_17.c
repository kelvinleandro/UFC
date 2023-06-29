#include <stdio.h>

int main(){
    int n, i, prod = 0;

    printf("Digite quantos elementos tera os vetores: ");
    scanf("%d", &n);
    int vetorX[n], vetorY[n];

    for(i = 0; i < n; i++){
        printf("Digite o %do valor do vetor x: ", i+1);
        scanf("%d", &vetorX[i]);
    }

    for(i = 0; i < n; i++){
        printf("Digite o %do valor do vetor y: ", i+1);
        scanf("%d", &vetorY[i]);
    }

    for (i = 0; i < n; i++){
        prod += vetorX[i] * vetorY[i];
    }
    
    printf("Produto escalar desses vetores: %d", prod);
}