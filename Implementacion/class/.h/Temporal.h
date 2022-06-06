#ifndef Temporal_
#define Temporal_

#include <iostream>
#include <Suscripcion.h>

//CAMBIAR LA RUTA DE LA INCLUSION 

using namespace std;

class Temporal : public Suscripcion{
    private:
        string periodo;
    public:
        //constructor
        Temporal();
        Temporal(string, int, string);
        //get
        string getPeriodo();
        //set
        void setPeriodo(string);
};

#endif