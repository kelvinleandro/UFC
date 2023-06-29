#include <stdio.h>
#include <stdlib.h>

int main()
{
    float h, peso_ideal;
    char sexo;
    printf("Digite sua altura: ");
    scanf("%f", &h);
    printf("Sexo[M/F]: ");
    scanf("%s", &sexo);

    //calcula peso ideal
    switch (sexo){
        case 'M':
            peso_ideal = (72.7 * h) - 58;
            printf("Peso ideal para homens: %.1f KG", peso_ideal);
            break;
        case 'F':
            peso_ideal = (62.1 * h) - 44.7;
            printf("Peso ideal para mulheres: %.1f KG", peso_ideal);
            break;
        default:
            printf("Opcao invalida para sexo. Nao sera possivel calcular seu peso ideal.");
            break;
    }

    return 0;
}
