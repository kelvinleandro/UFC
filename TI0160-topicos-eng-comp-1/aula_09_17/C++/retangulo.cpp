#include <iostream>
using namespace std;

class Retangulo {
private:
    float base;
    float altura;

public:
    void lerDados() {
        cout << "Digite a base do retangulo: ";
        cin >> base;
        cout << "Digite a altura do retangulo: ";
        cin >> altura;
    }

    float calcularArea() {
        return base * altura;
    }

    void exibirArea() {
        cout << "A area do retangulo e: " << calcularArea() << endl;
    }
};

int main() {
    Retangulo ret;
    ret.lerDados();
    ret.exibirArea();

    return 0;
}
