#include "../.h/Videojuego.h"
#include "../.cpp/VJ.cpp"
#include <iostream>

using namespace std;

//constructores
Videojuego::Videojuego(){
    this->partidas = new OrderedDictionary();
    this->suscripciones = new OrderedDictionary();  
    this->categorias = new OrderedDictionary();  
    this->vj = new List();
}

Videojuego::Videojuego(dtVideojuego * juego){
    this->videojuego = juego;
    this->partidas = new OrderedDictionary();  
    this->suscripciones = new OrderedDictionary(); 
    this->categorias = new OrderedDictionary();  
    this->vj = new List();
}

//gets
dtVideojuego* Videojuego::getVideojuego(){
    return this->videojuego;
}

IDictionary * Videojuego::getPartidas(){
    return this->partidas;
}

IDictionary * Videojuego::getSuscripciones(){
    return this->suscripciones;
}

ICollection * Videojuego::getVJ(){
    return this->vj;
}

//sets
void Videojuego::setVideojuego(dtVideojuego * juego){
    this->videojuego = juego;
}

void Videojuego::setSuscripciones(IDictionary * sus){
    this->suscripciones = sus;
}

void Videojuego::setCategorias(IDictionary * cat){
    this->categorias = cat;
}

void Videojuego::eliminarSuscripcion(string nombre){
    IIterator * it;
    for(it = this->suscripciones->getIterator(); it->hasCurrent(); it->next()){
        Suscripcion * sus = (Suscripcion *)it->getCurrent();

        IKey * k = new String(sus->getNombre().c_str());
        this->suscripciones->remove(k);
        delete(sus);
    }
}

int Videojuego::getEstadisticas(){
    IIterator * it;

    int cant = 0;
    int total = 0;
    for(it = this->vj->getIterator(); it->hasCurrent(); it->next()){
        VJ * vj = (VJ *)it->getCurrent();
        total += vj->getPuntaje();
        cant++;
    }

    if(total == 0){
        return 0;
    }else{
        return total/cant;
    }
    
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