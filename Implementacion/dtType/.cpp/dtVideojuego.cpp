#include "../.h/dtVideojuego.h"

dtVideojuego::dtVideojuego(){
    this->nombre = "";
    this->descripcion = "";
    this->cantHorasJug = 0;
};

dtVideojuego::dtVideojuego(string n, string d, float c){
    this->nombre = n;
    this->descripcion = d;
    this->cantHorasJug = c;
};

string dtVideojuego::getNombre(){
    return this->nombre;
};
string dtVideojuego::getDescripcion(){
    return this->descripcion;
};
float dtVideojuego::getCantHorasJug(){
    return this->cantHorasJug;
};

dtVideojuego::~dtVideojuego(){};


        