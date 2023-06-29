#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, maior;
    int canc = 1;
    for (int i = 1; canc == 1; i++){
        printf("Digite um número ou 0 para encerrar: ");
        scanf("%d", &num);
        
        if (i == 1){
            maior = num;
        }
        else if (num > maior){
            maior = num;
        }
        else {
            canc = num;
        }
    }
    
    printf("Maior = %d", maior);
}