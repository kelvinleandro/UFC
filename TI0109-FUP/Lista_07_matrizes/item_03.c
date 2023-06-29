#include <stdio.h>

int main(){
    int nums[4][4];

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            printf("Digite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &nums[i][j]);
        }
    }

    printf("Valores da diagonal secundaria: ");
    for (int i = 0; i < 4; i++){
        pritnf(" %d", nums[i][3 - i]);
    }
}