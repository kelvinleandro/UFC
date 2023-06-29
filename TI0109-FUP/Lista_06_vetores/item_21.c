#include <stdio.h>

int main(){
    int n, i, j, k;
    float media_pond = 0, media_sala = 0;

    printf("Insira a quantidade de alunos: ");
    scanf("%d", &n);

    printf("Insira a quantidade de provas: ");
    scanf("%d", &k);
    float notas[n][k], pesos[k], soma_pesos = 0;

    puts("");

    for(i=0; i < k; i++){
        printf("Insira o peso da prova %d: ", i+1);
        scanf("%f", &pesos[i]);
        soma_pesos += pesos[i];
    }

    puts("");

    for(i=0; i < n; i++){
        for(j=0; j < k; j++){
            printf("Insira a nota do aluno %d na prova %d: ", i+1, j+1);
            scanf("%f", &notas[i][j]);
            puts("");
        }
    }

    for(i=0; i < n; i++){
        media_pond = 0;
        for(j=0; j < k; j++){
            media_pond += notas[i][j]*pesos[j];
        }
        media_pond = media_pond / soma_pesos;
    }

    for(j=0; j < k; j++){
        media_sala = 0;
        for(i=0; i < n; i++){
            media_sala += notas[i][j];
        }
        media_sala = media_sala/n;
        printf("Media da sala na prova %d: %f\n", j+1, media_sala);
    }
}