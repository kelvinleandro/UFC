#include <stdio.h>

int gContador = 10;

void imprime_contador(void) {
    printf("contador = %d\n", gContador);
}

void modifica_contador(int novo) {
    gContador = novo;
}