#include <stdio.h>
#include <string.h>

void imprime_sufs(char* palavra){
    if(*palavra){
        imprime_sufs(palavra+1);
        printf("%s", palavra);
    }
}

int main(){
    char palavra[15];

    printf("Digite uma palavra: ");
    fgets(palavra, 15, stdin);

    imprime_sufs(palavra);
}