#include "../.h/Categoria.h"
#include <iostream>

using namespace std;

//constructores
Categoria::Categoria(){}

Categoria::Categoria(string nombre, string descripcion,string tipog){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipog = tipog;
}

//gets
string Categoria::getNombre(){
    return this->nombre;
}

string Categoria::getDescripcion(){
    return this->descripcion;
}
string Categoria::getTipog(){
    return this->tipog;
}
//sets
void Categoria::setNombre(string nombre){
    this->nombre = nombre;
}

void Categoria::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

//Para listar
dtCategoria* Categoria::getDataType(){
    dtCategoria *dtRes = new dtCategoria(this->nombre,this->descripcion);
    return dtRes;
}
