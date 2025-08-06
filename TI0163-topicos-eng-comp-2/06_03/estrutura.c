#include <stdio.h>
#include <string.h>
#include "aluno.h"

void cadastrarAlunos(Aluno* alunos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        snprintf(alunos[i].nome, sizeof(alunos[i].nome), "Aluno %d", i + 1);
        alunos[i].matr = i + 1;
        alunos[i].semestre = 4;
    }    
}

void imprimirAlunos(Aluno* alunos, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\nAluno %d:\n", i + 1);
        printf("  Nome: %s\n", alunos[i].nome);
        printf("  Matricula: %d\n", alunos[i].matr);
        printf("  Semestre: %d\n", alunos[i].semestre);
    }
}

int main(void) {
    Aluno instAluno[TAM];
    cadastrarAlunos(instAluno, TAM);
    imprimirAlunos(instAluno, TAM);
    return 0;
}