#include "../.h/PartidaIndividual.h"
#include <iostream>

using namespace std;

//constructores
PartidaIndividual::PartidaIndividual(){}

PartidaIndividual::PartidaIndividual(dtPartidaIndividual * partidaIndividual){
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