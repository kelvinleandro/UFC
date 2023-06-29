#include <stdio.h>

int main()
{
    int a, b, result;
    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);
    result = a;
    
    if ((a >= 0) && (b >= 0)){
        while (result >= b){
            result -= b;
        }
    }
    else {
        printf("Valores nao podem ser negativos.");
    }
    
    printf("%d %% %d = %d", a, b, result);
}
