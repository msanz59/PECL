#include "Lista.hpp"
#include <cstring>
Lista::Lista()
{
	primero=nullptr;
	ultimo=nullptr;
	longitud=0;
}

Lista::~Lista()
{
	
}



void Lista::insertar(Proceso v)
{
	v.setEstado(true);
	pnodoLista nuevo;
	nuevo= new NodoLista(v);
	if(ultimo){
		ultimo-> siguiente = nuevo;
		nuevo-> anterior = ultimo;
	}
	if(!primero)
		primero=nuevo;
		
	ultimo=nuevo;
	longitud++;
}

void Lista::mostrar()
{
		pnodoLista n = primero;
		
		if (!n){
			return;
		}
		else{
			
			cout << "PID         Usuario         Tipo         Estado         Prioridad" << endl;
			
			while(n){
				Proceso p = n->valor;
				mostrarlinea(p);
				n = n->siguiente;
			}
		}
}

int Lista::getLongitud()
{
	return this->longitud;
}
void Lista::vaciar()
{
	NodoLista* n = primero;
	
	while (n != nullptr){
		pnodoLista siguiente = n->siguiente;
		delete n;
		n = siguiente;
		longitud--;
	}
}

void Lista::buscarNombre(char* nom)
{
	pnodoLista n = primero;
	int veces = 0;
	if(!n){
		return;
	}
	Proceso a;
	while (n){
		a = n->valor;
		if (a.getNombre() == nom){
			veces++;
			
		}
	}
	
}

void Lista::mostrarlinea(Proceso p)
{
	cout << p.getNumerounico() << "         " << p.getNombre() << "          ";
	if(p.getTipo()==1)
	{
		cout << "T.Real       ";
	}
	else{
		cout << "Normal       ";
	}
	if(p.getEstado()==0)
	{
		cout << "Parado         ";
	}
	else{
		cout << "Ejec.          ";
	}
	cout << p.getPrioridad() << endl;
	
}

void Lista::buscarProcesos(bool menormayor)
{
	pnodoLista sig = primero->siguiente;
	if(menormayor == 1){
		pnodoLista menor = primero;
		for (int i = 0; i<longitud - 1; i++){
		if(sig->valor.getPrioridad() < menor->valor.getPrioridad()){
			menor = sig;
			
		}
		sig = sig->siguiente;
	}
		int x = menor->valor.getNumerounico();
		cout << "Normal menor prioridad ->      El proceso cuyo PID es ";
		cout << x << " es de tipo normal, su estado es ejecución y su prioridad es: " << menor->valor.getPrioridad(); 
		cout << endl;
	}
	else{
		pnodoLista mayor = primero;
		for (int i = 0; i<longitud - 1; i++){
		if(sig->valor.getPrioridad() > mayor->valor.getPrioridad()){
			mayor = sig;
			
		}
		
		sig = sig->siguiente;
	}
	int x = mayor->valor.getNumerounico();
	cout << "Tiempo real mayor prioridad -> El proceso cuyo PID es " << x << " es de tipo tiempo real, su estado es ejecución y su prioridad es: " << mayor->valor.getPrioridad() << endl;

	}
	
}

Proceso Lista::eliminarproceso(int num)
{
	pnodoLista n = primero;
	
	while(n){
		if(n->valor.getNumerounico() == num){
			cout << "PID         Usuario         Tipo         Estado         Prioridad" << endl;
			
			
			Proceso eliminado = n->valor;
			eliminado.setEstado(0);
			mostrarlinea(eliminado);
			if(n->anterior){
				n->anterior->siguiente = n->siguiente;
			}
			else{
				primero = n->siguiente;
			}
			if(n->siguiente){
				n->siguiente->anterior = n->anterior;
			}
			else{
				ultimo = n->anterior;
			}
			
			longitud--;
			return eliminado;
		}
		n = n->siguiente;
	}
	
	
}

void Lista::buscarusuario(char nom[6])
{
	int i = 0;
	pnodoLista n = primero;
	Proceso p = n->valor;
	while(n){
		if(strncmp(p.getNombre(), nom, 6) == 0){
			Proceso p = n->valor;
			mostrarlinea(p);
			p.toString();
		}
		n = n->siguiente;
		i++;
	}
	if (i == 0){
		cout << endl;
	}
}

void Lista::cambiarprioridad(int num)
{
	pnodoLista n = primero;
	while(n){
		if(n->valor.getNumerounico() == num){
			Proceso p = n->valor;
			cout << "PID         Usuario         Tipo         Estado         Prioridad" << endl;
			mostrarlinea(p);
			cout << "Introduzca la nueva prioridad: ";
			int num;
			cin >> num;
			p.setPrioridad(num);
			mostrarlinea(p);
			return;

		}
		n = n->siguiente;
	}
}