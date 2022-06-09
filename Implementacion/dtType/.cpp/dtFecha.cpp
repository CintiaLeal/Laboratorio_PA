#include "../.h/dtFecha.h"
#include <iostream>

using namespace std;

//constructores
dtFecha::dtFecha(){}

dtFecha::dtFecha(int dia,int mes,int anio, int hora, int minuto){
    this->dia =  dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
}

//gets
int dtFecha::getDia(){
    return this->dia;
}
int dtFecha::getMes(){
    return this->mes;
}
int dtFecha::getAnio(){
    return this->anio;
}
int dtFecha::getHora(){
    return this->hora;
}
int dtFecha::getMinuto(){
    return this->minuto;
}

