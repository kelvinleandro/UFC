#include <stdio.h>
#include "externo.h"

extern int gContador;

int main(void){
    imprime_contador();

    gContador += 15;

    printf("Contador atualizado = %d\n", gContador);
    imprime_contador();

    modifica_contador(5);
    printf("Contador atualizado 2 = %d\n", gContador);
    imprime_contador();
    return 0;
}