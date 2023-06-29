#include <stdio.h>

int main()
{
    int num, a = 0, b = 1, i, aux;
    printf("Digite um numero: ");
    scanf("%d", &num);
    printf("Serie de Fibonacci: \n");
    printf("%d\n", b);
    
    for(i = 2; i <= num; i++){
        aux = a + b;
        a = b;
        b = aux;
        
        printf("%d\n", aux);
    }

}
