#include <stdio.h>
#include <stdbool.h>

typedef struct{
    int usercode; // n >= 1
    char username[100];
}data_facebook;


void imprime_matriz(int n, int m[n][n]){
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n; j++){
            printf(" %d |", m[i][j]);
        }
        printf("\n");
    }
}

void zera_celulas(int n, int i, int j, int m[n][n], data_facebook* people){
    for(int i = i; i < n; i++){
        m[i][j] = 0;
    }
}

void adiciona_seguidor(int n, int m[n][n], data_facebook* people){
    int aux;
    bool zera = false;
    for(int i = 0; i < n; i++){ //coluna
        for(int j = 0; j < n; j++){ //linha
            if(j != 0){
                printf("Usuario %d, digite o codigo de quem voce segue ou 0 se n segue mais ninguem: ", m[0][i]);
                scanf("%d", &aux);
                if(aux == 0){
                    zera_celulas(n, i, j, m, people);
                    return;
                }
                else{
                    m[j][i] = aux;
                }
            }
        }
    }
}

void preenche_matriz(int n, int m[n][n], data_facebook* people){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            if(i == 0){
                m[i][j] = people[i].usercode;
            }
            else{
                adiciona_seguidor(n, m, people);
            }
        }
    }
}

int main(){
    int n;
    char buffer[100];
    n = atoi(fgets(buffer, 100, stdin));
    if(n <= 1) return 0;

    data_facebook people[n];
    int m[n][n]; // n <= x >= 0

    for(int i = 0; i < n; i++){
        printf("Username %d: ", i+1);
        fgets(people[i].username, 100, stdin);
        people[i].usercode = i+1;
    }

    preenche_matriz(n, m, people);
    imprime_matriz(n, m);

    return 0;
}