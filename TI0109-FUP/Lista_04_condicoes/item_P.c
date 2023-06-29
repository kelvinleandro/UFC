#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float a, b, c, alfa, beta;
    printf("Digite os valores de A, B e C em ordem crescente:\n");
    scanf("%f %f %f", &a, &b, &c);
    //verifica se forma um triangulo
    if (a < b+c && b < a+c && c < a+b) {
        if(a*a + b*b == c*c){
            alfa = 180*asinf(a/c)/M_PI;
            beta = 180*asinf(b/c)/M_PI;

            printf("Alfa = %f graus.\n", alfa);
            printf("Beta = %f graus.", beta);
        }
        else {
            printf("Triangulo nao e retangulo.");
        }
    }
    else {
        printf("Os valores nao podem formar um triangulo.");
    }
}
