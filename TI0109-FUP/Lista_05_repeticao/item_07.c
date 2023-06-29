#include <stdio.h>
#include <stdlib.h>

int main()
{
    double veloc_tar, tempo;
    printf("Insira a velocidade da tartaruga: ");
    scanf("%lf", &veloc_tar);
    
    tempo = 100/(9*veloc_tar);
    
    printf("O tempo que o coelho leva pra alcancar a tartaruga, em teoria, eh de: %.2lfs", tempo);
}
