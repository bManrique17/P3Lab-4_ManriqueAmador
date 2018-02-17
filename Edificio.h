#include <string>
using namespace std;

#ifndef EDIFICIO_H
#define EDIFICIO_H

class Edificio{
	private:
		int cantidadPisos,cantidadPersonasXPiso;
	public:
		Edificio();
		Edificio(int,int);
		//sets
		void setCantidadPisos(int);
		void setCantidadPersonasXPiso(int);
		//gets
		int getCantidadPisos();
		int getCantidadPersonasXPiso();
	//destructor
	~Edificio();
};

#endif
