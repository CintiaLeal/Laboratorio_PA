#include "../.h/dtUsuario.h"
#include <stdexcept>
dtUsuario::dtUsuario(string email, string contrasenia){
    this->email = email;
    this->contrasenia = contrasenia;
    
}
dtUsuario::dtUsuario(){
    
}

dtUsuario::~dtUsuario(){
    
}

string dtUsuario::getEmail(){
    return this->email;
}

string dtUsuario::getContrasenia(){
    return this->contrasenia;
}







