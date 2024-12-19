#include "NodoArbol.hpp"

NodoArbol::NodoArbol(Proceso dato)
{
    this->dato = dato;
    this->izq = nullptr;
    this->der = nullptr;
}

NodoArbol::~NodoArbol() {}

