#include <stdio.h>

int main(){
    int n, x[10], p, xexp;
    
    printf("Indique o valor de n: ");
    scanf("%d", &n);
    int coefs[n];
    
    for(int i = 0; i <= n; i++){
        printf("Digite o coeficiente a%d", i);
        scanf("%d", &coefs[i]);
    }

    for (int i = 0; i < 10; i++){
        printf("Digite um valor para X: ");
        scanf("%d", &x[i]);
    }

    for (int i = 0; i < 10; i++){
        p = coefs[0];
        for(int j = 0; i < n; j++){
            xexp = 1;
            for (int k = 0; k < j; k++){
                xexp *= x[i];
            }
        }

        printf("A soma P de x%d eh %d", i, p);
    }
}