#include "../../class/.h/Usuario.h"
#include <stdexcept>
Usuario::Usuario(string email, string contrasenia){
    this->email = email;
    this->contrasenia = contrasenia;  
}
Usuario::Usuario(){ 
}

Usuario::~Usuario(){
}

string Usuario::getEmail(){
    return this->email;
}

string Usuario::getContrasenia(){
    return this->contrasenia;
}


void Usuario::setEmail(string email){
    this->email = email;
}
void Usuario::setContrasenia(string contrasenia){
    this->contrasenia = contrasenia;

}



/*/metodos
dtMostrarPartida listarPartidas(){}
void confirmarPartidas(){}
void confirmarMultijugador(){}
void agregarPartida(Partida){}
dtPartidaIndividual getPartidasFinalizadas(string){}
void confirmarContinuar(int){}

void Usuario::confirmarNueva(Partida * p){
    if(p == NULL){
        throw std::invalid_argument("Partida es null");
    }

    // crea una clave para el nuevo elemento coleccionado
    IKey *k = new Integer((p->getIdPartida()));
    // agrega a la coleccion
    this->partidas->add(k, p);
    // no se debe borrar la k, ya que es a esta instancia a la cual queda referenciando la coleccion

}*/
