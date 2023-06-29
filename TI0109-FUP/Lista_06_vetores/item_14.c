#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(){
    float altura[3], aux_h;
    int i, j, sexo[3], aux_sexo;
    char nomes[3][40];

    for(i = 0; i < 3; i++){
        printf("Digite a altura da pessoa %d:", i);
        scanf("%f", &altura[i]);
        printf("Digite o sexo da pessoa %d: [1- mascul. 2 - femin.] ", i);
        scanf("%d", &sexo[i]);
    }

    for(i = 0; i < 3; i++){
        for(j = i+1; j < 3; j++){
            if (altura[i] > altura[j]){
                aux_h = altura[i];
                altura[i] = altura[j];
                altura[j] = aux_h;

                aux_sexo = sexo[i];
                sexo[i] = sexo[j];
                sexo[j] = aux_sexo;
            }
        }
    }

    for(i=0; i < 3; i++){
        printf("\nDigite o nome da pessoa de altura %.2fm e de sexo %d: ", altura[i], sexo[i]);
        scanf("%s", &nomes[i]);
    }

    for(i=0; i < 3; i++){
        printf("\n%s possui %.2fm e eh do sexo %d", nomes[i], altura[i], sexo[i]);
    }

    return 0;
}
