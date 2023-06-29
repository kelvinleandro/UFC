#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    
    //CALCULA SE E MULTIPLO
    if (n % 3 == 0){
        printf("E multiplo de 3.");
    }
    else {
        printf("Nao e multiplo de 3.");
    }
}
