#include <stdio.h>
#define DIM 6

void Le_vetor ( int v[] , int tam );
void Imprime_vetor ( int v[] , int tam );
void Inverte_vetor ( int v[] , int tam );

int main () {
    int v[DIM];
    Le_vetor(v , DIM);
    Imprime_vetor(v , DIM);
    Inverte_vetor(v , DIM);
    Imprime_vetor(v , DIM);
    return 0;
}

void Le_vetor ( int v[] , int tam ) {
    int i ;
    for ( i = 0; i < tam ; i ++) {
        printf (" %d = ? ", i); scanf ("%d", &v[i]) ;
    }
}
    
void Imprime_vetor ( int v[] , int tam ) {
    int i ;
    for ( i = 0; i < tam ; i ++)
        printf (" %d = % d\n", i , v[i]) ;
}

void Inverte_vetor ( int v[] , int tam ) {
    int i , temp ;
    for ( i = 0; i < tam /2; i ++) {
        temp = v[i];
        v[i] = v[tam -i -1];
        v[tam -i -1] = temp ;
    }
}