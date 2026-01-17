#include <iostream>
using namespace std;

class Animal {
public:
    void respirar() {
        cout << "Respirando..." << endl;
    }
};

class Cachorro : public Animal {
public:
    void latir() {
        cout << "Au Au!" << endl;
    }
};

int main() {
    Cachorro c;
    c.respirar(); // herdado
    c.latir();    // próprio
}

