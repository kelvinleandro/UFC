#include <stdio.h>
#include <math.h>

int main(){
    int num_cod, num_descod = 0;
    int val_codif[9] = {7,8,9,1,2,3,4,5,6}; //valores relacionado a codificacao
    printf("Digite o numero codificado: \n");
    scanf("%d", &num_cod);
    int quant_digits = floor(log10(num_cod)) + 1;
    int cont = quant_digits - 1;
    int vet_descod[quant_digits];

    // transforma cada digito em elemento de um array
    while (num_cod > 0){
        vet_descod[cont] = val_codif[(num_cod % 10) - 1];
        num_cod = num_cod / 10;
        cont--;
    }

    // transforma cada elemento do vetor em um unico numero
    for(int i = 0; i < quant_digits; i++){
        num_descod = vet_descod[i] + (num_descod * 10);
    }

    // mostra o valor codificado e decodificado
    printf("\nCifrada: %d", num_cod);
    printf("\nNormal: %d", num_descod);

}
