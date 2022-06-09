#include "../.h/dtPublicarVideojuego.h"

// FALTA HACER FUNCIONES QUE AGREGEN ELEMENTOS A LAS COLECCIONES
//DTGENERO, DTOTROS Y DT PLATAFORMA VAN A SER ICOLECTIBLE
dtPublicarVideojuego::dtPublicarVideojuego(){
    this->Generos = new List();
    this->Otros = new List();
    this->Plataformas = new List();
};

List* dtPublicarVideojuego::getGeneros(){
    return (List *)this->Generos;
}
List* dtPublicarVideojuego::getOtros(){
    return (List *)this->Otros;
}
List* dtPublicarVideojuego::getPlataformas(){
    return (List *)this->Plataformas;
}
dtPublicarVideojuego::~dtPublicarVideojuego(){}


        