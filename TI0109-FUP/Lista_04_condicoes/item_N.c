#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a, b, c;
    printf("Digite os valores de A, B e C:\n");
    scanf("%f %f %f", &a, &b, &c);

    //verifica se forma um triangulo
    if (a < b+c && b < a+c && c < a+b) {
        //verifica qual o tipo de triangulo
        if (a == b && b == c){
            printf("Triangulo equilatero");
        }
        else if (a != b && a !=c && b != c){
            printf("Triangulo escaleno");
        }
        else {
            printf("Triangulo isosceles");
        }
    }
    else {
        printf("Os valores nao podem formar um triangulo.");
    }
}
