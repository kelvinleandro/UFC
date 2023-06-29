#include <stdio.h>

int main()
{
    int a, b, mod, dv = 0;
    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);
    mod = a;
    
    if ((a >= 0) && (b >= 0)){
        while (mod >= b){
            dv++;
            mod -= b;
        }
    }
    else {
        printf("Valores nao podem ser negativos.");
    }
    
    printf("%d / %d = %d", a, b, dv);
}
