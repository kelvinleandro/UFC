#include <stdio.h>

int eh_ident(int matriz[10][10], int l, int c){
    int i, j, identidade = 1;

    if(l != c)
        identidade = 0;

    for(i=0; i < l && identidade; i++){
        for(j=0; j < c && identidade; j++){
            if((i == j) && (matriz[i][j] != 1)){
                identidade = 0;
            }
            else if((i != j) && (matriz[i][j] != 0)){
                identidade = 0;
            }
        }
    }

    return identidade;
}

int main(){
    int m, n;
    printf("Quantas linhas tera a matriz: ");
    scanf("%d", &m);
    printf("Quantas colunas tera a matriz: ");
    scanf("%d", &n);
    int matriz[m][n];

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("Valor da posicao %dx%d: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    if(eh_ident(matriz, m, n)){
        printf("A matriz eh uma matriz identidade.\n");
    }
    else{
        printf("Nao eh uma matriz identidade.\n");
    }


    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}