#include "../../class/.h/Partida.h"
#include <iostream>

using namespace std;

//constructores
Partida::Partida(){}

Partida::Partida(int idPartida, Videojuego * vid){
    this->idPartida = idPartida;
    this->videojuego = vid;
    this->activa = true;
}

//destructor
Partida::~Partida(){}
//gets
int Partida::getIdPartida(){
    return this->idPartida;
}

bool Partida::getActiva(){
    return this->activa;
}

bool Partida::getIndividual(){
    return this->individual;
}

Videojuego * Partida::getVideojuego(){
    return this->videojuego;
}

//sets
void Partida::setIdPartida(int idPartida){
    this->idPartida = idPartida;
}

void Partida::setActiva(bool b){
    this->activa = b;
}

void Partida::setIndividual(bool b){
    this->individual = b;
}

void Partida::setVideoJuego(Videojuego * v){
    this->videojuego = v;
}


//methods
/*
void eliminarPartida(){}
dtMostrarPartida getMostrarPartida(){}
void confirmarPartida(){}
void continuar(){}*/