#include <stdio.h>

int main(){
    struct dados{
        float salario;
        int idade;
        int sexo;
        int filhos;
    } pessoas[5];

    int i, quant_muie = 0, muie_rica = 0;
    float media_salario = 0, media_filhos = 0, maior_salario, perc_muie_rica;

    for(i=0; i < 5; i++){
        printf("Salario da pessoa %d: ", i);
        scanf("%f", &pessoas[i].salario);
        printf("Idade da pessoa %d: ", i);
        scanf("%d", &pessoas[i].idade);
        printf("Sexo da pessoa %d [0 - masc; 1 - fem.]: ", i);
        scanf("%d", &pessoas[i].sexo);
        printf("Quantidade de filhos da pessoa da pessoa %d: ", i);
        scanf("%d", &pessoas[i].filhos);
        
        puts("");
    }

    for(i=0; i < 5; i++){
        media_salario += pessoas[i].salario;
        media_filhos += pessoas[i].filhos;

        if(i == 0){
            maior_salario = pessoas[i].salario;
        }
        else if(pessoas[i].salario > maior_salario){
            maior_salario = pessoas[i].salario;
        }

        if(pessoas[i].sexo == 1){
            quant_muie++;
            if(pessoas[i].salario > 10000){
                muie_rica++;
            }
        }
    }

    media_salario /= 5;
    media_filhos /= 5;
    perc_muie_rica = (muie_rica / quant_muie) * 100;

    printf("Media de salario da populacao: R$%.2f\n", media_salario);
    printf("Media do numero de filhos: %.1f\n", media_filhos);
    printf("Maior salario: R$%.2f\n", maior_salario);
    printf("Porcentagem de mulheres que ganham acima de R$10.000: %.2f%%\n", perc_muie_rica);
}