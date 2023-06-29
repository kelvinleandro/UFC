#include <stdio.h>

int main(){
    int n, i, j, simetr = 1;
    printf("Digite o valor da ordem da matriz NxN: ");
    scanf("%d", &n);
    int matriz[n][n], matriz_transp[n][n];

    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Matriz: \n");
    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            matriz_transp[j][i] = matriz[i][j];
        }
    }

    printf("Matriz Transposta: \n");
    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", matriz_transp[i][j]);
        }
        printf("\n");
    }
    
    for (i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(matriz[i][j] != matriz_transp[i][j]){
                simetr = 0;
                break;
            }
        }
    }

    if (simetr == 1){
        printf("As matrizes sao simetricas.");
    }
    else{
        printf("As matrizes nao sao simetricas");
    }
    
}