#include <stdio.h>
#include <math.h>

int main(){
    float px, py, dist;
    int n, i, j;

    printf("Digite a coordenada x do ponto: ");
    scanf("%f", &px);

    printf("Digite a coordenada y do ponto: ");
    scanf("%f", &py);

    printf("Digite o valor n: ");
    scanf("%d", &n);
    float coor_x[n], coor_y[n], raios[n];
    
    for (i = 0; i < n; i++){
        printf("Valor de x%d: ", i+1);
        scanf("%f", &coor_x[i]);
        printf("Valor de y%d: ", i+1);
        scanf("%f", &coor_y[i]);
    }
    for (i = 0; i < n; i++){
        float r; 
        int repetido = 0;
        r = sqrt(pow(px - coor_x[i], 2) + pow(py - coor_y[i], 2));
        raios[i] = r;

        for(j=0; j<i ; j++){
            if(r == raios[j]){
                repetido=1;
            }
        }

        if(repetido==0){
            printf("%f\n", r);
        }
    }
}