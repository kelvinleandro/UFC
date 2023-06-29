#include <stdio.h>

int le_vetor(int vetor[20], int *quant);

int main(){
    int i, vetA[20], vetB[20], vetC[20], quant_elements[3];
    int vet_auxA[20], vet_auxB[20], vet_auxC[20];

    le_vetor(vet_auxA, &quant_elements[0]);
    le_vetor(vet_auxB, &quant_elements[1]);
    le_vetor(vet_auxC, &quant_elements[2]);

    for(i = 0; i < 20; i++){
        printf("%d, ", vet_auxA[i]);
    }

    printf("\nO vetor possui %d elementos", quant_elements[0]);
}

int le_vetor(int vetor[20], int *quant){
    int i = 0, continua = 1;
    *quant = 1;

    while ((continua == 1) && (i < 20)){
        printf("Digite um valor para a posicao %d do vetor: ", i);
        scanf("%d", &vetor[i]);

        printf("Deseja continuar? [0-nao, 1-sim]: ");
        scanf("%d", &continua);

        if (continua == 1){
            i++;
            *quant++;
        }
    }

}