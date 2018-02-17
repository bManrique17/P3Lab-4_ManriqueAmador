#include "Edificio.h"

#include <string>
using namespace std;
Edificio::Edificio(){}

Edificio::Edificio(int pCantidadPisos, int pCantidadPersonasXPiso){
	cantidadPisos = pCantidadPisos;
	cantidadPersonasXPiso = pCantidadPersonasXPiso;
}

//gets
int Edificio::getCantidadPisos(){
	return cantidadPisos;
}

int Edificio::getCantidadPersonasXPiso(){
	return cantidadPersonasXPiso;
}

//gets
void Edificio::setCantidadPisos(int pCantidadPisos){
	cantidadPisos = pCantidadPisos;
}

void Edificio::setCantidadPersonasXPiso(int pCantidadPersonasXPiso){
	cantidadPersonasXPiso = pCantidadPersonasXPiso;
}

