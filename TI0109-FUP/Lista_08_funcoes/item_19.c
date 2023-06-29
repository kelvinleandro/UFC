#include <stdio.h>

void troca_elementos(int n, int vetor[n]){
    int i, aux;

    for(i=0; i < n/2; i++){
        aux = vetor[i];
        vetor[i] = vetor[n-1-i];
        vetor[n-1-i] = aux;
    }
}

int main(){
    int n;
    printf("Quantos elementos tera o vetor: ");
    scanf("%d", &n);
    int vetorA[n];

    printf("Preencha o vetor:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &vetorA[i]);
    }

    troca_elementos(n, vetorA);

    printf("Vetor invertido: \n");
    for(int i = 0; i < n; i++){
        printf("%d", vetorA[i]);
    }

}