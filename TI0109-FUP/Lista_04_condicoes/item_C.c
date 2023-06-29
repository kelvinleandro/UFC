#include <stdio.h>
#include <stdlib.h>

int main()
{
    float saldo, credito;
    printf("Digite o saldo: ");
    scanf("%f", &saldo);

    //calcula credito
    if (saldo > 400){
        credito = saldo * 0.3;
    }
    else if (saldo <= 400 && saldo > 300) {
        credito = saldo * 0.25;
    }
    else if (saldo <= 300 && saldo > 200) {
        credito = saldo * 0.20;
    }
    else {
        credito = saldo * 0.10;
    }

    //imprime o resultado
    printf("Valor do saldo medio: R$%.2f\n", saldo);
    printf("Valor do credito: R$%.2f", credito);
}
