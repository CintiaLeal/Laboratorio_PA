#include "../.h/PartidaMultijugador.h"
#include <iostream>

using namespace std;

//constructores
PartidaMultijugador::PartidaMultijugador(){}

PartidaMultijugador::PartidaMultijugador(int idPartida, dtPartida * p,Videojuego * videojuego ,dtPartidaMultijugador * partida):Partida(idPartida, p, videojuego){
    this->partidaMultijugador = partida;
    this->comentarios = new OrderedDictionary();
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

//sets
void PartidaMultijugador::setPartidaMultijugador(dtPartidaMultijugador * partida){
    this->partidaMultijugador = partida;
}
