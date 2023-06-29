#include <stdio.h>

int main()
{
    int num = 0, soma_par = 0, soma_impar = 0, quant_par, quant_impar, maior_par = 0, menor_impar;
    float media_par, media_impar;
    
    while (num >= 0){
        printf("Digite um numero: ");
        scanf("%d", &num);
        
        if (num % 2 == 0){
            soma_par += num;
            quant_par++;
            if (num > maior_par){
                maior_par = num;
            }
        }
        else{
            if (num > 0){
                soma_impar += num;
                quant_impar++;
                if (num < menor_impar){
                    menor_impar = num;
                }
            }
        }
    }
    
    media_par = soma_par / quant_par;
    media_impar = soma_impar / quant_impar;
    
    printf("\nMedia dos valores pares = %.2f\n", media_par);
    printf("Media dos valores impares = %.2f\n", media_impar);
    printf("Maior numero par = %d\n", maior_par);
    printf("Menor numero impar = %d", menor_impar);
}
