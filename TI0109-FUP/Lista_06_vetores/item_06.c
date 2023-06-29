#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double fat(double m){
        double fatorial = 1, j;
        for(j = m; j> 0; j--){
            fatorial = fatorial *j;
        }
        return fatorial;
    }

    double X, x, n, seno = 0;
    double sequenc[15];
    int i;

    printf("Insira o valor do angulo em graus para o calculo do seno: ");
    scanf("%lf", &X);

    x = (X * M_PI)/180;

    for(i = 0; i < 15; i++){
        seno = seno + pow(-1, i)*pow(x, 1+2*i)/fat(1 + 2*i);
        sequenc[i] = seno;
    }
    
    for(i = 0; i < 15; i++){
        printf("%lf\n", sequenc[i]);
    }
}
