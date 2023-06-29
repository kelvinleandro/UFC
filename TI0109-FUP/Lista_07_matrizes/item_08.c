#include <stdio.h>

int main(){
    double matriz[3][3], determinante;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("Digite o valor da posicao [%d][%d] da Matriz : ", i, j);
            scanf("%lf", &matriz[i][j]);
        }
    }

    determinante = matriz[0][0] * ((matriz[1][1]*matriz[2][2]) - (matriz[2][1]*matriz[1][2])) -matriz[0][1] * (matriz[1][0] * matriz[2][2] - matriz[2][0] * matriz[1][2]) + matriz[0][2] * (matriz[1][0] * matriz[2][1] - matriz[2][0] * matriz[1][1]);
    printf("A determinante eh: %.1flf", determinante);

}