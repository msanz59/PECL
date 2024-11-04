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
void Proceso::toString()
{
	cout << "Nombre: " << this->nombre << " Numero Unico: " << this->numerounico << " Estado: " << " Tipo: ";
	if (tipo==1)
		cout << "Tiempo real";
	else
		cout << "Normal";
	cout << " Estado: ";
	if (estado==1)
		cout << "Ejecucion";
	else
		cout << "Parado";
	cout << endl; 
}
void Proceso::setombrenorandom()
{}
void Proceso::setEstado(bool est)
{}
void Proceso::setPrioridad(int num)
{}
void Proceso::setTipo(int tip)
{}