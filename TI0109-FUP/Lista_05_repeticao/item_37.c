#include <stdio.h>

int main()
{
    float altura, maior_h, menor_h, soma_h_turma = 0, soma_h_muie = 0, media_h_turma, media_h_muie;
    int cod_sexo, quant_muie = 0;
    for(int i = 1; i <= 50; i++){
        printf("Digite 1 para masculino ou 2 para feminino: ");
        scanf("%d", &cod_sexo);
        printf("Digite a altura:");
        scanf("%f", &altura);
        
        //armazena valores de maior e menor altura
        if (i == 1){
            maior_h = altura;
            menor_h = altura;
        }
        else {
            if (altura > maior_h){
                maior_h = altura;
            }
            else if (altura < menor_h){
                menor_h = altura;
            }
        }
        
        //faz a soma da altura da turma e das mulheres
        soma_h_turma += altura;
        if (cod_sexo == 2){
            quant_muie++;
            soma_h_muie += altura;
        }
    }
    
    //calcula a media da turma e das mulheres
    media_h_turma = soma_h_turma / 50;
    media_h_muie = soma_h_muie / quant_muie;
    
    //imprime o resultado
    printf("Maior altura = %.2f\n", maior_h);
    printf("Menor altura = %.2f\n", menor_h);
    printf("Media da altura das mulheres = %.2f\n", media_h_muie);
    printf("Media da altura da turma = %.2f", media_h_turma);
}
