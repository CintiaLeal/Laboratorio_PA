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
        virtual tipoSuscripcion getTipo() = 0;
};

#endif