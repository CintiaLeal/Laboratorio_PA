#include "../class/.h/pago.h"
#include <iostream>

using namespace std;

//constructores
Pago::Pago(){}

Pago::Pago(dtFecha fechaV, dtFecha fechaC, string metodoPago, bool activa){
    this->fechaV =  fechaV;
    this->fechaContrato = fechaC;
    this->metodoPago = metodoPago;
    this->activa = activa;
}

//gets
dtFecha Pago::getFechaV(){
    return this->fechaV;
}

dtFecha Pago::getFechaC(){
    return this->fechaContrato;
}

string Pago::getMetodoPago(){
    return this->metodoPago;
}

bool Pago::getActiva(){
    return this->activa;
}

//sets
void Pago::setFechaV(dtFecha FechaV){
    this->fechaV = FechaV;
}

void Pago::setFechaC(dtFecha FechaC){
    this->fechaContrato = FechaC;
}

void Pago::setMetodoPago(string metodoPago){
    this->metodoPago = metodoPago;
}

void Pago::setActiva(bool activa){
    this->activa = activa;
}

//methods
//primero hay que implementar las colecciones