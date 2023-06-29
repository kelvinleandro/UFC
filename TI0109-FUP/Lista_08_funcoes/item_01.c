#include <stdio.h>
#include <math.h>

int ehPrimo(int x){
    for(int j = 2; j < (sqrt(x)+1); j++){
        if(x%j==0){
            return 0;
        }
    }
    return 1;
}

int encontrMaiorPrimo(int num){
    for(int i = num-1; i > 1; i--){
        if (ehPrimo(i)){
            return i;
        }
    }
}

int main(){
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);

    if (n <= 0)
        return 0;
    
    int res = encontrMaiorPrimo(n);
    printf("%d", res);
}