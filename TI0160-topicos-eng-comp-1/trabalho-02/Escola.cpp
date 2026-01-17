#include "Escola.h"

Escola::Escola() : nome("Sem Nome") {}

Escola::Escola(const std::string& nome) : nome(nome) {}

void Escola::mostrarEscola() const {
    std::cout << "Escola: " << nome << std::endl;
}

Escola::Turma::Turma() : serie("Nao Definida") {}

Escola::Turma::Turma(const std::string& serie) : serie(serie) {}

void Escola::Turma::mostrarTurma() const {
    std::cout << "Turma: " << serie << std::endl;
}

Escola::Turma::Aluno::Aluno() : nomeAluno("Sem Nome"), nota(0.0) {}

Escola::Turma::Aluno::Aluno(const std::string& nome, double nota) : nomeAluno(nome), nota(nota) {}

void Escola::Turma::Aluno::mostrarAluno() const {
    std::cout << "Aluno -> Nome: " << nomeAluno << ", Nota: " << nota << std::endl;
}

Escola::Turma::Aluno Escola::Turma::Aluno::operator+(const Aluno& outro) const {
    double mediaNota = (this->nota + outro.nota) / 2.0;
    std::string nomeCombinado = this->nomeAluno + "+" + outro.nomeAluno;
    return Aluno(nomeCombinado, mediaNota);
}

std::ostream& operator<<(std::ostream& os, const Escola::Turma::Aluno& aluno) {
    os << "Aluno -> Nome: " << aluno.nomeAluno << ", Nota: " << aluno.nota;
    return os;
}