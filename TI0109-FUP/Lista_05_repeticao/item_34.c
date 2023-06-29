#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int fat;
    float coss = 0, x;
    printf("Digite o valor de X: ");
    scanf("%f", &x);
    
    for(int i= 1; i <= 15 ; i++){
        fat = 1;
        for(int j = 2; j <= 2*i - 2; j++){
            fat = fat * j;
        }
        
        if (i % 2 == 0){
            coss = coss - (pow(x, (2*i-2)) / fat);
        }
        else {
            coss = coss + (pow(x, (2*i-2)) / fat);
        }
    }
    
    printf("COS(%.1f) = %.2f", x, coss);
}
