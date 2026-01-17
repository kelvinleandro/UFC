#include <iostream>
#include <string>
using namespace std;

class Pessoa {
public:
    string nome;
    int idade;

    Pessoa(string nome, int idade) {
        this->nome = nome;   // "this->" diferencia o atributo do parâmetro
        this->idade = idade;
    }

    void apresentar() {
        cout << "Olá, eu sou " << this->nome << "!" << endl;
    }
};

int main() {
    Pessoa p("Maria", 25);
    p.apresentar();  // aqui o this aponta para p
}
