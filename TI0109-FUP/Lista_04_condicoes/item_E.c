#include <stdio.h>
#include <stdlib.h>

int main()
{
    int inv_choice;
    float valor;
    printf("Digite um valor: R$");
    scanf("%f", &valor);
    printf("Escolha o tipo de investimento: ");
    printf("1. Poupanca: ");
    printf("2. Fundo de renda fixa. ");
    scanf("%d", &inv_choice);

    switch (inv_choice) {
        case 1:
            printf("Rendimento mensal na poupanca: R$%.2f", valor * 0.1);
            break;
        case 2:
            printf("Rendimento no fundo de renda fixa: R$%.2f", valor * 0.15);
            break;
        default:
            printf("Tipo invalido.");
    }

}
