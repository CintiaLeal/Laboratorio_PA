#include "../../class/.h/Sistema.h"
#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

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
        cout<<"Un usuario con este nombre ya existe, por favor ingrese otro";
        
    }
    else{
        Desarrollador *d = new Desarrollador(email,contrasenia, nombreEmpresa);
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
//ICollection* Sistema::listarCategoria(){ }
/*
ICollection* Sistema::listarCategoria(){     // Terminada Verificar
    ICollection * res = new List();
    IIterator * it = dicCategoria->getIterator();
    while (it->hasCurrent()) {
        dtCategoria * p = dynamic_cast<Categoria *>(it->getCurrent())->getDataType();
        res->add(p);
        it->next();
    }
    delete it;
    return res;
}*/


ICollection* Sistema::listarCategoria(){ 

IIterator * it;
	for (it= this->dicCategoria->getIterator();it->hasCurrent();it -> next()){
		Categoria * u = (Categoria*)it->getCurrent();
		string nombre = u->getNombre();
		cout << nombre << endl;
	}
}

