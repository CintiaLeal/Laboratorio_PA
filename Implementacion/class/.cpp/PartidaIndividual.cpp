#include "../.h/PartidaIndividual.h"
#include <iostream>

using namespace std;

//constructores
PartidaIndividual::PartidaIndividual(){}

PartidaIndividual::PartidaIndividual(int idPartida, dtPartida * p,Videojuego * videojuego,dtPartidaIndividual * partidaIndividual):Partida(idPartida, p, videojuego){
    this->partidaIndividual = partidaIndividual;
}

//gets
dtPartidaIndividual * PartidaIndividual::getPartidaIndividual(){
    return this->partidaIndividual;
}

//sets
void PartidaIndividual::setPartidaIndividual(dtPartidaIndividual * partidaIndividual){
    this->partidaIndividual = partidaIndividual;
}