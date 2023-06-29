#include <stdio.h>

void troca_var(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int main(){
    int x = 1, y = 2;
    printf("Antes da troca: X=%d e Y=%d", x, y);
    troca_var(&x, &y);
    printf("\nDepois da troca: X=%d e Y=%d", x, y);
}