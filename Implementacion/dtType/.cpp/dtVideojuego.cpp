#include "../h/dtVideojuego.h"

DtVideojuego::dtVideojuego(){
    this->nombre = "";
    this->descripcion = "";
    this->cantHorasJug = 0;
};

DtVideojuego::dtVideojuego(string n, string d, float c){
    this->nombre = n;
    this->descripcion = d;
    this->cantHorasJug = c;
};

string DtVideojuego::getNombre(){
    return this->nombre;
};
string DtVideojuego::getDescripcion(){
    return this->descripcion;
};
float DtVideojuego::getCantHorasJug(){
    return this->cantHorasJug;
};

DtVideojuego::~dtVideojuego(){};


        