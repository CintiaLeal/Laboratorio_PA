#include "../.h/PartidaMultijugador.h"
#include <iostream>

using namespace std;

//constructores
PartidaMultijugador::PartidaMultijugador(){}

PartidaMultijugador::PartidaMultijugador(int idPartida, dtPartida * p,dtPartidaMultijugador * partida):Partida(idPartida, p){
    this->partidaMultijugador = partida;
    this->comentarios = new OrderedDictionary();
}

//gets
dtPartidaMultijugador * PartidaMultijugador::getPartidaMultijugador(){
    return this->partidaMultijugador;
}

//sets
void PartidaMultijugador::setPartidaMultijugador(dtPartidaMultijugador * partida){
    this->partidaMultijugador = partida;
}