#include <stdio.h>
#include <string.h>

void ordena(char* string){
    int i, j, quant = strlen(string);
    char temp;

    for(i=0; i < quant-1; i++){
        for(j= i+1; j < quant; j++){
            if(string[i] > string[j]){
                temp = string[i];
                string[i] = string[j];
                string[j] = temp;
            }
        }
    }

}

void eh_anagrama(char* palavra1, char* palavra2){

    if(strlen(palavra1) != strlen(palavra2)){
        printf("Strings possuem tamanhos diferentes. Nao sao anagramas.");
        exit(0);
    }

    ordena(palavra1);
    ordena(palavra2);

    if(strcmp(palavra1, palavra2)){
        printf("Sao anagramas");
    }
    else{
        printf("Nao sao anagramas");
    }
}

int main(){
    char palavra1[30], palavra2[30];

    printf("Digite a primeira palavra: ");
    fgets(palavra1, 30, stdin);
    printf("Digite a segunda palavra: ");
    fgets(palavra2, 30, stdin);

    eh_anagrama(palavra1, palavra2);
}