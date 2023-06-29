#include <stdio.h>

int main(){
    int i, j, mes = 3, semana = 4;
    int vendas[mes][semana], soma=0, soma_mes, soma_semana;

    for(i = 0; i < mes; i++){
        for(j = 0; j < semana; j++){
            printf("Quantidade de vendas do mes %d na semana %d: ", i+1, j+1);
            scanf("%d", &vendas[i][j]);
        }
    }

    for(i=0; i<mes; i++){
        for(j=0; j<semana; j++){
            printf("%d ", vendas[i][j]);
        }
        printf("\n");
    }

    // vendas em cada mes
    for(i=0; i<mes; i++){
        soma_mes = 0;
        for(j=0; j<semana; j++){
            soma_mes += vendas[i][j];
        }
        printf("\nTotal de vendas no mes %d: %d", i+1, soma_mes);
    }
    printf("\n");

    // vendas em cada semana
    for(i=0; i<semana; i++){
        soma_semana = 0;
        for(j=0; j<mes; j++){
            soma_semana += vendas[j][i];
        }
        printf("\nTotal de vendas na semana %d: %d", i+1, soma_semana);
    }
    printf("\n");

    // vendas no ano
    for(i=0; i<mes; i++){
        for(j=0; j<semana; j++){
            soma += vendas[i][j];
        }
    }
    printf("\nTotal de vendas no ano: %d", soma);

}