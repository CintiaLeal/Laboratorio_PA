#include "../.h/dtMostrarPartida.h"
#include <iostream>

using namespace std;

//constructores
dtMostrarPartida::dtMostrarPartida(){}

dtMostrarPartida::dtMostrarPartida(string nombreVideojuego, dtPartida * partida){
    this->nombreVideojuego =  nombreVideojuego;
    this->partida = partida;
}

//gets
string dtMostrarPartida::getNombreVideojuego(){
    return this->nombreVideojuego;
}

dtPartida *dtMostrarPartida::getPartida(){
    return this->partida;
}


