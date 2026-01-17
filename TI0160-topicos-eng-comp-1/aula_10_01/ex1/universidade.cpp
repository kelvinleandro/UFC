#include <iostream>
#include <string>
using namespace std;

// Classe externa
class Universidade {
public:
    string nome;

    Universidade(string n) : nome(n) {}

    // Classe interna
    class Departamento {
    public:
        string nomeDep;

        Departamento(string d) : nomeDep(d) {}

        // Classe aninhada dentro de Departamento
        class Professor {
        public:
            string nomeProf;

            Professor(string p) : nomeProf(p) {}

            void apresentar();
        };

        void mostrarDep();
    };

    void mostrarUniv();
};

// Implementações com operador de escopo '::'

// Método da classe Universidade
void Universidade::mostrarUniv() {
    cout << "Universidade: " << nome << endl;
}

// Método da classe Departamento
void Universidade::Departamento::mostrarDep() {
    cout << "Departamento: " << nomeDep << endl;
}

// Método da classe Professor
void Universidade::Departamento::Professor::apresentar() {
    cout << "Professor: " << nomeProf << endl;
}

// Programa principal
int main() {
    // Criando objetos
    Universidade u("Universidade Federal do Ceará");
    Universidade::Departamento d("Engenharia de Teleinformática");
    Universidade::Departamento::Professor p("Prof. Dr. Alexandre Coelho");

    // Chamando métodos
    u.mostrarUniv();
    d.mostrarDep();
    p.apresentar();

    return 0;
}
