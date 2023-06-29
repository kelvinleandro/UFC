#include <stdio.h>

void find_change(int n, int vetor[n]){
    int i, aux, index;

    for(i=0; i < n; i++){
        if(i == 0){
            index = i;
        }
        else if(vetor[i] > vetor[index]){
            index = i;
        }
    }

    aux = vetor[0];
    vetor[0] = vetor[index];
    vetor[index] = aux;

}

int main(){
    int n, i;
    printf("Quantos elementos tera o vetor: ");
    scanf("%d", &n);
    int vetor[n];

    printf("Preencha o vetor:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }

    puts("");
    for(i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    puts("");

    find_change(n, vetor);
    
    for(i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
}