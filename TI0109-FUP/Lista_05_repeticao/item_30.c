#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float soma = 1;
    
    for(int i= 1; i < 100; i++){
        if (i % 2 == 0){
            soma = soma - (1 / (i * 2));
        }
        else {
            soma = soma + (1 / (i * 2));
        }
    }
    
    printf("Somatorio = %.2f", soma);
}
