#ifndef jugador_
#define jugador_
#include <iostream>

#include "../../class/.h/Usuario.h"
#include "../../dtType/.h/dtJugador.h"
#include "../../dtType/.h/dtPago.h"
#include "../../ICollection/collections/List.h"
using namespace std;

class Jugador:public Usuario{
    private:
        dtJugador * jugador;
        ICollection * pagos;
    public:
        Jugador(dtJugador *);
        Jugador();
        ~Jugador();

        //get y set 
        dtJugador * getJugador();

        void setJugador(dtJugador *);

        //metodo
        bool member(string);
        string listarVideojuego();
        string getNick();
        void buscarSuscripcion(int);
        void cancelarSuscripcion();
        void nuevoSuscripcion(string);
        void cancelar();
};
#endif 
