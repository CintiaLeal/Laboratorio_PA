#include "../../class/.h/Partida.h"
#include <iostream>

using namespace std;

//constructores
dtPartida::dtPartida(){}

dtPartida::dtPartida(int id, dtFecha * fecha, float duracion){
    this->id = id;
    this->fecha = fecha;
    this->duracion = duracion;
}

//destructor
dtPartida::~dtPartida(){}
//gets

dtFecha * dtPartida::getFecha(){
    return this->fecha;
}
float  dtPartida::getDuracion(){
    return this->duracion;
}

int  dtPartida::getId(){
    return this->id;
}

void dtPartida::setDuracion(float d){
    this->duracion =  d;
}

void dtPartida::imprimirFecha(dtFecha * fecha){
   cout<<"DIA: "<< fecha->getDia()<<endl;  
   cout<<"MES: "<< fecha->getMes()<<endl; 
   cout<<"ANIO: "<< fecha->getAnio()<<endl; 
   cout<<"HORA: "<< fecha->getHora()<<endl; 
   cout<<"MINUTO: "<< fecha->getMinuto()<<endl; 
}

void dtPartida::setId(int d){
    this->id = d;
}