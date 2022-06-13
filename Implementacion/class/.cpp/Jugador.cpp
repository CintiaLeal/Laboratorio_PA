#include "../.h/Jugador.h"
#include <iostream>

using namespace std;

Jugador::Jugador(){
    
}
Jugador::~Jugador(){
    
}
Jugador::Jugador(string email, string contrasenia,string nick, string descripcion): Usuario(email, contrasenia){
    this->nick = nick;
    this->descripcion = descripcion;
  
}



//methods 
bool Jugador::member(string){}

string Jugador::listarVideojuego(){}

string Jugador::getNick(){
    return this->getNick();
}

void Jugador::buscarSuscripcion(int){}

void Jugador::cancelarSuscripcion(){}

void Jugador::nuevoSuscripcion(string){}

void Jugador::cancelar(){}
