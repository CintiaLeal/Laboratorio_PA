#ifndef Suscripcion_
#define Suscripcion_

#include "../../ICollection/interfaces/ICollectible.h"
#include <iostream>
//INCLUIR TIPO SUSCRIPCION

using namespace std;

class Suscripcion : public ICollectible{
    private:
        string nombre;
        int precio;
        string periodo;
    public:
    //constructores
        Suscripcion();
        Suscripcion(string, int, string);
    //gets
        string getNombre();
        int getPrecio();
        string getPeriodo();
    //sets
        void setNombre(string);
        void setPrecio(int);
        void setPeriodo(string);
    //methods
};

#endif