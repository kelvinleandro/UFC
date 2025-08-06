#include <stdio.h>

float Eleva ( float a , int b ) {
    float res = 1.0;
    for ( ; b >0; b --) res *= a;
    return res ;
}

int main () {
    float numero ;
    int potencia ;
    puts (" Entre com um numero ");
    scanf ("%f ", &numero);
    puts (" Entre com a potencia ");
    scanf ("%d ", &potencia) ;
    printf ("%f Elevado a %d e igual a %f\n ",
    numero , potencia , Eleva ( numero , potencia ));
    return 0;
}