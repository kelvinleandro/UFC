#include <stdio.h>

int main()
{
    int a, b, c = 1, mdc, resto;
    printf("Digite o valor de A:");
    scanf("%d", &a);
    printf("Digite o valor de B:");
    scanf("%d", &b);
    
    if ((b >= 0) && (b >= 0)){
        while ((c <= a) && (c <= b)){
            if ((a % c == 0) && (b % c == 0)){
                mdc = c;
            }
            c++;
        }
        
        printf("O MDC de %d e %d eh: %d", a, b, mdc);
    }
    else{
        printf("Valores nao podem ser negativo.");
    }
}
