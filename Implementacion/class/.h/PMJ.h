#include "Jugador.h"
#include <iostream>

using namespace std;
class Jugador;
class PMJ: public ICollectible{
    private:
        dtFecha * horaSalida;
        Jugador * j;
    public:
        //constructor
        PMJ();
        PMJ(dtFecha*, Jugador *);

        //gets
        dtFecha * getHoraSalida();
        Jugador * getJ();

        //sets
        void setHoraSalida(dtFecha*);
        void setJ(Jugador*);
};