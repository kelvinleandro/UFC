#include <iostream>
using namespace std;

// Classe Base
class Pessoa {
protected: 
    string nome;   // protegido → acessível nas subclasses
public:
    void setNome(string n) {
        nome = n;
    }
    void apresentar() {
        cout << "Olá, eu sou " << nome << endl;
    }
};

// Classe Derivada com herança protegida
class Aluno : protected Pessoa {
private:
    int matricula;
public:
    Aluno(string n, int m) {
        setNome(n);     // permitido → herdado como protegido
        matricula = m;
    }

    void mostrarDados() {
        cout << "Nome: " << nome << endl;       // acessível, pois virou protected
        cout << "Matrícula: " << matricula << endl;
    }
};

// Classe mais derivada (subclasse da subclasse)
class Bolsista : public Aluno {
private:
    double bolsa;
public:
    Bolsista(string n, int m, double b) : Aluno(n, m) {
        bolsa = b;
    }
    void mostrarBolsista() {
        // nome continua acessível, herdado como protected
        cout << "Bolsista: " << nome << " - Bolsa: R$ " << bolsa << endl;
    }
};

int main() {
    Aluno a("Carlos", 1234);
    a.mostrarDados();
    // a.apresentar(); ERRO → virou protected na classe Aluno

    Bolsista b("Ana", 5678, 1200.50);
    b.mostrarBolsista();
    return 0;
}
