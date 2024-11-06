#include "Gestor.hpp"
#include "Proceso.hpp"
#include "Pila.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
Gestor::Gestor()
{
	
}

void Gestor::genera12Procesos()
{
	for (int i = 0; i<12; i++){
		Proceso proceso;
		this->pila.insertar(proceso);
	}
	cout<<"hola mundo";

}
void Gestor::borraProcesosColas()
{
	this->gpu0.vaciar();
	this->gpu1.vaciar();
	this->gpu2.vaciar();
	this->gpu3.vaciar();

}
void Gestor::borraProcesosPila()
{
	this->pila.vaciar();
}
void Gestor::buscarProcesoPorNombreUsuario()
{
	char nom[6];
	cout << "Introduce el nombre de usuario: ";
	cin >> nom;
	normal.buscarusuario(nom);
	tiemporeal.buscarusuario(nom);
}
void Gestor::buscarProcesos()
{
	normal.buscarProcesos(1);
	tiemporeal.buscarProcesos(0);
}
void Gestor::cambiarPrioridadProcesoPorPID()
{
	cout << "Introduce PID: ";
	int antiguopid;
	cin >> antiguopid;
	normal.cambiarprioridad(antiguopid);
	tiemporeal.cambiarprioridad(antiguopid);
}
void Gestor::eliminarProcesoPorPID()
{
	int numero;
	
	cout << "Introduce el PID: " << endl;
	cin >> numero;
	pila.insertar(normal.eliminarproceso(numero));
	pila.insertar(tiemporeal.eliminarproceso(numero));
}
void Gestor::encolarProcesos()
{
	int lon = pila.getLongitud();
	for (int i = 0; i<lon; i++){
		Proceso p = pila.extraer();
		if(p.getTipo()==0){
			if(gpu0.getLongitud() > gpu1.getLongitud()){
				p.setPrioridad(1); 
				gpu1.insertar(p);
				
				
			}
			else
				gpu0.insertar(p);
				
		}
		else{
			if(gpu2.getLongitud() > gpu3.getLongitud()){
				p.setPrioridad(1);
				gpu3.insertar(p);
				
				
			}
			else
				gpu2.insertar(p);
				
		}
			
	}
		
}
void Gestor::enlistarProcesos()
{
	int lon = gpu0.getLongitud();
	for (int i = 0; i<lon; i++){
		Proceso p = gpu0.eliminar();
		normal.insertar(p);
	}
	lon = gpu1.getLongitud();
	for (int i = 0; i<lon; i++){
		Proceso p = gpu1.eliminar();
		normal.insertar(p);
	}
	lon = gpu2.getLongitud();
	for (int i = 0; i<lon; i++){
		Proceso p = gpu2.eliminar();
		tiemporeal.insertar(p);
	}
	lon = gpu3.getLongitud();
	for (int i = 0; i<lon; i++){
		Proceso p = gpu3.eliminar();
		tiemporeal.insertar(p);
			
	}
	return;
}
void Gestor::muestraProcesos()
{
	this->pila.mostrar();
}
void Gestor::muestraProcesosGPUs0y1()
{
	cout << "Procesos de la GPU0: \n";
	gpu0.mostrar();
	cout << "Procesos de la GPU1: \n";
	gpu1.mostrar();
}
void Gestor::muestraProcesosGPUs2y3()
{
	cout << "Procesos de la GPU2: \n";
	gpu2.mostrar();
	cout << "Procesos de la GPU3: \n";
	gpu3.mostrar();
}
void Gestor::muestraProcesosNormal()
{
	normal.mostrar();
}
void Gestor::muestraProcesosTiempoReal()
{
	tiemporeal.mostrar();
}
void Gestor::reiniciar()
{
	
}
int Gestor::ProcesosEnPila()
{
	return this->pila.getLongitud();
}
int Gestor::ProcesosEnGPU0()
{
	return this->gpu0.getLongitud();
}
int Gestor::ProcesosEnGPU1()
{
	return this->gpu1.getLongitud();
}
int Gestor::ProcesosEnGPU2()
{
	return this->gpu2.getLongitud();
}
int Gestor::ProcesosEnGPU3()
{
	return this->gpu3.getLongitud();
}
int Gestor::ProcesosEnListaNormal()
{
	return this->normal.getLongitud();
}
int Gestor::ProcesosEnListaTiempoReal()
{
	return this->tiemporeal.getLongitud();
}
Gestor::~Gestor()
{
}



