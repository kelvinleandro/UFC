#include <stdio.h>

int main(){
    int matriz[3][3],i, j, soma_linha[3], soma_coluna[3], soma_diag = 0, soma_diag_sec = 0, aux=0;

    for (i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("Valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    // soma das linhas
    for (i=0; i<3; i++) {
        for(j=0; j<3; j++){
            aux += matriz[i][j];
        }
        soma_linha[i] = aux;
        aux = 0;
    }

    // soma das linhas
    for (i=0; i<3; i++) {
        for(j=0; j<3; j++){
            aux += matriz[j][i];
        }
        soma_coluna[i] = aux;
        aux = 0;
    }

    // soma das diagonais
    for (i = 0; i < 3; i++){
        soma_diag += matriz[i][i];
        soma_diag_sec += matriz[i][3 - i];
    }

    // compara valores das diagonais
    if(soma_diag != soma_diag_sec){
        printf("A matriz nao eh um cubo magico");
        return 0;
    }

    // compara valores das somas da linhas com colunas
    for(i = 0; i < 3; i++){
        if (soma_linha[i] != soma_coluna[i]){
            printf("A matriz nao eh um cubo magico");
            return 0;
        }
    }

    if (soma_linha[0] != soma_diag){
        printf ("Nao eh quadrado magico!\n");
        return 0;
    }
    printf ("A matriz é um quadrado magico!\n");
    
}