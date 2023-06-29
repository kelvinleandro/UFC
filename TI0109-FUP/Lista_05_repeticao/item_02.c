#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, result;
    int canc = 1;
    for (int i = 1; canc == 1; i++){
        printf("Digite um número ou 0 para encerrar: ");
        scanf("%d", &num);
        
        if (i == 1){
            result = num;
        }
        else if (num != 0){
            result = result * num;
        }
        else {
            canc = num;
        }
    }
    
    printf("Resultado = %d", result);
}
