#include "../.h/dtComentario.h"

dtComentario::dtComentario(int idComentario, string texto, dtFecha fecha){
    this->idComentario = idComentario;
    this->texto = texto;
    this->fecha = fecha;    
}
dtComentario::dtComentario(){

}

int dtComentario::getIdComentario(){
    return this->idComentario;
}

string dtComentario::getTexto(){
    return this->texto;
}

dtFecha dtComentario::getFecha(){
    return this->fecha;
}
dtComentario::~dtComentario(){}