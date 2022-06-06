#ifndef Vitalicia_
#define Vitalicia_

#include <iostream>
#include <Suscripcion.h>

//CAMBIAR LA RUTA DE LA INCLUSION 

using namespace std;

class Vitalicia : public Suscripcion{
    private:
    
    public:
        //constructor
        Vitalicia();
        Vitalicia(string, int);
        //methods
        bool buscarSuscripcion();
};

#endif