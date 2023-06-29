#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c, angulo;
    printf("Digite os valores de A, B e C em ordem crescente:\n");
    scanf("%f %f %f", &a, &b, &c);

    angulo = (a*a + b*b - c*c)/(2*a*b);

    //verifica se forma um triangulo
    if (a < b+c && b < a+c && c < a+b) {
        printf("Triangulo existe.\n");
        if (angulo > 0) {
            printf("Triangulo existe e e acutangulo.");
        }
        else if (angulo == 0){
            printf("Triangulo existe e e retangulo.");
        }
        else if (angulo < 0){
            printf("Triangulo existe e e obtusangulo.");
        }
    }
    else {
        printf("Os valores nao podem formar um triangulo.");
    }
}
