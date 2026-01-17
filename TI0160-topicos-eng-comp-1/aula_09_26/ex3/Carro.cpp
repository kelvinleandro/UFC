#include <iostream>
#include <string>
using namespace std;

class Carro {
public:
    string modelo;

    Carro(string m) {  // construtor
        modelo = m;
        cout << "Carro criado: " << modelo << endl;
    }

    ~Carro() {  // destrutor
        cout << "Carro destruído: " << modelo << endl;
    }
};

int main() {
    Carro c1("Fusca");       // stack
    Carro* c2 = new Carro("Civic"); // heap

    delete c2; // destruição manual

    return 0;
}
