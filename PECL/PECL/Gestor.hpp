#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Arbol.hpp"
#include <string>
#include <vector>
#include <random>

class Gestor
{
public:
	Gestor();
	~Gestor();
	void genera12Procesos();
	void muestraProcesos();
	void borraProcesosPila();
	void encolarProcesos();
	void muestraProcesosGPUs0y1();
	void muestraProcesosGPUs2y3();
	void borraProcesosColas();
	void enlistarProcesos();
	void muestraProcesosNormal();
	void muestraProcesosTiempoReal();
	void buscarProcesos();
	void buscarProcesoPorNombreUsuario();
	void eliminarProcesoPorPID();
	void cambiarPrioridadProcesoPorPID();
	void reiniciar();
	void reutilizarPID(int pid);
	void pintarArbol();
	void mostrarMayorMenorArbol();
	void mostrarInorden();
	void mostrarTiemporeal();
	void mostrarNormal();
	void eliminarPrioridadArbol();
	void mostrarProcesosHoja();
	int ProcesosEnPila();
	int ProcesosEnGPU0();
	int ProcesosEnGPU1();
	int ProcesosEnGPU2();
	int ProcesosEnGPU3();
	int ProcesosEnListaNormal();
	int ProcesosEnListaTiempoReal();
	int ProcesosEnArbol();
	
	
private:
	Pila pila;
	Cola gpu0;
	Cola gpu1;
	Cola gpu2;
	Cola gpu3;
	Lista normal;
	Lista tiemporeal;
	Arbol arbol;
	Proceso praiz;
	vector<int> PIDV;
	vector<int> Preal;
	vector<int> Pnormal;
	

};

#endif // GESTOR_HPP
