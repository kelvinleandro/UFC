#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct pessoa{
    char nome[20], sexo;
    int idade;
};

int main(){

    int n, maior;
    char mais_velha[20];
    bool mulher_existe = false;

    scanf("%d", &n);
    struct pessoa pessoas[n];

    for(int i = 0; i < n; i++){
        scanf("%s %d %c", &pessoas[i].nome, &pessoas[i].idade, &pessoas[i].sexo);
    }
    
    for(int i = 0; i < n; i++){
        if ((i == 0) && (pessoas[i].sexo == 'f')){
            maior = pessoas[i].idade;
            strcpy(mais_velha, pessoas[i].nome);
            mulher_existe = true;
        }
        else if((pessoas[i].sexo == 'f') && (pessoas[i].idade > maior)){
            maior = pessoas[i].idade;
            strcpy(mais_velha, pessoas[i].nome);
            mulher_existe = true;
        }
    }

    if(mulher_existe == false){
        printf("nao tem mulher\n");
    }
    else{
        printf("%s\n", mais_velha);
    }


}