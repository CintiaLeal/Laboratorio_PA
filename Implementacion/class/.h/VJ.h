#include "Jugador.h"
#include <iostream>
#include "../../ICollection/collections/List.h"

using namespace std;

class Jugador;

class VJ: public ICollectible{
    private:
        int puntaje;
        Jugador * jug;
    public:
        //constructor
        VJ();
        VJ(int, Jugador*);

        //gets
        int getPuntaje();
        Jugador * getJugador();

        //sets
        void setPuntaje(int);
        void setJugador(Jugador*);
};