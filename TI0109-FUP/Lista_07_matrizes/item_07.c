#include <stdio.h>

int main(){
    int matrizA[3][2], matrizB[2][5], matrizC[3][5];

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            printf("Digite o valor da posicao [%d][%d] da Matriz A: ", i, j);
            scanf("%d", &matrizA[i][j]);
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 5; j++){
            printf("Digite o valor da posicao [%d][%d] da Matriz B: ", i, j);
            scanf("%d", &matrizB[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            matrizC[i][j] = 0;
            for (int k = 0; k < 2; k++) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matrizC[i][j]);
        }
        printf("\n");
    }

}