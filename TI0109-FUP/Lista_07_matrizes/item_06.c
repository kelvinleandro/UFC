#include <stdio.h>

int main(){
    int nums[3][5], soma;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 5; j++){
            printf("Digite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &nums[i][j]);
        }
    }

    for (int i = 0; i < 3; i++){
        soma = 0;
        for (int j = 0; j < 5; j++){
            soma += nums[i][j];
        }
        for (int k = 0; k < 5; k++){
            printf(" %d", soma);
        }
        printf("\n");
    }
}