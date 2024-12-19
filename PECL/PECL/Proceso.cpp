#include "Proceso.hpp"

#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

Proceso::Proceso()
{
    this->tipo = (rand() % 2);
    int numx = (rand() % 700 + 300);
    this->numerounico = numx; // num entre 300 y 999
    this->estado = 0;
    this->nombre = "";
    setNombrerand();
}

Proceso::~Proceso() {}
int Proceso::getNumerounico() { return this->numerounico; }
int Proceso::getPrioridad() { return this->prioridad; }
bool Proceso::getEstado() { return this->estado; }
bool Proceso::getTipo() { return this->tipo; }
string Proceso::getNombre() { return this->nombre; }
void Proceso::setNumerounico(int num)
{
    if(num <= 300)
        this->numerounico = num;
    else
        this->numerounico = 0;
}
void Proceso::setNombrerand()
{
    nombre = "user";
    for(int i = 0; i < 2; i++) {
        int random_char = rand() % 10;
        nombre += '0' + random_char; // Añadir el carácter generado al string
    }
}
void Proceso::toString()
{
    cout << "El proceso cuyo PID es " << this->getNumerounico() << " es de tipo ";
    if(tipo == 1)
        cout << "Tiempo real";
    else
        cout << "Normal";
    cout << endl;
}

void Proceso::setEstado(bool est) { this->estado = est; }
void Proceso::setPrioridad(int num) { this->prioridad = num; }
void Proceso::setTipo(int tip) {}