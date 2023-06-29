#include <stdio.h>

int main()
{
    int num, q_par = 0, q_impar = 0;
    printf("Digite quantos numeros deseja ler: ");
    scanf("%d", &num);

    for (int i = 1; i <= num; i++){
        if (i % 2 == 0){
            q_par++;
        }
        else {
            q_impar++;
        }
    }
    
    printf("Quantidade de pares = %d\n", q_par);
    printf("Quantidade de impares = %d", q_impar);
}
