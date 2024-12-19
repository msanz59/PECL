#ifndef PILA_HPP
#define PILA_HPP
#include "Proceso.hpp"
#include "NodoPila.hpp"
#include <string>
#include <vector>


class Pila
{
public:
	Pila();
	~Pila();
	void insertar(Proceso v);
	Proceso extraer();
	Proceso cima();
	void mostrar();
	int getLongitud();
	void vaciar();
	vector<int> getPIDSborrados();
	void borrarPIDSborrados();
	
	
private:
	pnodoPila ultimo;
	int longitud;
	vector<int> PIDSborrados;
	

};



#endif // PILA_HPP
