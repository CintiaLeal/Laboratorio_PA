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
        string tipo;
    public:
    //constructores
        Suscripcion();
        Suscripcion(string, int, string, string);
    //gets
        string getNombre();
        int getPrecio();
        string getPeriodo();
        string getTipo();
    //sets
        void setNombre(string);
        void setPrecio(int);
        void setPeriodo(string);
        void setTipo(string);
    //methods
        //string getTipo(); /* 0=vitalicia, 1=mensual, 2=trimestral, 3=anual */
        //string getTipo();
};

#endif