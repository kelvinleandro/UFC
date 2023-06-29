#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c;
    printf("Digite os valores de A, B e C:\n");
    scanf("%f %f %f", &a, &b, &c);

    //verifica se valores formam um triangulo
    if (a < b+c && b < a+c && c < a+b) {
        printf("Os valores podem formar um triangulo.");
    }
    else {
        printf("Os valores nao podem formar um triangulo.");
    }
}
