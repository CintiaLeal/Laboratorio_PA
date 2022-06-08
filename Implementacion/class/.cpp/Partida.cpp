#include "../../class/.h/Partida.h"
#include <iostream>

using namespace std;

//constructores
Partida::Partida(){}

Partida::Partida(int idPartida, dtPartida * p){
    this->idPartida = idPartida;
    this->partida = p;
    this->jugadores = new OrderedDictionary();
    this->videojuego = new OrderedDictionary();
}

//destructor
Partida::~Partida(){}
//gets
int Partida::getIdPartida(){
    return this->idPartida;
}
dtPartida *Partida::getPartida(){
    return this->partida;
}
//sets
void Partida::setIdPartida(int idPartida){
    this->idPartida = idPartida;
}
void Partida::setPartida(dtPartida *p){
    this->partida = p;
}

//methods
void eliminarPartida(){}
dtMostrarPartida getMostrarPartida(){}
void confirmarPartida(){}
void continuar(){}