#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n1, n2, choice;
    float result;
    printf("Digite dois numeros: \n");
    scanf("%d %d", &n1, &n2);
    printf("Escolha a operacao que deseja fazer(1 a 4):\n ");
    printf("1: MEDIA ENTRE NUMEROS DIGITADOS.\n ");
    printf("2: DIFERENCA DO MAIOR PELO MENOR.\n ");
    printf("3: PRODUTO ENTRE NUMEROS DIGITADOS.\n ");
    printf("4: DIVISAO DO PRIMEIRO PELO SEGUNDO NUMERO.\n ");
    scanf("%d", &choice);

    //analisa a operacao que deseja fazer
    switch (choice){
        case 1:
            result = ((float)(n1 + n2) / 2);
            break;
        case 2:\
            //verifica qual o maior numero
            if (n1 > n2) {
                result =  n1 - n2;
            }
            else {
                result = n2 - n1;
            }
            break;
        case 3:
            result = n1 * n2;
            break;
        case 4:
            //verifica se o denominador e igual a zero.
            if (n2 == 0) {
                printf("O denominador nao pode ser 0. \n");
                return 0;
            }
            else {
                result = ((float)n1/n2);
            }
            break;
        default:
            printf("Opcao invalida. \n");
            return 0;
    }

    printf("Resultado = %f", result);
}
