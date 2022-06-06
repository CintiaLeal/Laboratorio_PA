#include <Implementacion/.h>
#include <iostream>
//Falta el include

using namespace std;

//constructores
Suscripcion::Suscripcion(){}

Suscripcion::Suscripcion(string nombre, int precio){
    this->nombre = nombre;
    this->precio = precio;
}

//gets
string Suscripcion::getNombre(){
    return this->nombre;
}

int Suscripcion::getPrecio(){
    return this->precio;
}

//sets
void Suscripcion::setNombre(string nom){
    this->nombre = nom;
}

void Suscripcion::setPrecio(int precio){
    this->precio = precio;
}
