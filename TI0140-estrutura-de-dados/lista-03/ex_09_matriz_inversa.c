#include <stdio.h>
 
int main(){
    int mat[3][3], i, j;
    float determinant = 0;
    printf("Digite os elementos da matriz:\n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
           scanf("%d", &mat[i][j]);
        }
    }

    printf("\nA matriz eh:");
    for(i = 0; i < 3; i++){
        printf("\n");
        for(j = 0; j < 3; j++){
            printf("%d\t", mat[i][j]);
        }
    }
    // encontrando a determinante
    for(i = 0; i < 3; i++){
        determinant = determinant + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));
    }

    printf("\n\nDeterminante: %f\n", determinant);
    
    // calculando a matriz inversa
    printf("\nMatriz Inversa: \n");
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            printf("%.1f\t",((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ determinant);
        }
    printf("\n");
    }
 
   return 0;
}