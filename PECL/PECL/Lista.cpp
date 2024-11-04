#include "Lista.hpp"

Lista::Lista()
{
	primero=NULL;
	ultimo=NULL;
	longitud=0;
}

Lista::~Lista()
{
}



void Lista::insertar(Proceso v)
{
	pnodoLista nuevo;
	nuevo= new NodoLista(v);
	if(ultimo)
		ultimo->siguiente = nuevo;
		
	ultimo=nuevo;
	
	if(!primero)
		primero=nuevo;
	longitud++;
}
Proceso Lista::eliminar()
{}
void Lista::mostrar()
{}
Proceso Lista::verPrimero()
{}
int Lista::getLongitud()
{}
void Lista::vaciar()
{}