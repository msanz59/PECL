#include "Proceso.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

Proceso::Proceso()
{
	this->tipo = (rand() %2);
	this->numerounico = (rand() % 700 + 300); //num entre 300 y 999
	this->estado = 0;
	setNombrerand();
}

Proceso::~Proceso()
{
}
int Proceso::getNumerounico()
{
	return this->numerounico;
}
int Proceso::getPrioridad()
{
	return this->prioridad;	
}
bool Proceso::getEstado()
{ return this->estado; }
bool Proceso::getTipo()
{ return this->tipo; }
char* Proceso::getNombre()
{ 
	
	return this->nombre; }
void Proceso::setNumerounico(int num)
{ 
		if(num <= 300)
			this->numerounico = num;
		else
			this->numerounico = 0;
}
void Proceso::setNombrerand()
{
		this->nombre[0] = 'u';
		this->nombre[1] = 's';
		this->nombre[2] = 'e';
		this->nombre[3] = 'r';
		
		for (int i = 0; i<2; i++){
			int random_char = rand() % 10;
			this->nombre[i+4] = '0' + random_char;
			
		}
		this->nombre[6] = '\0';
}
void Proceso::toString()
{
	cout << "El proceso cuyo PID es "<< this->getNumerounico() << " es de tipo ";
	if (tipo==1)
		cout << "Tiempo real";
	else
		cout << "Normal";
	cout << endl; 
}
void Proceso::setombrenorandom()
{}
void Proceso::setEstado(bool est)
{
	this->estado = est;
}
void Proceso::setPrioridad(int num)
{
	this->prioridad = num;
}
void Proceso::setTipo(int tip)
{}