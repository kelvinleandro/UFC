#include <stdio.h>

// Implemente a função 'troca'.
void troca(int *a, int *b){
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

int main(){

    int x = 0, y = 0;

    scanf("%d %d", &x, &y);

    // Chame a função 'troca' para trocar os valores de x e y.
    troca(&x, &y);
    printf("%d %d\n", x, y);
}