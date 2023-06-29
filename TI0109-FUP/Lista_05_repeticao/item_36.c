#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n, fat, fatn, fatd;
    float soma = 0, r;
    printf("Digite o valor de N: ");
    scanf("%d", &n);
    
    for (int i = 0; i <= n; i++){
        fatn = 1;
        fatd = 1;
        for (int j = 2; j < i; j++){
            fatn = fatn * j;
        }
        
        for (int j = 2; j <= 2*i; i++){
            fatd = fatd * j;
        }
        
        r = fatn / fatd;
        if (i % 2 == 1) {
            printf("%do termo = %f", i+1 , r);
        }
        else{
            printf("%do termo = -%f", i+1 , r);
            soma -= r;
        }
    }
    
    printf("soma = %f", soma);
}
