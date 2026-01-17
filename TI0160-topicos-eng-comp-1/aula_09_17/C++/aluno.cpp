#include <iostream>
#include <string>

using namespace std;

class Aluno {
private:
	string nome;
	int matricula;
	string curso;

public:
	// Metodo par cadastrar aluno
	void cadastrar() {
		cout << "Cadastrar Alunos" << "\n";
		nome = "Alexandre Coelho";
		matricula = 120;
		curso = "Eng. Comp.";
	}

	//Método para exibir dados do aluno
	void exibir() {
		cout << "\nExibir dados dos alunos\n";
		cout << "Nome: " << nome << endl;
		cout << "Matr: " << matricula << endl;
		cout << "Curso: " << curso << endl;
	}
};


int main(){
	Aluno aluno;

	aluno.cadastrar();
	aluno.numtest = 10;
	aluno.exibir();
	return 0;
}
