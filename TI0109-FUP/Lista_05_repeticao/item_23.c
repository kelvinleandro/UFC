#include <stdio.h>

int main()
{
    int num, a, b, i, aux, soma;
    printf("Digite o primeiro termo: ");
    scanf("%d", &a);
    printf("Digite o segundo termo: ");
    scanf("%d", &b);
    printf("Digite quantos termos deseja ver: ");
    scanf("%d", &num);
    printf("Serie de Fibonacci: \n");
    printf("%d\n%d\n", a, b);
    soma = a + b;
    
    for(i = 3; i <= num; i++){
        aux = a + b;
        a = b;
        b = aux;
        
        printf("%d\n", aux);
        soma += aux;
    }
    
    printf("Soma dos termos: %d", soma);
}
