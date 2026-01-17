#ifndef ESCOLA_H
#define ESCOLA_H

#include <iostream>
#include <string>

class Escola {
private:
    std::string nome;

public:
    Escola();
    Escola(const std::string& nome);

    void mostrarEscola() const;

    class Turma {
    private:
        std::string serie;

    public:
        Turma();
        Turma(const std::string& serie);

        void mostrarTurma() const;

        class Aluno {
        private:
            std::string nomeAluno;
            double nota;

        public:
            Aluno();
            Aluno(const std::string& nome, double nota);

            void mostrarAluno() const;

            Aluno operator+(const Aluno& outro) const;

            friend std::ostream& operator<<(std::ostream& os, const Aluno& aluno);
        };
    };
};

#endif // ESCOLA_H