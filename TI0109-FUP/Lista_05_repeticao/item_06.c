#include <stdio.h>

int main()
{
    int fat, num;
    printf("Digite um valor para calcular o fatorial: ");
    scanf("%d", &num);
    
    for(fat = 1; num > 1; num = num - 1){
        fat = fat * num;
    }
    
    printf("Valor do fatorial = %d", fat);
}
