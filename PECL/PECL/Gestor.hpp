#ifndef GESTOR_HPP
#define GESTOR_HPP
#include "Pila.hpp"
#include "Cola.hpp"

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
	int ProcesosEnPila();
	int ProcesosEnGPU0();
	int ProcesosEnGPU1();
	int ProcesosEnGPU2();
	int ProcesosEnGPU3();

	
private:
	Pila pila;
	Cola gpu0;
	Cola gpu1;
	Cola gpu2;
	Cola gpu3;
	

};

#endif // GESTOR_HPP
