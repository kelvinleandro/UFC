#include <stdio.h>

int divisores(int n){
    int quant = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0){
            quant++;
        }
    }
    return quant;
}

int main(){
    int n;
    do{
        printf("\nN: ");
        scanf("%d", &n);
        if (n == 0){
            break;
        }
        printf("\nQuantidade de divisores de %d = %d", n, divisores(n));
    } while (n != 0);
}