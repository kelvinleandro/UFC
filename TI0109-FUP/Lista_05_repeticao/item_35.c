#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int fat;
    float x, ex = 0;
    printf("Digite o valor de X: ");
    scanf("%f", &x);
    
    for (int i = 1; i <= 15; i++){
        fat = 1;
        for (int j = 2; j < i; j++){
            fat = fat * j;
        }
        
        ex = ex + (pow(x, i-1)) / fat;
    }
    
    printf("E^%.1f = %f", x, ex);
}
