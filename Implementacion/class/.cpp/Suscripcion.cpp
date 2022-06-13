#include <class/.h/Suscripcion.h>
#include <iostream>
//Falta el include

using namespace std;

//constructores
Suscripcion::Suscripcion(){}

Suscripcion::Suscripcion(string nombre, int precio, string periodo){
    this->nombre = nombre;
    this->precio = precio;
    this->periodo = periodo;
}

//gets
string Suscripcion::getNombre(){
    return this->nombre;
}

int Suscripcion::getPrecio(){
    return this->precio;
}

string Suscripcion::getPeriodo(){
    return this->periodo;
}


//sets
void Suscripcion::setNombre(string nom){
    this->nombre = nom;
}

void Suscripcion::setPrecio(int precio){
    this->precio = precio;
}

void Suscripcion::setPeriodo(string periodo){
    this->periodo = periodo;
}
