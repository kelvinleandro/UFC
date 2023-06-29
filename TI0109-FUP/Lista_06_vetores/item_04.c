#include <stdio.h>

int main(){
    float altura[10], soma_altura = 0, media_altura;
    for (int i = 0; i < 10; i++){
        printf("Digite a altura: ");
        scanf("%f", &altura[i]);
        soma_altura += altura[i];
    }

    media_altura = soma_altura / 10;

    for (int i = 0; i < 10; i++){
        if (altura[i] > media_altura){
            printf("%.2f\n", altura[i]);
        }
    }
}