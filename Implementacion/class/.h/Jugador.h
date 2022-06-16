#ifndef jugador_
#define jugador_
#include <iostream>

#include "../../class/.h/Usuario.h"
#include "../../dtType/.h/dtJugador.h"
#include "../../class/.h/Pago.h"
#include "../../ICollection/collections/List.h"
using namespace std;

class Jugador:public Usuario{
    private:
        string nick;
        string descripcion;
        IDictionary * partidas;
        ICollection * pagos;
    public:
        Jugador(string, string, string, string);
        Jugador();
        ~Jugador();

        //get y set 
        dtJugador * getJugador();
        ICollection * getPagos();
        IDictionary * getPartidas();
        string getTipo();
        void setJugador(dtJugador *);

        //metodo
        bool member(string);
        string listarVideojuego();
        string getNick();
        void borrarPagos(string);
        void borrarPartidas(string);
        void buscarSuscripcion(int);
        void cancelarSuscripcion();
        void nuevoSuscripcion(string);
        void cancelar();
};
#endif 

