
#include "../.h/DtPartidaIndividual.h"
using namespace std;


dtPartidaIndividual::dtPartidaIndividual(){

}

dtPartidaIndividual::dtPartidaIndividual(int id, dtFecha * fecha, float duracion, dtPartidaIndividual* continua):dtPartida(id, fecha, duracion){
this->continua = continua;
}

dtPartidaIndividual* dtPartidaIndividual::getContinua(){
    this->continua;
}

dtPartidaIndividual::~dtPartidaIndividual(){

}
