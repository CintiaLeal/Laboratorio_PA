#include "../.h/Pago.h"
#include <iostream>

using namespace std;

//constructores
Pago::Pago(){}

Pago::Pago(dtFecha * fechaV, dtFecha * fechaC, string metodoPago, bool activa, Suscripcion * suscripcion){
    this->fechaV =  fechaV;
    this->fechaContrato = fechaC;
    this->metodoPago = metodoPago;
    this->activa = activa;
    this->suscripcion = suscripcion;
}

//gets
dtFecha * Pago::getFechaV(){
    return this->fechaV;
}

dtFecha * Pago::getFechaC(){
    return this->fechaContrato;
}

string Pago::getMetodoPago(){
    return this->metodoPago;
}

bool Pago::getActiva(){
    return this->activa;
}

Suscripcion * Pago::getSuscripcion(){
    return this->suscripcion;
}

//sets
void Pago::setFechaV(dtFecha * FechaV){
    this->fechaV = FechaV;
}

void Pago::setFechaC(dtFecha * FechaC){
    this->fechaContrato = FechaC;
}

void Pago::setMetodoPago(string metodoPago){
    this->metodoPago = metodoPago;
}

void Pago::setActiva(bool activa){
    this->activa = activa;
}

void Pago::setSuscripcion(Suscripcion * s){
    this->suscripcion = s;
}

Videojuego * Pago::getJuego(){
    this->suscripcion->getVideojuego();
}

//methods
//primero hay que implementar las colecciones