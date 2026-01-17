#include <iostream>
#include "Escola.h"

int main() {
    Escola escola("UFC");
    Escola::Turma turma("Engenharia de Computacao");

    escola.mostrarEscola();
    turma.mostrarTurma();

    Escola::Turma::Aluno aluno1("Ana", 9.0);
    Escola::Turma::Aluno aluno2("Pedro", 7.0);

    aluno1.mostrarAluno();
    aluno2.mostrarAluno();

    Escola::Turma::Aluno aluno3 = aluno1 + aluno2;

    std::cout << aluno3 << std::endl;

    return 0;
}