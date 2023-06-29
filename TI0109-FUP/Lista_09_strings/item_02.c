#include <stdio.h>
#include <string.h>

void palindromo(char* nome){
    int i, n = strlen(nome)-2, res = 1;

    for(i=0; i < n; i++){
        if(nome[i] != nome[n-i]){
            res = 0;
            break;
        }
    }

    if(res == 0){
        printf("Nao eh palindromo");
    }
    else{
        printf("Eh palindromo");
    }

}

int main(){
    char nome[30];

    printf("Digite um nome: ");
    fgets(nome, 29, stdin);

    palindromo(nome);
}