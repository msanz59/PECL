#include "NodoPila.hpp"
#include "Proceso.hpp"
#include <string>

NodoPila::NodoPila(Proceso v, NodoPila* sig)
{
	valor = v;
	siguiente = sig;
}

NodoPila::~NodoPila()
{
	
}

