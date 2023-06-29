#include <stdio.h>
#include <string.h>

struct restaurante{
    int ponto;
    char nome[20];
};

void melhor_restaurante(int n, struct restaurante restaurantes[]){
    int maior_pontuacao, maior_indice;

    for(int i = 0; i < n; i++){
        if(i == 0){
            maior_indice = i;
            maior_pontuacao = restaurantes[i].ponto;
        }
        else if(restaurantes[i].ponto > maior_pontuacao){
            maior_indice = i;
            maior_pontuacao = restaurantes[i].ponto;
        }
        else if(restaurantes[i].ponto == maior_pontuacao){
            if(strcmp(restaurantes[i].nome, restaurantes[maior_indice].nome) < 0){
                maior_indice = i;
                maior_pontuacao = restaurantes[i].ponto;
            }
        }
    }

    printf("%s\n", restaurantes[maior_indice].nome);
}

int main()
{
    int n, maior_ponto;
    char buffer[100], melhor[100];
    scanf("%d", &n);
    struct restaurante test[n];
    
    for(int i = 0; i < n; i++){
        scanf("%s %d", &test[i].nome, &test[i].ponto);
    }

    melhor_restaurante(n, test);
    return 0;
}
