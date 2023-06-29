#include <stdio.h>
#include <stdlib.h>

int main()
{
    float peso;
    int idade, grupo;
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    printf("Digite seu peso: ");
    scanf("%f", &peso);

    // calcula o grupo caso idade seja menor que 20
    if (idade < 20) {
        if (peso <= 60) {
            grupo = 9;
        }
        else if (peso > 60 && peso <= 90) {
            grupo = 8;
        }
        else {
            grupo = 7;
        }
    }
    //calcula grupo caso idade esteja entre 20 e 50
    else if (idade >= 20 && idade <= 50) {
        if (peso <= 60) {
            grupo = 6;
        }
        else if (peso > 60 && peso <= 90) {
            grupo = 5;
        }
        else {
            grupo = 4;
        }
    }
    //calcula grupo caso idade seja maior que 50
    else {
        if (peso <= 60) {
            grupo = 3;
        }
        else if (peso > 60 && peso <= 90) {
            grupo = 2;
        }
        else {
            grupo = 1;
        }
    }

    //mostra resultado
    printf("Voce faz parte do grupo de risco %d", grupo);
}
