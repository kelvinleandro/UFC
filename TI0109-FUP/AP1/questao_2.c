#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, i, result = 0, feliz = 1;

    printf("Quantos numeros deseja ler: ");
    scanf("%d", &n);

    if(n < 1){
        return 0;
    }

    int sequencia[n];

    for(i=0; i < n; i++){
        printf("Digite o %do numero: ", i+1);
        scanf("%d", &sequencia[i]);
    }

    for(i = n-1; i > 0; i--){
        result = abs(sequencia[i] - sequencia[i-1]);

        if(result >= n){
            feliz = 0;
            break;
        }
    }

    if(feliz){
        printf("Feliz");
    }
    else{
        printf("Nao feliz");
    }
}
