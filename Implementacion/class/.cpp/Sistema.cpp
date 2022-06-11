#include "../../class/.h/Sistema.h"
#include <stdexcept>

Sistema * Sistema::instancia = 0;

Sistema::Sistema(){
    this->dicUsuario = new OrderedDictionary();
    this->dicCategoria = new OrderedDictionary();
    this->dicVideojuego = new OrderedDictionary();
}
Sistema::~Sistema(){ }

Sistema * Sistema::getInstancia() {
    if (instancia == 0) {
        instancia = new Sistema();
    }
    return instancia;
}
/*
void Sistema::altaUsuarioDesarrollador(string email,string contrasenia,string nombreEmpresa){
    IKey * k = new String(email.c_str());
    if(this->dicUsuario->member(k)){
        cout<<"Ya existe";
    }
    else{
        Desarrollador *d = new Desarrollador(email,contrasenia,nombreEmpresa);
        dicUsuario->add(k,d);
    }
}*/
void Sistema::altaUsuarioDesarrollador(string email,string contrasenia,string nombreEmpresa){
    IKey * k = new String(email.c_str());
    if(this->dicUsuario->member(k)){
        cout<<"Ya existe";
        
    }
    else{
        Usuario *d = new Usuario(email,contrasenia);
        dicUsuario->add(k,d);
        
    }
}

void Sistema::nuevaCategoria(string nombre,string descripcion){
     IKey * k = new String(nombre.c_str());
    if(this->dicCategoria->member(k)){
        cout<<"Ya existe"<<endl; 
    }
    else{
        Categoria *c = new Categoria(nombre,descripcion);
        dicCategoria->add(k,c);
        
    }
}