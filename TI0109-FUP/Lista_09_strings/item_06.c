#include <stdio.h>
#include <string.h>

void imprime_prefs(char* palavra){
    if(*palavra){
        printf("%s", palavra);
        imprime_prefs(palavra+1);
    }
}

int main(){
    char palavra[15];

    printf("Digite uma palavra: ");
    fgets(palavra, 15, stdin);

    imprime_prefs(palavra);
}