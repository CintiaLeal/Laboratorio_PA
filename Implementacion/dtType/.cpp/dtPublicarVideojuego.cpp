#include "../.h/dtPublicarVideojuego.h"

dtPublicarVideojuego::dtPublicarVideojuego(){
    this->Generos = new List();
    this->Otros = new List();
    this->Plataformas = new List();
};

ICollection* dtPublicarVideojuego::getGeneros(){
    return this->Generos;
}
ICollection* dtPublicarVideojuego::getOtros(){
    return this->Otros;
}
ICollection* dtPublicarVideojuego::getPlataformas(){
    return this->Plataformas;
}

void dtPublicarVideojuego::agregarGenero(dtGenero * data){
    this->Generos->add(data);
}

void dtPublicarVideojuego::agregarOtro(dtOtros * data){
    this->Otros->add(data);
}

void dtPublicarVideojuego::agregarPlataforma(dtPlataforma * data){
    this->Plataformas->add(data);
}

dtPublicarVideojuego::~dtPublicarVideojuego(){}


        