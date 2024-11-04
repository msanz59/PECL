#ifndef LISTA_HPP
#define LISTA_HPP
#include "Proceso.hpp"
#include "NodoLista.hpp"

class Lista
{
public:
	Lista();
	~Lista();
	
	void insertar(Proceso v);
	Proceso eliminar();
	void mostrar();
	Proceso verPrimero();
	int getLongitud();
	void vaciar();
	
private:
	pnodoLista primero, ultimo;
	int longitud;

};

#endif // LISTA_HPP
