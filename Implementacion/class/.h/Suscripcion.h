#ifndef Suscripcion_
#define Suscripcion_

#include "../../ICollection/interfaces/ICollectible.h"
#include "../.h/Videojuego.h"
#include <iostream>
//INCLUIR TIPO SUSCRIPCION

using namespace std;

class Suscripcion : public ICollectible{
    private:
        string nombre;
        int precio;
        string periodo;
        Videojuego * vid;
    public:
    //constructores
        Suscripcion();
        Suscripcion(string, int, string);
    //gets
        string getNombre();
        int getPrecio();
        string getPeriodo();
        Videojuego * getVideojuego();
    //sets
        void setNombre(string);
        void setPrecio(int);
        void setPeriodo(string);
    //methods
        Videojuego * buscarSuscripcion();
};

#endif