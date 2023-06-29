#include <stdio.h>
#include <string.h>

struct expressao{
    int soma, subtracao;
    float multiplicacao, divisao;
};

int main()
{
    struct expressao test;
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    
    test.soma = num1 + num2;
    test.subtracao = num1 - num2;
    test.divisao = (float) num1 / num2;
    test.multiplicacao = num1 * num2;

    printf("%d %d %.1f %.1f", test.soma, test.subtracao, test.divisao, test.multiplicacao);
    return 0;
}
