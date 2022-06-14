#include "../../class/.h/Partida.h"
#include <iostream>

using namespace std;

//constructores
Partida::Partida(){}

Partida::Partida(int idPartida, dtPartida * p){
    this->idPartida = idPartida;
    this->partida = p;
    this->activa = true;
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

bool Partida::getActiva(){
    return this->activa;
}

bool Partida::getIndividual(){
    return this->individual;
}
//sets
void Partida::setIdPartida(int idPartida){
    this->idPartida = idPartida;
}
void Partida::setPartida(dtPartida *p){
    this->partida = p;
}

void Partida::setActiva(bool b){
    this->activa = b;
}

void Partida::setIndividual(bool b){
    this->individual = b;
}

//methods
/*
void eliminarPartida(){}
dtMostrarPartida getMostrarPartida(){}
void confirmarPartida(){}
void continuar(){}*/