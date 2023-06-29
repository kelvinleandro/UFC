#include <stdio.h>
#include <stdlib.h>

int main()
{
    float preco, novo_preco;
    char classificacao;
    printf("Digite um preco: R$");
    scanf("%f", &preco);

    //calcula novo preco de acordo com percentual de aumento
    if (preco <= 50) {
        novo_preco = preco * 1.05;
    }
    else if (preco > 50 && preco <= 100) {
        novo_preco = preco * 1.1;
    }
    else {
        novo_preco = preco * 1.15;
    }

    //classifica o novo preco
    if (novo_preco <= 80) {
        classificacao = 'D';
    }
    else if (novo_preco > 80 && novo_preco <= 120) {
        classificacao = 'C';
    }
    else if (novo_preco > 120 && novo_preco <= 200) {
        classificacao = 'B';
    }
    else {
        classificacao = 'A';
    }

    //imprime o resultado
    printf("Novo preco: R$%.2f\n", novo_preco);
    printf("Classificacao: %c", classificacao);
}
