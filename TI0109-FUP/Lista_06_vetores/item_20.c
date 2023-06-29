#include <stdio.h>

int main(){
    int n, i, soma_max = 0, soma_total = -1;

    printf("Insira quantos termos tem a sequencia: ");
    scanf("%d", &n);
    int sequencia[n];

    for (i = 0; i < n; i++){
        printf("Numero %d: ", i+1);
        scanf("%d", &sequencia[i]);
    }

    for(i=0; i < n; i++){
        soma_max += sequencia[i];
        if(soma_max < 0){
            soma_max = 0;
        }

        if(soma_max > soma_total){
            soma_total = soma_max;
        }
    }

    printf("Soma maxima: %d", soma_total);

    return 0;
}
