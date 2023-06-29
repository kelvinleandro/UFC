#include <stdio.h>

int main()
{
    float num, media, soma;
    int quant;
    printf("Quantos numeros voce deseja ler? ");
    scanf("%d", &quant);
    
    for (int i = 1; i <= quant; i++){
        printf("Digite o %do numero: ", i);
        scanf("%f", &num);
        soma += num;
    }
    
    media = soma / quant;
    
    printf("Media : %.1f", media);
}
