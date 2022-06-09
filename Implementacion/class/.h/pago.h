#ifndef Pago_
#define Pago_

#include <iostream>
#include "../../dtType/.h/dtFecha.h"
#include "../../dtType/.h/dtVideojuego.h"
//#include "class/.h/Videojuego.h"
using namespace std;

class Pago{
    private:
        dtFecha fechaV;
        dtFecha fechaContrato;
        string metodoPago;
        bool activa;
    public:
        //constructores
        Pago();
        Pago(dtFecha, dtFecha, string, bool);
        //gets
        dtFecha getFechaV();
        dtFecha getFechaC();
        string getMetodoPago();
        bool getActiva();
        //sets
        void setFechaV(dtFecha);
        void setFechaC(dtFecha);
        void setMetodoPago(string);
        void setActiva(bool);
        //methods
        //Videojuego getJuego();
        dtVideojuego buscarVideojuego(string);

        void cambiarEstado();
};

#endif