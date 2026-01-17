#include <iostream>
using namespace std;

// ===== Classe A =====
class A {
public:
    void mostrarA() {
        cout << "Sou a classe A" << endl;
    }
};

// ===== Classe B =====
class B {
public:
    void mostrarB() {
        cout << "Sou a classe B" << endl;
    }
};

// ===== Classe C herda de A e B =====
class C : public A, public B {
public:
    void mostrarC() {
        cout << "Sou a classe C" << endl;
    }
};

int main() {
    C obj;
    obj.mostrarA(); // herdado de A
    obj.mostrarB(); // herdado de B
    obj.mostrarC(); // da própria C
    return 0;
}
