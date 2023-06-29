#include <stdio.h>
struct pessoa{
    char nome[4];
    int valor, montante;
};

int main(){
    int n, maior = 0, pessoa = 0;
    scanf("%d", &n);
    struct pessoa v[n];

    for(int i = 0; i < n; i++){
        scanf("%s %d", &v[i].nome, &v[i].valor);
        v[i].montante = v[i].valor;
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(strcmp(v[i].nome, v[j].nome) == 0){
                v[i].montante += v[j].valor;
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(v[i].montante >= maior){
            maior = v[i].montante;
            pessoa = i;
        }
    }

    printf("%s", v[pessoa].nome);
}