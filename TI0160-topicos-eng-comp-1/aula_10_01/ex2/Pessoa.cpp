#include <iostream>
using namespace std;

class Pessoa {
public:
    string nome;
    int idade;

    // Construtor padrão (sem parâmetros)
    Pessoa() {
        nome = "Desconhecido";
        idade = 0;
    }

    // Construtor com um parâmetro
    Pessoa(string n) {
        nome = n;
        idade = 0;
    }

    // Construtor com dois parâmetros
    Pessoa(string n, int i) {
        nome = n;
        idade = i;
    }

    void apresentar() {
        cout << "Olá, eu sou " << nome << " e tenho " << idade << " anos." << endl;
    }
};

int main() {
    Pessoa p1;                  // usa construtor padrão
    Pessoa p2("Alexandre");     // usa construtor com 1 parâmetro
    Pessoa p3("Maria", 25);     // usa construtor com 2 parâmetros

    p1.apresentar();
    p2.apresentar();
    p3.apresentar();

    return 0;
}
