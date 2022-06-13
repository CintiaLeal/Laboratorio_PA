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
void Sistema::altaUsuarioJugador(string email,string contrasenia,string nick,string descripcion){
    IKey * k = new String(email.c_str());
    if(this->dicUsuario->member(k)){
        cout<<"Ya existe";
        
    }
    else{
        
        Jugador * jug = new Jugador(email,contrasenia,nick,descripcion);
        dicUsuario->add(k,jug);
        
    }
}
void Sistema::nuevaCategoria(string nombre,string descripcion,int tipo){
    string tipog;
    if(tipo==1){
        tipog="Plataforma";
    }
    if(tipo==2){
        tipog="General";
    }
    else{
        tipog="Otro";
    }
    IKey * k = new String(nombre.c_str());
    if(this->dicCategoria->member(k)){
        cout<<"Ya existe"<<endl; 
    }
    else{
        Categoria *c = new Categoria(nombre,descripcion,tipog);
        dicCategoria->add(k,c);
        
    }
}

dtVideojuego* Sistema::altaVideojuego(string nombre, string descripcion){
    bool existe = true;
    string nom = nombre;
    do{
        IKey * k = new String(nom.c_str());
        if(this->dicVideojuego->member(k)){
            cout << "Este videojuego ya existe, ingrese otro nombre" << endl;
            cin >> nom;
        }else{
            existe = false;
        }
    }while(existe);
    dtVideojuego * vid = new dtVideojuego(nom, descripcion, 0);
}

void Sistema::listarCategoria(){ 

IIterator * it;
	for (it= this->dicCategoria->getIterator();it->hasCurrent();it -> next()){
		Categoria * u = (Categoria*)it->getCurrent();
		string nombre = u->getNombre();
		cout << nombre << endl;
	}
}

