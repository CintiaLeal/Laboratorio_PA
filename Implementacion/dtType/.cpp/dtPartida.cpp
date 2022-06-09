#include "../../class/.h/Partida.h"
#include <iostream>

using namespace std;

//constructores
dtPartida::dtPartida(){}

dtPartida::dtPartida(int idPartida, dtFecha * fecha, float duracion){
    this->idPartida = idPartida;
    this->fecha = fecha;
    this->duracion = duracion;
}

//destructor
dtPartida::~dtPartida(){}
//gets
int dtPartida::getIdPartida(){
    return this->idPartida;
}
dtFecha * dtPartida::getFecha(){
    return this->fecha;
}
float  dtPartida::getDuracion(){
    return this->duracion;
}

