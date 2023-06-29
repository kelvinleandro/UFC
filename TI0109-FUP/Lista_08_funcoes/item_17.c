#include <stdio.h>

void localiza_letra(char vetor[], int n, char c){
    int i;
    for(i=0; i < n; i++){
        if(vetor[i] == c){
            printf("[%d]", i-1);
        }
    }
}

int main(){
    int n, i;
    printf("Quantos elementos tera o vetor? ");
    scanf("%d", &n);
    char vetor[n];

    printf("Preencha o vetor: ");
    for(i = 0; i < n; i++){
        scanf("%c", &vetor[i]);
    }

    localiza_letra(vetor, n, 'a');
}