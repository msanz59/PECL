#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "NodoArbol.hpp"
#include "Proceso.hpp"
#include <string>
#include <vector>
using namespace std;

class Arbol
{
public:
    Arbol();
    void insertar(Proceso val);
    void pintar();
    void dibujar();
    ~Arbol();
	int getprocesosenarbol();
	void inorden();
	void procesoMenor();
	void procesoMayor();
	void mostrarTiemporeal();
	void mostrarNormal();
	void eliminarPorPrioridad(int PID);
	void mostrarHoja();
	Proceso getElimin();
	
private:
    pnodoAbb raiz;
    pnodoAbb insertar(pnodoAbb, Proceso);
    void pintar(pnodoAbb);
    int altura(pnodoAbb);
	void procesoMenor(pnodoAbb nodo);
	
	void procesoMayor(pnodoAbb nodo);
	void inorden(pnodoAbb nodo);
	void mostrarTiemporeal(pnodoAbb nodo);
	void mostrarNormal(pnodoAbb nodo);
	void eliminarPorPrioridad(int PID, pnodoAbb& nodo);
	void mostrarHoja(pnodoAbb nodo);
    void dibujarNodo(vector<string>& output, vector<string>& linkAbove, pnodoAbb nodo, int nivel, int minPos,
                     char linkChar);
	int procesosenarbol;
	Proceso elimin;
};

#endif // ARBOL_HPP
