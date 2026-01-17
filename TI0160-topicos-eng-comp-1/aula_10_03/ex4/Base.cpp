#include<iostream>
using namespace std;

class Base1{
public: 
	int x;
	Base1(){
		x=1;
	}
};

class Base2{
public: 
	int x;
	Base2(){
		x=2;
	}
};


class Derivada: public Base1, public Base2 {
public:
	int z;
	Derivada(){
		z=3;
	}

	void getX(){
		cout << Base1::x << endl;
		cout << Base2::x << endl;
	}
};


int main(){
	Derivada obj;
	cout << obj.z << endl;
	// obj.getX();
	cout << obj.Base1::x << endl;
	cout << obj.Base2::x << endl;
}
