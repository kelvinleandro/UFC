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

    // Sobrecarga do operador +
    A operator+(int b) {
        return A(x + b, y + b);
    }
};

int main() {
    A a(1, 2), b(3, 4);
    A c;

    c = a + 5; // usa a sobrecarga de operador

    cout << "c.x = " << c.x << " e c.y = " << c.y << endl;
    return 0;
}
