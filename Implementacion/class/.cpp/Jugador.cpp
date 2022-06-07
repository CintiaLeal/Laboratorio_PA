#include "class/.h/Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(){}

Jugador::Jugador(dtJugador * jugador){}

//gets
dtJugador * Jugador::getJugador(){
    return this->jugador;
}

//sets
void Jugador::setJugador(dtJugador * jugador){
    this->jugador = jugador;
}

//methods 
bool Jugador::member(string){}

string Jugador::listarVideojuego(){}

string Jugador::getNick(){
    return this->getNick();
}

void Jugador::buscarSuscripcion(int){}

void Jugador::cancelarSuscripcion(){}

void Jugador::nuevoSuscripcion(string){}

void Jugador::cancelar(){}