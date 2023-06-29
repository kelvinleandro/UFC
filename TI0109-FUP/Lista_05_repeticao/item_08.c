#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int i, erros = 0, erro_semana = 0;
    
    for(i= 0; i < 13; i++){
        erro_semana = pow(2, i);
        printf("total de erros na semana %d eh de %d\n", i+1, erro_semana);
        erros += erro_semana;
    }
    
    printf("\nO total de erros, em teoria, que serao cometidos pelo aluno e de: %d", erros);
}
