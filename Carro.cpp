#include "Carro.h"

#include <string>
using namespace std;
Carro::Carro(){}

Carro::Carro(string pColor,string pMarca, int pAltura){
	color = pColor;
	marca = pMarca;
	altura = pAltura;
}

//gets
string Carro::getColor(){
	return color;
}

int Carro::getAltura(){
	return altura;
}

string Carro::getMarca(){
	return marca; 
}

//gets
void Carro::setColor(string pColor){
	color = pColor;
}

void Carro::setAltura(int pAltura){
	altura = pAltura;
}

void Carro::setMarca(string pMarca){
	marca = pMarca;
}
