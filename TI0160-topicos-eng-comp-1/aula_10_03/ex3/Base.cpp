#include <iostream>
using namespace std;

// ===== Classe Base =====
class Base {
public:
    void metodoPublico() {
        cout << "Método público da Base" << endl;
    }
protected:
    void metodoProtegido() {
        cout << "Método protegido da Base" << endl;
    }
};

// ===== Classe Derivada com herança privada =====
class Derivada : private Base {
public:
    void acessarBase() {
        // Dentro da Derivada ainda conseguimos usar os métodos
        metodoPublico();   // virou private em Derivada
        metodoProtegido(); // também virou private
    }
};

// ===== Outra Classe que herda de Derivada =====
class Neto : public Derivada {
public:
    void tentarAcessar() {
        // metodoPublico();   // Erro → não acessível, virou private em Derivada
        // metodoProtegido(); // Erro → não acessível, virou private em Derivada
        cout << "Neto não herda nada diretamente da Base" << endl;
    }
};

int main() {
    Derivada d;
    d.acessarBase();   // funciona, porque foi exposto em Derivada

    // d.metodoPublico();   // Erro: virou private em Derivada
    // d.metodoProtegido(); // Erro: virou private em Derivada

    Neto n;
    n.tentarAcessar(); // só executa mensagem própria

    return 0;
}
