#include "Cola.hpp"

Cola::Cola()
{
	primero=NULL;
	ultimo=NULL;
	longitud=0;
}
void Cola::insertar(Proceso v)
{
	pnodoCola nuevo;
	nuevo= new NodoCola(v);
	if(ultimo)
		ultimo->siguiente = nuevo;
		
	ultimo=nuevo;
	
	if(!primero)
		primero=nuevo;
	longitud++;
}
void Cola::mostrar()
{
	pnodoCola aux = primero;
	cout << "\tEl contenido de la cola es: \n" ;
	while(aux){
		cout << "->	";
		aux->valor.toString();
		aux = aux->siguiente;
	}
	cout<<endl;
}
Proceso Cola::eliminar()
{
	pnodoCola nodo;
	Proceso v;
	nodo=primero;
	//if(!nodo)
		//return 0;
	primero= nodo->siguiente;
	v=	nodo->valor;
	delete nodo;
	if(!primero)
		ultimo= NULL;
	longitud--;
	return v;	
}
Proceso Cola::verPrimero(){
	primero->valor.toString();
	return primero->valor;
}
int Cola::getLongitud(){
	return this->longitud;
}
void Cola::vaciar(){
	while(primero){
		eliminar();
	}
}
Cola::~Cola()
{
	while(primero){
		eliminar();
	}
}

