#ifndef PROCESO_HPP
#define PROCESO_HPP
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

class Proceso
{
public:
	Proceso();
	void setombrenorandom();
	int getNumerounico();
	int getPrioridad();
	bool getEstado();
	bool getTipo();
	char* getNombre();
	void setNumerounico(int num);
	void setNombrerand();
	void setEstado(bool est);
	void setPrioridad(int num);
	void setTipo(int tip);
	void toString();
	
	~Proceso();
	
private:
	int numerounico;
	bool estado;
	int prioridad;
	bool tipo;
	char nombre[6];


};

#endif // PROCESO_HPP
