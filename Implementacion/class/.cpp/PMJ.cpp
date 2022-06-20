#include "../.h/PMJ.h"
//Constructores
PMJ::PMJ(){};

PMJ::PMJ(dtFecha* f, Jugador * j){
    this->horaSalida = f;
    this->j = j;
}

//gets
dtFecha * PMJ::getHoraSalida(){
    return this->horaSalida;
}

Jugador * PMJ::getJ(){
    return this->j;
}

//sets
void PMJ::setHoraSalida(dtFecha * f){
    this->horaSalida = f;
}

void PMJ::setJ(Jugador * j){
    this->j = j;
}

