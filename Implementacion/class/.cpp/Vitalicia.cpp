#include <iostream>
#include "class/.h/Vitalicia.h"

using namespace std;

//constructor
Vitalicia::Vitalicia(){}

Vitalicia::Vitalicia(string nombre, int precio){
    this->nombre = nombre;
    this->precio = precio;
}

//methods
bool Vitalicia::buscarSuscripcion(){
    
}

string Vitalicia::getTipo(){
    return "Vitalicia";
}