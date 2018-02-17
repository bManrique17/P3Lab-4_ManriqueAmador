#include <string>
using namespace std;

#ifndef CARRO_H
#define CARRO_H

class Carro{
	private:
		string color,marca;
		int altura;
	public:
		Carro();
		Carro(string,string,int);
		//sets
		void setColor(string);
		void setMarca(string);
		void setAltura(int);
		//gets
		string getColor();
		string getMarca();
		int getAltura();
	//destructor
	~Carro();
};

#endif
