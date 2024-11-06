#include "Pila.hpp"
#include "Proceso.hpp"
#include <iostream>
#include <optional>
using namespace std;

Pila::Pila()
{
	ultimo = NULL;
	longitud= 0;
	
}
void Pila::insertar(Proceso v)
{
	if(this->longitud >=48)
	{
		return;
	}
	else
	{
		pnodoPila nuevo;
		nuevo = new NodoPila(v, ultimo);
		ultimo = nuevo;
		longitud++;
	}
}
Proceso Pila::extraer()
{
	pnodoPila nodo;
	Proceso v;
	//if(!ultimo)
		//return nullopt;
	nodo = ultimo;
	ultimo = nodo->siguiente;
	v = nodo->valor;
	longitud--;
	delete nodo;
	return v;
	
}
Proceso Pila::cima()
{
	//pnodoPila nodo;
	//if(!ultimo)
		//return nullopt;
	return ultimo->valor;
	
}
void Pila::mostrar()
{
	pnodoPila aux = ultimo;
	cout << "\El contenido de la pila es: \n";
	while(aux) {
		Proceso val = aux->valor;
		cout << "->";
		val.toString();
		aux = aux->siguiente;
	}
	cout << endl;
	
}

int Pila::getLongitud()
{
	return this->longitud;
}
void Pila::vaciar()
{
	pnodoPila aux;
	while(ultimo) {
		aux = ultimo;
		ultimo = ultimo->siguiente;
		delete aux;
		longitud--;
	}
}
Pila::~Pila()
{
	pnodoPila aux;
	while(ultimo) {
		aux = ultimo;
		ultimo = ultimo->siguiente;
		delete aux;
	}
		
}


