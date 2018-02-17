temp:	mainLab4.o Carro.o Parqueo.o Edificio.o
	g++ mainLab4.o Carro.o Parqueo.o Edificio.o -o temp

mainLab4.o:	mainLab4.cpp Carro.h Parqueo.h Edificio.h
	g++ -c mainLab4.cpp

Carro.o:	Carro.h Carro.cpp
	g++ -c Carro.cpp

Parqueo.o:	Parqueo.h Parqueo.cpp Carro.h
	g++ -c Parqueo.cpp

Edificio.o:	Edificio.h Edificio.cpp
	g++ -c Edificio.cpp


