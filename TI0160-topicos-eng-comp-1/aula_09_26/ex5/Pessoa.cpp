#include "Pessoa.h"
#include <iostream>
using namespace std;

Pessoa::Pessoa(string n, int i) {
    nome = n;
    idade = i;
}

void Pessoa::apresentar() {
    cout << "Olá, meu nome é " << nome 
         << " e tenho " << idade << " anos." << endl;
}
