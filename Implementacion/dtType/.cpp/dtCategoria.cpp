#include "../.h/dtCategoria.h"

dtCategoria::dtCategoria(){
    this->nombre = "";
    this->descripcion = "";
};

dtCategoria::dtCategoria(string n, string d){
    this->nombre = n;
    this->descripcion = d;
};

string dtCategoria::getNombre(){
    return this->nombre;
};
string dtCategoria::getDescripcion(){
    return this->descripcion;
};

dtCategoria::~dtCategoria(){};


        