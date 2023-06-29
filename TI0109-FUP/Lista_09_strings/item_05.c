#include <stdio.h>
#include <string.h>

void exclui(int quant, char nome[quant], char letra){
    int i = 0;

    while(i < quant){
        if(nome[i] == letra){
            if(i < (quant - 1)){
                for(int j = i; j < (quant - 1); j++){
                    nome[j] = nome[j + 1];
                }
            }
            quant--;
        }
        else{
            i++;
        }
    }

    printf("Palavra sem a letra %c: %s", letra, nome);
}

int main(){
    char nome[30], letra;
    printf("Digite um nome: ");
    fgets(nome, 30, stdin);
    int quant = sizeof(nome);
    printf("Digite a letra que deseja remover: ");
    scanf("%c", &letra);

    exclui(quant, nome, letra);
}
