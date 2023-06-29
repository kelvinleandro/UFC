#include <stdio.h>

int main(){
    int quant_merc[5];
    float preco_merc[5], faturamento = 0;
    for(int i = 0; i < 5; i++){
        printf("Indique a quantidade de vendas da mercadoria %d: ", i+1);
        scanf("%d", &quant_merc[i]);
    }

    for(int i = 0; i < 5; i++){
        printf("Indique o preco da mercadoria %d: ", i+1);
        scanf("%f", &preco_merc[i]);
    }

    for(int i = 0; i< 5; i++){
        faturamento += quant_merc[i] * preco_merc[i];
    }

    printf("\nFaturamento mensal : R$%.2f", faturamento);
}
