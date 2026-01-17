#include <iostream>
#include <string>

using namespace std;

class Impressora {
public:
    void imprimir(){
        cout << "Documento impresso." << endl;
    }
};

class Scanner {
public:
    void digitalizar(){
        cout << "Documento digitalizado." << endl;
    }
};

class Multifuncional : public Impressora, public Scanner {
public:
    void copiar() {
        imprimir();
        digitalizar();
    }
};

int main() {
    Multifuncional m;

    m.imprimir();

    m.digitalizar();

    m.copiar();
    
    return 0;
}