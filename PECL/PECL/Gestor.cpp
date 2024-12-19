#include "Gestor.hpp"
#include "Proceso.hpp"
#include "Pila.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;
Gestor::Gestor()
{
	praiz.setPrioridad(100);
	arbol.insertar(praiz);
}

void Gestor::genera12Procesos()
{
	for (int i = 0; i<12; i++){
		bool esunico = true;
		Proceso proceso;
		for(int num : PIDV){
		if(proceso.getNumerounico() == num){
			esunico = false;
		}
		
	}
		if(esunico){
			if(pila.getLongitud() < 48){
			 PIDV.push_back(proceso.getNumerounico());	
			} 
			this->pila.insertar(proceso);
			
		}
		else{
			i--;
		}
		
	}
	
	
	//for(int num : PIDV){
		//cout << num << " ";
	//}
	

}
void Gestor::borraProcesosColas()
{
	this->gpu0.vaciar();
	vector<int> PIDgpu0 = this->gpu0.getPIDSborrados();
	for(int num : PIDgpu0){
		reutilizarPID(num);
	}
	gpu0.borrarPIDSborrados();
	
	this->gpu1.vaciar();
	vector<int> PIDgpu1 = this->gpu1.getPIDSborrados();
	for(int num : PIDgpu1){
		reutilizarPID(num);
	}
	gpu1.borrarPIDSborrados();
	
	this->gpu2.vaciar();
	vector<int> PIDgpu2 = this->gpu2.getPIDSborrados();
	for(int num : PIDgpu2){
		reutilizarPID(num);
	}
	gpu2.borrarPIDSborrados();
	
	this->gpu3.vaciar();
	vector<int> PIDgpu3 = this->gpu3.getPIDSborrados();
	for(int num : PIDgpu3){
		reutilizarPID(num);
	}
	gpu3.borrarPIDSborrados();
	

}
void Gestor::borraProcesosPila()
{
	this->pila.vaciar();
	vector<int> PIDPila = this->pila.getPIDSborrados();
	for(int num : PIDPila){
		reutilizarPID(num);
	}
	this->pila.borrarPIDSborrados();
}
void Gestor::buscarProcesoPorNombreUsuario()
{
	string nom;
	cout << "Introduce el nombre de usuario: ";
	cin >> nom;
	cout << "PID         Usuario         Tipo         Estado         Prioridad" << endl;
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
	Proceso p1 = normal.eliminarproceso(numero);
	Proceso p2 = tiemporeal.eliminarproceso(numero);
	if(p1.getPrioridad() != 1999){
		pila.insertar(p1);
	}
	if(p2.getPrioridad() != 1999){
		pila.insertar(p2);
	}
	
	
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
	this->borraProcesosColas();
	this->borraProcesosPila();
	this->tiemporeal.vaciar();
	this->normal.vaciar();
	PIDV.clear();
	arbol.~Arbol();

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
void Gestor::reutilizarPID(int pid)
{
	vector<int> PIDVaux;
	for(int num : PIDV){
		if (num != pid){
			PIDVaux.push_back(num);
		}
	}
	PIDV.clear();
	PIDV = PIDVaux;
}

void Gestor::pintarArbol()
{
	
	arbol.~Arbol();
	arbol.insertar(praiz);
	for (int i = 1; i<=99; i++){
		Preal.push_back(i);
	}
	for (int i = 101; i<=139; i++){
		Pnormal.push_back(i);
	}
	random_device rd;
	mt19937 gen(rd());
	shuffle(Preal.begin(), Preal.end(), gen);
	shuffle(Pnormal.begin(), Pnormal.end(), gen);
	
	int lon = pila.getLongitud();
	for (int i = 0; i<lon; i++){
		Proceso p = pila.extraer();
		if (p.getTipo() == 0){
			int nump = Pnormal[Pnormal.size() -1];
			Pnormal.pop_back();
			p.setPrioridad(nump);
			arbol.insertar(p);
		}
		else{
			int nump = Preal[Preal.size() -1];
			Preal.pop_back();
			p.setPrioridad(nump);
			arbol.insertar(p);
		}
		
	}
	arbol.dibujar();	
}

int Gestor::ProcesosEnArbol()
{
	return this->arbol.getprocesosenarbol();
}

void Gestor::mostrarMayorMenorArbol()
{
	arbol.procesoMayor();
	arbol.procesoMenor();
}

void Gestor::mostrarInorden()
{
	arbol.inorden();
}

void Gestor::mostrarTiemporeal()
{
	arbol.mostrarTiemporeal();
}
void Gestor::mostrarNormal()
{
	arbol.mostrarNormal();
}

void Gestor::eliminarPrioridadArbol()
{
	int numero;
	
	cout << "Introduca la prioridad del proceso que quieres eliminar: " << endl;
	cin >> numero;
	cout << "Arbol antes de eliminar el proceso: " << endl;
	arbol.dibujar();
	cout << "Arbol despues de eliminar el proceso: " << endl;
	if (numero != 100){
		arbol.eliminarPorPrioridad(numero);
		pila.insertar(arbol.getElimin());
		arbol.dibujar();
	}
	else{
		cout << "Numero no valido" << endl;
	}

	
	
	
}

void Gestor::mostrarProcesosHoja()
{
	arbol.mostrarHoja();
}