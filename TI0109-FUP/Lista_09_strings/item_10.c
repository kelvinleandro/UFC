#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool eh_senha(char* senha){
    int i, size = strlen(senha);
    if(size < 7 || size > 15) 
        return false;

    bool numerico = 0, minusc = 0, maiusc = 0;

    for(i=0; i < size; i++){
        if(isupper(senha[i])){
            maiusc = true;
        }
        else if(islower(senha[i])){
            minusc = true;
        }
        else if(isdigit(senha[i])){
            numerico = true;
        }
    }

    return numerico && minusc && maiusc; 
}

int main(){
    char senha[30];

    printf("Senha: ");
    fgets(senha, 29, stdin);

    if(eh_senha(senha))
        printf("Senha Valida");
    else
        printf("Senha Invalida");
}