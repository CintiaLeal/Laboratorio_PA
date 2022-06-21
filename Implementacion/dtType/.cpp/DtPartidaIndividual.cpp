
#include "../.h/DtPartidaIndividual.h"
using namespace std;


dtPartidaIndividual::dtPartidaIndividual(){

}

dtPartidaIndividual::dtPartidaIndividual(int id, dtFecha * fecha, float duracion, dtPartidaIndividual* continua, bool t):dtPartida(id, fecha, duracion){
this->continua = continua;
this->contin=t;
}

dtPartidaIndividual* dtPartidaIndividual::getContinua(){
    this->continua;
}

dtPartidaIndividual::~dtPartidaIndividual(){

}

bool dtPartidaIndividual::getCont(){
    return this->contin;
}
