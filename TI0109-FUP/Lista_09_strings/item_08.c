#include <stdio.h>
#include <string.h>

void sub_strings(char* palavra, int inicio, int fim){
    int i;
    for(i = inicio; i < fim; i++){
        printf("%c", palavra[i]);
    }
    puts(",");
}

int main(){
    int n;
    char palavra[30];

    printf("Digite uma palavra: ");
    fgets(palavra, 30, stdin);
    printf("Digite um numero: ");
    scanf("%d", &n);

    int size = strlen(palavra);

    for(int i = 0; i < size-n; i++){
        sub_strings(palavra, i, i+n);
    }
}