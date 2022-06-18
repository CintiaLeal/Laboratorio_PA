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

IDictionary * Videojuego::getCategorias(){
    return this->categorias;
}

string Videojuego::getEmpresa(){
    return this->empresa;
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

void Videojuego::setEmpresa(string nombre){
    this->empresa = nombre;
}

void Videojuego::eliminarSuscripcion(){
   
    IIterator * it;
        

    for(it = this->suscripciones->getIterator(); it->hasCurrent(); it->next()){

        Suscripcion * sus = (Suscripcion *)it->getCurrent();

        cout<<sus->getNombre().c_str()<<endl;

        //this->suscripciones->remove(k);
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

float Videojuego::getCantHorasJug(){
    return this->videojuego->getCantHorasJug();
}

void Videojuego::agregarSuscripcion(int a,int b, int c, int d){
    Suscripcion * sus = new Suscripcion("Mensual", a, "Temporal");
    IKey * k = new String(sus->getNombre().c_str());
    this->suscripciones->add(k, sus);
    
    Suscripcion * sus2 = new Suscripcion("Trimestral", b, "Temporal");
    IKey * k2 = new String(sus2->getNombre().c_str());
    this->suscripciones->add(k2,sus2);
    
    Suscripcion * sus3 = new Suscripcion("Anual", c, "Temporal");
    IKey * k3 = new String(sus3->getNombre().c_str());
    this->suscripciones->add(k3, sus3);
    
    Suscripcion * sus4 = new Suscripcion("Vitalicia", d, "Permanente");
    IKey * k4 = new String(sus4->getNombre().c_str());
    this->suscripciones->add(k4,sus4);
    

    delete(k);
    delete(k2);
    delete(k3);
    delete(k4);
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