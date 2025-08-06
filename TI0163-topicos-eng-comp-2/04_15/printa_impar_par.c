#include <stdio.h>

void pares (void) {
    int i ;
    for ( i = 2; i <= 10; i += 2) {
        printf (" %d: ", i);
    }
}

void impares (void) {
    int i ;
    for ( i = 3; i <= 11; i += 2) {
        printf (" %d: ", i);
    }
}

int main (int argc, char *argv[]) {
    pares();
    printf("\n");
    impares();
    return 0;
}