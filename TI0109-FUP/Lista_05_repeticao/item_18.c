#include <stdio.h>

int main()
{
    int a, b, i=2, primo = 1;
    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);
    
    if ((a >= 0) && (b >= 0)){
        while (i <= b) {
            if (b % i == 0) {
                if (a % i == 0) {
                    primo = 0;
                }
            }
            i++;
        }
        if (primo == 1){
            printf("%d e %d sao primos entre si.", a, b);
        }
        else {
            printf("%d e %d nao sao primos entre si.", a, b);
        }
    }
    else {
        printf("Valores nao podem ser negativos.");
    }
    
}
