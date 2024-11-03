#include "Proceso.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>

Proceso::Proceso()
{
	this->tipo = (rand() %2);
	setNumerounico(rand() % 700 + 300); //num entre 300 y 999
	this->estado = (rand() %2);
	setNombre();
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
char Proceso::getNombre()
{ return this->nombre[10]; }
void Proceso::setNumerounico(int num)
{ 
		if(num <= 300)
			this->numerounico = num;
		else
			this->numerounico = 0;
}
void Proceso::setNombre()
{
		for (int i = 0; i<9; i++){
			int random_char = rand() % 62;
			
			if(random_char < 26)
				this->nombre[i] = 'A' + random_char;
			else if(random_char < 52)
				this->nombre[i] = 'a' + (random_char - 26);
			else
				this->nombre[i] = '0' + (random_char - 52);
		}
		this->nombre[9] = '\0';
}
void Proceso::setEstado(bool est)
{}
void Proceso::setPrioridad(int num)
{}
void Proceso::setTipo(int tip)
{}