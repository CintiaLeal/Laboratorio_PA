#include "../../class/.h/Comentario.h"

Comentario::Comentario(int idComentario, string texto, dtFecha fecha){
    this->idComentario = idComentario;
    this->texto = texto;
    this->fecha = fecha;    
}
Comentario::Comentario(){

}

int Comentario::getIdComentario(){
    return this->idComentario;
}

string Comentario::getTexto(){
    return this->texto;
}

dtFecha Comentario::getFecha(){
    return this->fecha;
}
//No se puede cambiar el id o si?
void Comentario::setIdComentario(int idComentario){
    this->idComentario = idComentario;
}

void Comentario::setTexto(string texto){
    this->texto = texto;
}
//No se puede cambiar la fecha y hora o si?
void Comentario::setFecha(dtFecha fecha){
    this->fecha = fecha;
}

void eliminarComentario(){
    //Implementar
}