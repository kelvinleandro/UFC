#include <iostream>
using namespace std;

class A {
private:
	int privado = 10;
protected:
	int protegido = 20;
public:
	int publico = 30;
	
	int get_privado(void){
		return privado;
	}
};

class B : public A {
	//public: int publico;
	//protected: int protegido;
public:
	int get_protegido(void){
		return protegido;
	}
};

int main() {
	B obj;

	cout << obj.publico << endl;
	cout << obj.get_protegido() << endl;
	cout << obj.get_privado() << endl;

}

