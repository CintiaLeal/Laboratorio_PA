#ifndef Suscripcion_
#define Suscripcion_

#include <iostream>
//INCLUIR TIPO SUSCRIPCION

using namespace std;

class Suscripcion{
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
        string getTipo(); /* 0=vitalicia, 1=mensual, 2=trimestral, 3=anual */
        string Suscripcion::getTipo()
};

#endif