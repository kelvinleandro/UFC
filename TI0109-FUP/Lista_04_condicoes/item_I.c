#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c, delta, x, x1, x2;
    printf("Digite os valores dos coeficientes A, B e C, respectivamente:\n");
    scanf("%f %f %f", &a, &b, &c);
    
    //calcula o delta
    delta = pow(b, 2) - 4*a*c;

    //verifica se delta = 0
    if (delta == 0) {
        x = (-(b)) / (2*a);
        printf("x = %f", x);
    }
    else {
        //calcula as duas raizes
        x1 = (-(b) + sqrt(delta)) / (2*a);
        x2 = (-(b) - sqrt(delta)) / (2*a);
        printf("x1 = %f\n", x1);
        printf("x2 = %f", x2);
    }
}
