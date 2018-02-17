#include <string>
#include "Carro.h"
#include "Edificio.h"
#include "Parqueo.h"
#include <iostream>

using namespace std;

int menu();
void crearEdificio();
void parquearCarro();
void eliminarCarro();
void inventarioParqueo();

Edificio* EdificioActual;
Parqueo* ParqueoActual;
Carro* CarroActual;
Carro**** espaciosParqueoM;

int main(){
	cout<<"LAB#4_ManriqueAmador"<<endl;
	char respuesta;
	do{
		switch(menu()){
			case 1:
				crearEdificio();
				break;
			case 2:
				parquearCarro();
				break;
			case 3:
				eliminarCarro();
				break;
			case 4:
				inventarioParqueo();
				break;
			default:
				break;
		}
		cout<<"\nDesea ejecutar de nuevo [S/N]: ";
		cin>>respuesta;
	}while(respuesta == 's' || respuesta == 'S');

	return 0;
}

int menu(){
	int retorno;
	cout<<"->MENU"<<endl
		<<"(1)Crear edificio"<<endl
		<<"(2)Parquear un carro"<<endl
		<<"(3)Eliminar un carro"<<endl
		<<"(4)Inventario del parqueo"<<endl
		<<"->Ingrese su respuesta: ";
	cin>>retorno;
	return retorno;
}

void crearEdificio(){
	int cantidadPersonasXPiso,cantidadPisos,hMax;
	cout<<"\n**Crear edificio"<<endl;
	cout<<"Ingrese la capacidad de personas por piso: ";
	cin>>cantidadPersonasXPiso;
	do{
		if(cantidadPersonasXPiso>49 && cantidadPersonasXPiso<201)
			break;
		else{
			cout<<"Fuera del rango (50-200), ingreselo de nuevo"<<endl;
			cin>>cantidadPersonasXPiso;
		}
	}while(true);
	cout<<"Ingrese la cantidad de pisos: ";
	cin>>cantidadPisos;
	cout<<"Ingrese la altura maxima: ";
	cin>>hMax;
	EdificioActual = new Edificio(cantidadPisos,cantidadPersonasXPiso);
	ParqueoActual = new Parqueo(cantidadPisos,cantidadPersonasXPiso, hMax);
	espaciosParqueoM = ParqueoActual->espaciosParqueo;
	cout<<"Edificio y parqueo creado"<<endl;

}

void parquearCarro(){
	string colorCC,marcaCC;
	int alturaCC,piso;
	cout<<"**Parquear Carro"<<endl;
	cout<<"Ingrese el color del carro: ";
	cin>>colorCC;
	cout<<"Ingrese la marca del carro; ";
	cin>>marcaCC;
	cout<<"Ingrese la altura maxima del carro: ";
	cin>>alturaCC;
	if(alturaCC>=ParqueoActual->getHMax())
		cout<<"El carro es demasiado alto"<<endl;
	else{
		CarroActual = new Carro(colorCC,marcaCC,alturaCC);
		cout<<"\nEl parqueo tiene "<<ParqueoActual->getCantidadPisos()<<" pisos"<<endl;
		cout<<"Ingrese en que piso desea colocar su auto(si es el primero ingresar 0): ";
		cin>>piso;
		int senuelo = ParqueoActual->getCantidadZ()*ParqueoActual->getCantidadM();
		for(int a=0 ; a<ParqueoActual->getCantidadN() ; a++ ){
			if(senuelo==-1)
				break;
			for(int b=0 ; b<ParqueoActual->getCantidadM() ; b++){
				if(espaciosParqueoM[a][b][piso]==NULL){
					cout<<"Se ha estacionado en la posicion "<<a<<"-"<<b<<" del piso "<<piso<<endl;
					espaciosParqueoM[a][b][piso] = CarroActual;
					senuelo=-1;
					break;
				}else{
					senuelo--;
				}
			}
		}
		if(senuelo==0){
			cout<<"No hay espacio en ese piso"<<endl;
		}
	}

}

void inventarioParqueo(){

	int vacios=0,llenos=0;
	cout<<"\n**Inventario Parqueo"<<endl;
	for(int i = 0 ; i<ParqueoActual->getCantidadN() ; i++){
		for(int j = 0 ; j<ParqueoActual->getCantidadM() ; j++){
			for(int k = 0 ; k<ParqueoActual->getCantidadZ() ; k++){
				if(espaciosParqueoM[i][j][k] == NULL)
					vacios++;		
				else
					llenos++;
			}
		}
	}
	cout<<"Espacios vacios: "<<vacios<<endl;
	cout<<"Espacios llenos: "<<llenos<<endl;

}

void eliminarCarro(){
	int piso,x,y;
	cout<<"\n**Eliminar un carro"<<endl;
	cout<<"->Ingrese el piso: ";
	cin>>piso;
	cout<<"->Ingrese el valor x: ";
	cin>>x;
	cout<<"->Ingrese el valor y: ";
	cin>>y;
	if(espaciosParqueoM[x][y][piso] == NULL){
		cout<<"Ahi no hay un carro"<<endl;
	}else{
		espaciosParqueoM[x][y][piso] = NULL;
		cout<<"Posicion ["<<x<<"]["<<y<<"]["<<piso<<"]"<<" eliminada"<<endl;
	}
}
