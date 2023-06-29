#include <stdio.h>

int main()
{
    int num, a, b, atual;
    printf("Digite quantos termos deseja ver: ");
    scanf("%d", &num);
    printf("Digite o primeiro termo: ");
    scanf("%d", &a);
    printf("Digite o segundo termo: ");
    scanf("%d", &b);
    printf("Serie de Fetuccine: \n");
    printf("%d\n%d\n", a, b);

    for(int i = 3; i <= num; i++){
        if (i % 2 == 0){
            atual = b - a;
        }
        else {
            atual = b + a;
        }
        
        a = b;
        b = atual;
        
        printf("%d\n", atual);
    }
    
}
