#include "../.h/Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(){
    ICollection * pagos = new List();
    IDictionary * partidas = new OrderedDictionary();
}
Jugador::~Jugador(){
    
}
Jugador::Jugador(string email, string contrasenia,string nick, string descripcion): Usuario(email, contrasenia){
    this->nick = nick;
    this->descripcion = descripcion;
    ICollection * pagos = new List();
    IDictionary * partidas = new OrderedDictionary();
  
}

ICollection * Jugador::getPagos(){
    return this->pagos;
}

IDictionary * Jugador::getPartidas(){
    return this->partidas;
}

//methods 
bool Jugador::member(string){}

string Jugador::listarVideojuego(){}

string Jugador::getNick(){
    return this->getNick();
}

void Jugador::borrarPagos(string nombre){
    IIterator * it;

    for(it = this->pagos->getIterator(); it->hasCurrent(); it->next()){
        Pago * p = (Pago *)it->getCurrent();
        if(p->getJuego()->getVideojuego()->getNombre() == nombre){
            this->pagos->remove(p);
            delete p;
        }
    }
}

void Jugador::borrarPartidas(string nombre){
    IIterator * it;

    for(it = this->partidas->getIterator(); it->hasCurrent(); it->next()){
        Partida * p = (Partida *)it->getCurrent();

        if(p->getVideojuego()->getVideojuego()->getNombre() == nombre){
            IKey * k = new Integer(p->getIdPartida());
            this->partidas->remove(k);
        }
    }
}

void Jugador::buscarSuscripcion(int){}

void Jugador::cancelarSuscripcion(){}

void Jugador::nuevoSuscripcion(string){}

void Jugador::cancelar(){}
