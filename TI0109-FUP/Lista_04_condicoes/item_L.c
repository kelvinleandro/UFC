#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b;
    printf("Digite o valor A e B, respectivamente:\n");
    scanf("%d %d", &a, &b);

    //CALCULA SE A E DIVISIVEL POR B
    if(a % b == 0){
        printf("O valor A e divisivel por B.");
    }
    else {
        printf("A nao e divisivel por B.");
    }
}
