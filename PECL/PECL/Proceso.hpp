#ifndef PROCESO_HPP
#define PROCESO_HPP
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

class Proceso
{
public:
	Proceso();
	int getNumerounico();
	int getPrioridad();
	bool getEstado();
	bool getTipo();
	string getNombre();
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
	string nombre;


};

#endif // PROCESO_HPP
