#include "../.h/Suscripcion.h"
#include <iostream>
//Falta el include

using namespace std;

//constructores
Suscripcion::Suscripcion(){}

Suscripcion::Suscripcion(string nombre, int precio, string periodo){
    this->nombre = nombre;
    this->precio = precio;
    this->periodo = periodo;
}

//gets
string Suscripcion::getNombre(){
    return this->nombre;
}

int Suscripcion::getPrecio(){
    return this->precio;
}

string Suscripcion::getPeriodo(){
    return this->periodo;
}

Videojuego * Suscripcion::getVideojuego(){
    return this->vid;
}

//sets
void Suscripcion::setNombre(string nom){
    this->nombre = nom;
}

void Suscripcion::setPrecio(int precio){
    this->precio = precio;
}

void Suscripcion::setPeriodo(string periodo){
    this->periodo = periodo;
}

//methods

Videojuego * Suscripcion::buscarSuscripcion(){
    Videojuego * v = this->getVideojuego();

    cout << "Nombre:" << v->getVideojuego()->getNombre() << endl;
    IDictionary * aux = v->getSuscripciones();
    IIterator * it;
    for(it = aux->getIterator(); it->hasCurrent(); it->next()){
        Suscripcion * s = (Suscripcion *)it->getCurrent();

        cout << "Nombre:" << s->getNombre() << " | Precio:" << s->getPrecio() << endl;
    }

    return v;
}