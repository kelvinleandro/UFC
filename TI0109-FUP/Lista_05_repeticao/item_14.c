#include <stdio.h>

int main()
{
    float a, produto = 0;
    int b;
    printf("Digite o valor de A: ");
    scanf("%f", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);

    for (int i = 1; i <= b; i++){
        produto += a;
    }
    
    printf("%.1f X %d = %.1f\n", a, b, produto);
}
