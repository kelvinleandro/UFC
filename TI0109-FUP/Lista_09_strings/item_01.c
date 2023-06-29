#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void up_low(int n, char nome[n]){
    int i;

    for(i=0; i<n; i++){
        if(islower(nome[i])){
            nome[i] = toupper(nome[i]);
        }
        else if(isupper(nome[i])){
            nome[i] = tolower(nome[i]);
        }
    }
}

int main(){
    char nome[30];

    printf("Digite um nome: ");
    fgets(nome, 30, stdin);
    int tam = strlen(nome);

    up_low(tam, nome);
    printf("\n%s", nome);
}
