#include<iostream>
using namespace std;

class A{
private:
	int privado = 10;

protected:
	int protegido = 20;

public:
	int publico = 30;

	int get_privado_A(){
		return privado;
	}
};


class B : protected A {
/*
protected:
	int protegido;
	int publico;
*/

public:
	int get_publico(){
		return publico;
	}

	int get_protegido(){
		return protegido;
	}

	int get_privado_B(){
		return get_privado_A();
	}

};



int main(){
	B objeto;

	cout << objeto.get_publico() << endl;
	cout << objeto.get_protegido() <<  endl;

	cout << objeto.get_privado_B() << endl;

}
