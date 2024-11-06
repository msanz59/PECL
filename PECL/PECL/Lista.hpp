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
	void mostrar();
	int getLongitud();
	void vaciar();
	void buscarNombre(char* nom);
	void mostrarlinea(Proceso p);
	void buscarProcesos(bool menormayor);
	Proceso eliminarproceso(int num);
	void buscarusuario(char* nom);
	void cambiarprioridad(int num);
	
private:
	pnodoLista primero, ultimo;
	int longitud;

};

#endif // LISTA_HPP
