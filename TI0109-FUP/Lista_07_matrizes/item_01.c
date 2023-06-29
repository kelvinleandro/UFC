#include <stdio.h>

int main(){
    int m[6][3], i, j, menor, maior;

    for(i = 0; i < 6; i++){
        for(j = 0; j < 3; j++){
            printf("\nDigite o elemento da Matriz da linha %d e coluna %d: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }

    menor = m[0][0];
    for (i = 0; i < 6; i++){
        for (j = 0; j < 3; j++){
            if (m[i][j] < menor){
                menor = m[i][j];
            }
        }
    }

    maior = m[0][0];
    for (i = 0; i < 6; i++){
        for (j = 0; j < 3; j++){
            if (m[i][j] > maior){
                maior = m[i][j];
            }
        }
    }

    printf("Menor elemento: %d\n", menor);
    printf("Maior elemento: %d", maior);
}