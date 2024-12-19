#include "NodoLista.hpp"
#include <string>

NodoLista::NodoLista(Proceso v, NodoLista* sig, NodoLista* prev)
{
	valor = v;
	siguiente = sig;
	anterior = prev;
}

NodoLista::~NodoLista()
{
}

