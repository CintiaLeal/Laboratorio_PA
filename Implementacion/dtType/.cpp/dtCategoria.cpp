#include "../.h/dtCategoria.h"



dtCategoria::dtCategoria(string n, string d){
    this->nombre = n;
    this->descripcion = d;
}

string dtCategoria::getNombredt(){
    return this->nombre;
}
string dtCategoria::getDescripciondt(){
    return this->descripcion;
}



        