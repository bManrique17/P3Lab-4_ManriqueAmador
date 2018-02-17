#include <string>  //parqueo
#include "Carro.h"
using namespace std;

#ifndef PARQUEO_H
#define PARQUEO_H

class Parqueo{
	private:
		int cantidadPisos,cantidadN,cantidadM,cantidadZ,hMax;
	public:
		Parqueo();
		Parqueo(int,int,int);
		Carro**** espaciosParqueo;
		void setCantidadN(int);
		void setCantidadM(int);
		void crearMatriz();
		//gets
		int getCantidadPisos();
		int getCantidadN();
		int getCantidadM();
		int getCantidadZ();
		int getHMax();
	//destructor
	~Parqueo();
};

#endif
