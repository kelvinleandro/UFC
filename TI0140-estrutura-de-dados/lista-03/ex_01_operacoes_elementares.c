#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 4

void trocar_linhas(int i, int j, float ** M, int n, int m){
// Troca as linhas i e j da matriz M de dimensões n × m
    float aux;
    for(int k = 0; k < m; k++){
        aux = M[i][k];
        M[i][k] = M[j][k];
        M[j][k] = aux;
    }
}

void multiplicar_escalar_linha(int i, float a, float ** M, int n, int m){
// Multiplica a linha i da matriz M de dimensões n × m
    for(int j = 0; j < m; j++){
        M[i][j] = M[i][j] * a;
    }
}

void somar_linhas(int i, int j, float a, float ** M, int n, int m){
// Soma à linha i o produto da linha j por a
// na matriz M de dimensões n × m
    for(int k = 0; k < m; k++){
        M[i][k] +=  M[j][k] * a;
    }
}

void imprime_matriz(int l, int c, float **M){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < c; j++){
            printf("%.0f ", M[i][j]);
        }
        puts("");
    }
}

int main(){
    float l0[] = {1,-2,2,1};
    float l1[] = {2,1,-3,5};
    float l2[] = {4,-7,1,-1};
    
    int n = ROW;
    int m = COL;
    float ** M = malloc(n * sizeof(float *));
    for(int i = 0; i < n ; i ++){
        M[i] = malloc(m * sizeof(float));
    }

    M[0] = l0;
    M[1] = l1;
    M[2] = l2;

    // trocar_linhas(0, 2, M, ROW, COL);
    // multiplicar_escalar_linha(1, 3, M, ROW, COL);
    // somar_linhas(1, 0, 2, M, ROW, COL);
    imprime_matriz(ROW, COL, M);

}