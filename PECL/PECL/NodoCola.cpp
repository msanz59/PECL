#include "NodoCola.hpp"
#include <string>

NodoCola::NodoCola(Proceso v, NodoCola*sig)
{
	valor=v;
	siguiente=sig;
}

NodoCola::~NodoCola()
{
}

