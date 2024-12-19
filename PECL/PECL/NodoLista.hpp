#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP
#include "Proceso.hpp"
#include <string>
class NodoLista
{
public:
	NodoLista(Proceso v, NodoLista* sig = NULL, NodoLista* prev = NULL);
	~NodoLista();
	
private:
	Proceso valor;
	NodoLista*siguiente;
	NodoLista*anterior;
	
	friend class Lista;

};

typedef NodoLista* pnodoLista;


#endif // NODOLISTA_HPP
