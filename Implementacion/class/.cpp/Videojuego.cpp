#include "../.h/Videojuego.h"
#include <iostream>

using namespace std;

//constructores
Videojuego::Videojuego(){
    this->partidas = new OrderedDictionary();
    this->suscripciones = new OrderedDictionary();  
    this->categorias = new OrderedDictionary();  
    this->VJ = new List();
}

Videojuego::Videojuego(dtVideojuego * juego){
    this->videojuego = juego;
    this->partidas = new OrderedDictionary();  
    this->suscripciones = new OrderedDictionary(); 
    this->categorias = new OrderedDictionary();  
    this->VJ = new List();
}

//gets
dtVideojuego* Videojuego::getVideojuego(){
    return this->videojuego;
}

//sets
void Videojuego::setVideojuego(dtVideojuego * juego){
    this->videojuego = juego;
}

 //asuntos de la coleccion
        /*
        void Videojuego::agregarPartida(partida *p){

        }
        void Videojuego::eliminarPartida(partida *p){

        }
        void Videojuego::agregarVJ(VJ *vj){

        }
        void Videojuego::eliminarVJ(VJ *vj){

        }
        void Videojuego::agregarSuscripcion(Suscripcion *suscr){

        }
        void Videojuego::eliminarSuscripcion(Suscripcion *suscr){

        }
        void Videojuego::agregarCategoria(Categoria *cat){

        }
        void Videojuego::eliminarCategoria(Categoria *cat){

        }
        */

//Method
/*
string Videojuego::getNombre(){
   return this->videojuego->getNombre();
}*/

 void Videojuego::eliminarVideojuego(){

 }

void Videojuego::agregarPM(PartidaMultijugador){

}
void Videojuego::agregarPI(PartidaIndividual){

}/*
string Videojuego::getDescripcion(){
return this->videojuego->getDescripcion();
}
float Videojuego::getCantHorasJug(){
return this->videojuego->getCantHorasJug();
}*/
//set<DtSuscripciones> Videojuego::listarSusSuscripciones(){}

void Videojuego::nuevaSuscripcion(string){

}