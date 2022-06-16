#include "../.h/Desarrollador.h"
#include <iostream>

using namespace std;

//constructores
Desarrollador::Desarrollador(){}
Desarrollador::Desarrollador(string email, string contrasenia, string nombreEmpresa):Usuario(email,contrasenia){
    this->nombreEmpresa = nombreEmpresa;
}


Desarrollador::~Desarrollador(){}
//get
string Desarrollador::getNombreEmpresa(){
    return this->nombreEmpresa;
}
string Desarrollador::getTipo(){
    string d = "soyDesarrollador";
    return d;
}
//set
void Desarrollador::setNombreEmpresa(string nombre){
    this->nombreEmpresa = nombre;
}
//methods
//dtPublicarVideojuego Desarrollador::altaVideojuego(string ,string){ }
