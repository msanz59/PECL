#ifndef LISTA_HPP
#define LISTA_HPP
#include "Proceso.hpp"
#include "NodoLista.hpp"
#include <string>
#include <vector>

using namespace std;
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
	void buscarusuario(string nom);
	void cambiarprioridad(int num);
	vector<int> getPIDSborrados();
	void borrarPIDSborrados();
	
private:
	pnodoLista primero, ultimo;
	int longitud;
	vector<int> PIDLborrados;

};

#endif // LISTA_HPP
