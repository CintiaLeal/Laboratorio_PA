#include "../.h/dtPartidaMultijugador.h"
using namespace std;


dtPartidaMultijugador::dtPartidaMultijugador(){

}

dtPartidaMultijugador::dtPartidaMultijugador(int id, dtFecha * fecha, float duracion, bool EnVivo):dtPartida(id, fecha, duracion){
this->EnVivo = EnVivo;
}

bool dtPartidaMultijugador::getEnVivo(){
    this->EnVivo;
}

dtPartidaMultijugador::~dtPartidaMultijugador(){

}
