#include "../.h/VJ.h"
//Constructores
VJ::VJ(){};

VJ::VJ(int numero, Jugador * jugador){
    this->puntaje = numero;
    this->jug = jugador;
}

//gets
int VJ::getPuntaje(){
    return this->puntaje;
}

Jugador * VJ::getJugador(){
    return this->jug;
}

//sets
void VJ::setPuntaje(int puntaje){
    this->puntaje = puntaje;
}

void VJ::setJugador(Jugador * jug){
    this->jug = jug;
}