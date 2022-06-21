#include "../.h/PartidaMultijugador.h"
#include <iostream>

using namespace std;

//constructores
PartidaMultijugador::PartidaMultijugador(){
     this->comentarios = new OrderedDictionary();
    this->jugadores = new OrderedDictionary();
    this->pmj = new List();
}

PartidaMultijugador::PartidaMultijugador(dtPartidaMultijugador * partida){
    this->partidaMultijugador = partida;
    this->comentarios = new OrderedDictionary();
    this->jugadores = new OrderedDictionary();
    this->pmj = new List();
}

PartidaMultijugador::~PartidaMultijugador(){
}

//gets
dtPartidaMultijugador * PartidaMultijugador::getPartidaMultijugador(){
    return this->partidaMultijugador;
}

IDictionary * PartidaMultijugador::getComentarios(){
    return this->comentarios;
}

IDictionary * PartidaMultijugador::getJugadores(){
    return this->jugadores;
}

ICollection * PartidaMultijugador::getPMJ(){
    return this->pmj;
}

//sets
void PartidaMultijugador::setPartidaMultijugador(dtPartidaMultijugador * partida){
    this->partidaMultijugador = partida;
}

void PartidaMultijugador::setPmj(ICollection * p){
    this->pmj = p;
}


void PartidaMultijugador::setJugadores(IDictionary * dic){
    this->jugadores = dic;
}