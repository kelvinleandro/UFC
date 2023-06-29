#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n,i;

    printf("Quantidade de candidados: ");
    scanf("%d", &n);

    if (n > 5){
        printf("Max de candidatos eh 5.");
        n = 5;
    }

    char candidatos[n][30];
    int votos[n];

    memset(votos, 0, sizeof(int)*n);
    getchar();
    for(i=0; i < n; i++){
        printf("Digite o nome do candidato %d: ", i+1);
        fgets(candidatos[i], sizeof(char)*30, stdin);
    }

    char voto[30] = "naofim";
    printf("Digite o nome do candidato ou fim p/ finalizar: ");
    fgets(voto, 30, stdin);

    while(strcmp(voto, "fim\n")){
        int escolhido = 0;
        for(escolhido=0; escolhido < n && strcmp(voto, candidatos[escolhido]); escolhido++);
        if(escolhido >= n){
            printf("Candidato nao existe\n");
        }
        else{
            printf("Voto computado no candidato %s", candidatos[escolhido]);
            votos[escolhido]++;
        }
        printf("Digite o nome do candidato ou 'fim' para finalizar: ");
        fgets(voto, 30, stdin);
    }

    for(i=0; i < n; i++){
        printf("Candidato: %s Votos: %d\n\n", candidatos[i], votos[i]);
    }

    return 0;
}