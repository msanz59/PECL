#include "NodoCola.hpp"
#include "Proceso.hpp"
#include <string>
#include <vector>
#include <random>
#include <algorithm>

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
	vector<int> getPIDSborrados();
	void borrarPIDSborrados();
	
private:
	pnodoCola primero, ultimo;
	int longitud;
	int numprnor;
	int numprtr;
	vector<int> PIDCborrados;
	vector<int> Prealcola;
	vector<int> Pnormalcola;

};

