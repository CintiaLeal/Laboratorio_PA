#ifndef Pago_
#define Pago_

#include <iostream>
#include "Suscripcion.h"
#include "../../dtType/.h/dtVideojuego.h"
#include "../../dtType/.h/dtPartidaIndividual.h"
#include "../../dtType/.h/dtPartida.h"
#include "../../dtType/.h/dtUsuario.h"
#include "../../dtType/.h/dtMostrarPartida.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/String.h"
#include "../../ICollection/Integer.h"

using namespace std;

class Pago: public ICollectible{
    private:
        dtFecha fechaV;
        dtFecha fechaContrato;
        string metodoPago;
        bool activa;
        Suscripcion *suscripcion;
    public:
        //constructores
        Pago();
        Pago(dtFecha, dtFecha, string, bool, Suscripcion *);
        //gets
        dtFecha getFechaV();
        dtFecha getFechaC();
        string getMetodoPago();
        bool getActiva();
        Suscripcion * getSuscripcion();
        //sets
        void setFechaV(dtFecha);
        void setFechaC(dtFecha);
        void setMetodoPago(string);
        void setActiva(bool);
        void setSuscripcion(Suscripcion *);
        //methods
        Videojuego * getJuego();
        dtVideojuego buscarVideojuego(string);

        void cambiarEstado();
};

#endif
