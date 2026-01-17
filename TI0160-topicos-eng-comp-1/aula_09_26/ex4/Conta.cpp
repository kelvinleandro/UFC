#include<iostream>
using namespace std;

class Conta {
private:
    double saldo;
public:
    Conta(double s) : saldo(s) {}
    Conta* depositar(double valor) {
        saldo += valor;
        return this; // retorna o próprio objeto
    }
    void exibir() { cout << "Saldo: " << saldo << endl; }
};

int main() {
    Conta c(100);
    c.depositar(50)->depositar(25)->exibir();
}
