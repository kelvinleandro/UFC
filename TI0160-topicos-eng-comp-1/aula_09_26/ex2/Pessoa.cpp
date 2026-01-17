#include <iostream>
#include <string>
using namespace std;

class Pessoa {
public:
    string nome;
    int idade;

    Pessoa(string n, int i) {
        nome = n;
        idade = i;
        cout << "Objeto criado: " << nome << endl;
    }

    void apresentar() {
        cout << "Olá, eu sou " << nome << " e tenho " << idade << " anos." << endl;
    }

    ~Pessoa() {
        cout << "Objeto destruído: " << nome << endl;
    }
};

int main() {
    Pessoa* p2 = new Pessoa("Alexandre", 30); // criando dinamicamente
    p2->apresentar();

    delete p2; // objeto destruído explicitamente
    return 0;
}
