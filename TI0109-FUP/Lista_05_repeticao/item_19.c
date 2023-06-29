#include <stdio.h>

int main()
{
    int num;
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    for (int i = 1; i <= num; i++){
        if (num % i == 0){
            printf("%d eh divisor de %d\n", i, num);    
        }
    }
}
