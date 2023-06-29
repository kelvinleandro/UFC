#include <stdio.h>
#include <stdlib.h>
#define ROW 3
#define COL 4

void zerar_posicao_acima(int i, int j, float ** M, int n, int m){
// Zera a posição M[i][j] da matriz M , onde i < j
    for(int k = 0; k < m; k++){
        M[i][k] -= (M[i][j]/M[j][k])*M[j][j];
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

    zerar_posicao_acima(0, 1, M, ROW, COL);
    imprime_matriz(ROW, COL, M);

}