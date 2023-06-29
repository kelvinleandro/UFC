#include <stdio.h>

int main(){
    int dias;
    printf("Digite a quantidade de dias: ");
    scanf("%d", &dias);
    float temps[dias], soma_temperatura = 0, media_temp, menor_temp, maior_temp, dias_inferior = 0;

    for(int i = 0; i < dias; i++){
        printf("Digite a temperatura: ");
        scanf("%f", &temps[i]);
        soma_temperatura += temps[i];
    }

    media_temp = soma_temperatura / dias;

    for(int i = 0; i < dias; i++){
        if(i == 0){
            menor_temp = temps[i];
            maior_temp = temps[i];
        }
        else{
            if (temps[i] > maior_temp){
                maior_temp = temps[i];
            }
            else if (temps[i] < menor_temp){
                menor_temp = temps[i];
            }
        }
    }

    for(int i = 0; i < dias; i++){
        if(temps[i] < media_temp){
            dias_inferior++;
        }
    }

    printf("Menor temperatura: %.2f\n", menor_temp);
    printf("Maior temperatura: %.2f\n", maior_temp);
    printf("Temperatura media: %.2f\n", media_temp);
    printf("Quantidade de dias inferior a media: %.2f", dias_inferior);
}