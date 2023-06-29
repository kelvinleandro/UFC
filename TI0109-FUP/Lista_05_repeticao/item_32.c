#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float soma = 0, pi;
    
    for(int i= 1; i <= 51 ; i++){
        if (i % 2 == 0){
            soma = soma - (1 / pow((2*i-1), 3));
        }
        else {
            soma = soma + (1 / pow((2*i-1), 3));
        }
    }
    
    pi = pow((soma * 32), (1.0/3));
    
    printf("PI = %f", pi);
}
