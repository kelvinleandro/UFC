#include <stdio.h>

int main()
{
    int n1, n2, n_min, n_max, soma=0;
    printf("Digite dois numeros: ");
    scanf("%d %d", &n1, &n2);
    if (n1 > n2){
        n_max = n1;
        n_min = n2;
    }
    else {
        n_max = n2;
        n_min = n1;
    }
    
    for (int i = n_min; i <= n_max; i++){
        if (i % 2 == 0){
            printf("%d eh par\n", i);
            soma += i;
        }
    }
    
    printf("Soma dos pares = %d", soma);
}
