#include "../../class/.h/Usuario.h"

Usuario::Usuario(string email, string contrasenia, dtPartida * partidas){
    this->email = email;
    this->contrasenia = contrasenia;
    this->partidas = partidas;    
}
Usuario::Usuario(){

}

string Usuario::getEmail(){
    return this->email;
}

string Usuario::getContrasenia(){
    return this->contrasenia;
}

dtPartida * Usuario::getPartidas(){
    return this->partidas;
}

void Usuario::setEmail(string email){
    this->email = email;
}
void Usuario::setContrasenia(string contrasenia){
    this->contrasenia = contrasenia;

}

void Usuario::setPartidas(dtPartida * partidas){
    this->partidas = partidas;
}

//metodos
dtMostrarPartida listarPartidas(){}
void confirmarPartidas(){}
void confirmarMultijugador(/*set<string>*/){}
void agregarPartida(Partida){}
dtPartidaIndividual getPartidasFinalizadas(string){}
void confirmarContinuar(int){}
void confirmarNueva(string){}
