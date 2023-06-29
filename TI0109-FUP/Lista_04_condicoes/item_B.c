#include <stdio.h>
#include <stdlib.h>

int main()
{
    float salario, novo_salario;
    printf("Digite seu salario: R$");
    scanf("%f", &salario);

    //verifica se pode reajustar salario
    if (salario < 900) {
        novo_salario = salario * 1.3;
        printf("Salario reajustado: R$%.2f", novo_salario);
    }
    else {
        printf("Voce nao tem direito a reajuste no salario");
    }
}
