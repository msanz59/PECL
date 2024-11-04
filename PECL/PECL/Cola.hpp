#include "NodoCola.hpp"
#include "Proceso.hpp"

class Cola
{
public:
	Cola();
	~Cola();
	
	void insertar(Proceso v);
	Proceso eliminar();
	void mostrar();
	Proceso verPrimero();
	int getLongitud();
	void vaciar();
	
private:
	pnodoCola primero, ultimo;
	int longitud;

};

