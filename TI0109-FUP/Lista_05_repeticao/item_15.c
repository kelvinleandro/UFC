#include <stdio.h>

int main()
{
    float a, result = 0;
    int b;
    printf("Digite o valor de A: ");
    scanf("%f", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);

    if (b >= 0){
        for (int i = 0; i <= b; i++){
            if (i == 0){
                result = 1;
            }
            else if (i == 1) {
                result = a;
            }
            else{
                result = result * a;
            }
        }
    }
    else {
        printf("Indice B nao pode ser negativo.");
    }
    printf("%.1f ** %d = %.1f\n", a, b, result);
}
