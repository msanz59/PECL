#include "Cola.hpp"
#include <string>

Cola::Cola()
{
	primero=NULL;
	ultimo=NULL;
	longitud=0;
	numprnor=-19;
	numprtr=0;
}
void Cola::insertar(Proceso v)
{
	if(v.getTipo()==0)
	{
		if (numprtr > 99){
			numprtr = 0;
		}
		v.setPrioridad(v.getPrioridad() + numprtr);
		numprtr = numprtr + 2;
	}
	else{
		if (numprnor > 19){
			numprnor = -19;
		}
		v.setPrioridad(v.getPrioridad() + 120 + numprnor);
		numprnor = numprnor + 2;
	}
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
	
	while(aux){
		
		Proceso p = aux->valor;
		cout << "El proceso cuyo PID es " << p.getNumerounico() << " es de tipo ";
		if (p.getTipo()==1){
		cout << "Tiempo real, ";
		
		}
		else{
		cout << "Normal, ";
		
		}
		cout << "su estado es ";
		if(p.getEstado()==0)
	{
		cout << "Parado";
	}
	else{
		cout << "Ejec.";
	}
		cout << " y su prioridad es: " << p.getPrioridad();
		cout << endl;
		
		
		
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
		Proceso paux = primero->valor;
		PIDCborrados.push_back(paux.getNumerounico());
		eliminar();
	}
}
Cola::~Cola()
{
	while(primero){
		eliminar();
	}
}



vector<int> Cola::getPIDSborrados()
{
	return this->PIDCborrados;
}
void Cola::borrarPIDSborrados()
{
	PIDCborrados.clear();
}