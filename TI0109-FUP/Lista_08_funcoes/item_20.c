#include <stdio.h>

void exclui(int quant, int v[], int numero){
    int i = 0;
 
    while(i < quant){
        if(v[i] == numero){
            if(i < (quant - 1)){
                for(int j = i; j < (quant - 1); j++){
                    v[j] = v[j + 1];
                }
            }
            quant--;
        }
        else{
            i++;
        }
    }
 
    printf("Vetor sem o elemento %d: ", numero);  
    for(i = 0; i < quant; i++){
        printf("%d ", v[i]);
    }
}

int main(){
    int quant;
    printf("Quantos elementos tera o vetor: ");
    scanf("%d", &quant);
    int vetor[quant];

    printf("Preencha o vetor:\n");
    for(int i = 0; i < quant; i++){
        scanf("%d", &vetor[i]);
    }

    exclui(quant, vetor, 5);
}