#include <iostream>
#include <string>
using namespace std;

class Pessoa {
public:
    string nome;
    int idade;

    Pessoa(string nome, int idade) {
        this->nome = nome;
        this->idade = idade;
    }

    Pessoa() {
        nome = "Desconhecido";
        idade = 20;
    }

    void mostrar(){
        cout << "Pessoa: " << nome << "; Idade: " << idade << endl;
    }
};

class Aluno: protected Pessoa {
public:
    Aluno(string nome, int idade) : Pessoa(nome, idade) {}

    Aluno() : Pessoa() {}

    void mostrar(){
        cout << "Aluno: " << nome << "; Idade: " << idade << endl;
    }
};

class Professor: private Pessoa {
public:
    Professor(string nome, int idade): Pessoa(nome, idade) {}

    Professor() : Pessoa() {}

    void mostrar() {
        cout << "Professor: " << nome << "; Idade: " << idade << endl; 
    }
    

};

int main() {
    Pessoa pe("Joao", 18);
    Aluno al("Maria", 17);
    Professor prof("Alex", 43);

    cout << pe.nome << " " << pe.idade << endl;
    pe.mostrar();
    
    // cout << al.nome << " " << al.idade << endl;
    al.mostrar();

    // cout << prof.nome << " " << prof.idade << endl;
    prof.mostrar();

    return 0;
}