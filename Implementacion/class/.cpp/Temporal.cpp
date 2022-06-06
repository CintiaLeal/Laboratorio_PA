#include <iostream>
#include "class/.h/Temporal.h"

//constructores
Temporal::Temporal(){}

Temporal::Temporal(string nombre, int precio, string periodo){
    this->nombre = nombre;
    this->precio = precio;
    this->periodo = periodo;
}

//gets
string Temporal::getPeriodo(){
    return this->periodo;
}

//sets
void Temporal::setPeriodo(string periodo){
    this->periodo = periodo;
}

//methods
string Temporal::getTipo(){
    return this->periodo;
}



