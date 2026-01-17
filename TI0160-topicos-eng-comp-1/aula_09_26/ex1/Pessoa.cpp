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
    Pessoa p1("Alexandre", 30);
    p1.apresentar();
    return 0;
}
