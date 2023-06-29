#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int num;
    float soma = 0;
    printf("Digite um numero: ");
    scanf("%d", &num);
    
    for(int i= 1; i <= num; i++){
        soma += 1 / (pow(i, i));
    }
    
    printf("Somatorio = %.2f", soma);
}
