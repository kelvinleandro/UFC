#include <stdio.h>

struct aluno{
    char nome[100];
    float n1, n2, n3, media;
};

void ordena_struct(int n, struct aluno alunos[]){
    struct aluno aux;
    for(int i = 0; i < n; i++){
        for(int j = i +1; j < n; j++){
            if(alunos[j].media > alunos[i].media){
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }
}

void imprime_struct(int n, struct aluno alunos[]){
    for(int i = 0; i < n; i++){
        printf("%d: %s", i, alunos[i].nome);
        printf("   Media: %.2f\n", alunos[i].media);
        printf("   N1: %.2f, N2: %.2f, N3: %.2f\n", alunos[i].n1, alunos[i].n2, alunos[i].n3);
    }
}

int main(){
    int n;
    char buffer[100];
    n = atoi(fgets(buffer, 100, stdin));
    struct aluno alunos[n];

    for(int i = 0; i < n; i++){
        fgets(alunos[i].nome, 100, stdin);
        setbuf(stdin, NULL);
        scanf(" %f %f %f", &alunos[i].n1, &alunos[i].n2, &alunos[i].n3);
        setbuf(stdin, NULL);
        alunos[i].media = (alunos[i].n1+alunos[i].n2+alunos[i].n3) / 3;
    }

    ordena_struct(n, alunos);
    imprime_struct(n, alunos);

    return 0;
}