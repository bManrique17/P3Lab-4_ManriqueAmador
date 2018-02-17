#include "Parqueo.h"
#include "Carro.h"
#include <string>
#include <iostream>

using namespace std;
Parqueo::Parqueo(){}

Parqueo::Parqueo(int pCantidadPisos, int pCantidadPersonasXPiso,int pHMax){
	cantidadPisos = pCantidadPisos;
	hMax = pHMax;
	cantidadN = pCantidadPersonasXPiso/10;
	if(cantidadN<12)
		cantidadM = cantidadN*0.7;
	else
		cantidadM = cantidadN*0.4;
	cantidadZ = pCantidadPisos;
	crearMatriz();
}


int Parqueo::getCantidadPisos(){
	return cantidadPisos;
}

int Parqueo::getCantidadN(){
	return cantidadN;
}

int Parqueo::getCantidadM(){
	return cantidadM;
}

int Parqueo::getCantidadZ(){
	return cantidadZ;
}

int Parqueo::getHMax(){
	return hMax;
}

void Parqueo::setCantidadN(int pCantidadN){
	cantidadN = pCantidadN;
}

void Parqueo::setCantidadM(int pCantidadM){
	cantidadM = pCantidadM;
}

void Parqueo::crearMatriz(){
	int n,m,z;
	n=cantidadN;
	m=cantidadM;
	z=cantidadZ;
	espaciosParqueo = new Carro***[n];
	for(int i=0 ; i<n ; i++){
		espaciosParqueo[i] = new Carro**[m];
		for(int j=0 ; j<m ; j++){
			espaciosParqueo[i][j] = new Carro*[z];
			for(int k=0 ; k<z ; k++){
				espaciosParqueo[i][j][k] = NULL;
			}
		}
	}
}	

Parqueo::~Parqueo(){/*
	for(int i=0 ; i!=cantidadN ; i++){
		for(int j=0 ; j!=cantidadM ; j++){
			for(int k=0 ; k!=cantidadZ ; k++){
				espaciosParqueo[i][j][k] = NULL;
				delete espaciosParqueo[i][j][k];
			}
			delete[] espaciosParqueo[i][j];
		}
		delete[] espaciosParqueo[i];
	}
	delete [] espaciosParqueo;
	*/
}
