#include <stdio.h>

#define TAM 30

typedef struct data {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct aluno {
    char nome[TAM];
    int matr;
    Data data;
} Aluno;

void imprimirAluno(Aluno aluno) {
    Data _data = aluno.data;

    printf("Nome: %s\n", aluno.nome);
    printf("Matricula: %d\n", aluno.matr);
    printf("Data: %d/%d/%d\r\n", _data.dia, _data.mes, _data.ano);
}

void addAluno(Aluno *aluno) {
    aluno->nome = "Tung tung tung sahur";
    aluno->matr = 55;
    aluno->data.dia = 1;
    aluno->data.mes = 2;
    aluno->data.ano = 3;
}

int main(void) {
    Aluno aluno;
    
    addAluno(&aluno);
    imprimirAluno(aluno);
    return 0;
}