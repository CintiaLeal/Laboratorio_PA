#include "class/.h/Partida.h"
#include <iostream>

using namespace std;

//constructores
Partida::Partida(){}

Partida::Partida(int idPartida, dtPartida* partida, dtUsuario* jugadores, dtVideojuego* videojuego){
    this->idPartida = idPartida;
    this->partida = partida;
    this->jugadores = jugadores;
    this->videojuego = videojuego;
}

//destructor
Partida::~Partida(){}

//gets
int Partida::getIdPartida(){
    return this->idPartida;
}

dtPartida* Partida::getPartida(){
    return this->partida;
}

dtUsuario* Partida::getJugadores(){
    return this->jugadores;
}

dtVideojuego* Partida::getVideojuego(){
    return this->videojuego;
}

//sets
void Partida::setIdPartida(int idPartida){
    this->idPartida = idPartida;
}

void Partida::setPartida(dtPartida * partida){
    this->partida = partida;
}

void Partida::setJugadores(dtUsuario * jugadores){
    this->jugadores = jugadores;
}

void Partida::setVideojuego(dtVideojuego * videojuego){
    this->videojuego = videojuego;
}

//methods
void eliminarPartida(){}

dtMostrarPartida getMostrarPartida(){}

void confirmarPartida(){}

void continuar(){}