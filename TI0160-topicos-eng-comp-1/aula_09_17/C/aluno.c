#include<stdio.h>
#include<string.h>


typedef struct aluno {
	char nome[60];
	int matricula;
	char curso[20];
} Aluno;


void cadastrarAluno(Aluno *estudante);
void exibirAluno(Aluno estudante);

void cadastrarAluno(Aluno *estudante){
	printf("Cadastro de aluno\n");
	strcpy(estudante->nome, "Alexandre Coelho");
	estudante->matricula = 120;
	strcpy(estudante->curso, "Eng. Comp.");
	printf("DONE\n");

}

void exibirAluno(Aluno estudante){
	printf("\nImprimir alunos Cadastrados\n");
	printf("Aluno: %s\n", estudante.nome);
	printf("Matr.: %d\n", estudante.matricula);
	printf("Curso: %s\n", estudante.curso);

}


int main(){
	Aluno estudante01;
	cadastrarAluno(&estudante01);
	exibirAluno(estudante01);


}
