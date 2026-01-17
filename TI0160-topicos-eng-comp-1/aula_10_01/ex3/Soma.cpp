#include <iostream>
using namespace std;

class A {
public:
    int x, y;

    // Construtor padrão
    A() {
        x = y = 0;
    }

    // Construtor parametrizado
    A(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

// Função soma que retorna um objeto A
A soma(A a, A b) {
    return A(a.x + b.x, a.y + b.y);
}

int main() {
    A a(1, 2), b(3, 4);
    A c;

    c = soma(a, b);

    cout << "c.x = " << c.x << " e c.y = " << c.y << endl;
    return 0;
}
