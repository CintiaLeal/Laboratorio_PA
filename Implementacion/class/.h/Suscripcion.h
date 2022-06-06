#ifndef Suscripcion_
#define Suscripcion_

#include <iostream>
//INCLUIR TIPO SUSCRIPCION

using namespace std;

class Suscripcion{
    protected:
        string nombre;
        int precio;
    public:
    //constructores
        Suscripcion();
        Suscripcion(string, int);
    //gets
        string getNombre();
        int getPrecio();
    //sets
        void setNombre(string);
        void setPrecio(int);
    //methods
        virtual string getTipo() = 0; /* 0=vitalicia, 1=mensual, 2=trimestral, 3=anual */
};

#endif