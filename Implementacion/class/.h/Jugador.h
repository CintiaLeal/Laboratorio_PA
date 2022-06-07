#ifndef jugador_
#define jugador_
#include <iostream>

#include "../../class/.h/Usuario.h"
#include "../../dtType/.h/dtJugador.h"
#include "../../dtType/.h/dtPago.h"
using namespace std;

class Jugador:public Usuario{
    private:
        dtJugador * jugador;
        dtPago * pagos; //implementar pago
    public:
        Jugador(dtJugador *, dtPago *);
        Jugador();
        ~Jugador();

        //get y set 
        dtJugador getJugador();
        dtPago  getPagos();

        void setJugador(dtJugador *);
        void setPagos(dtPago *);

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
