#ifndef jugador_
#define jugador_
#include <iostream>

#include "../../class/.h/Usuario.h"
#include "../../dtType/.h/dtFecha.h"

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
        bool buscarSuscripcion(string);
        void cancelarSuscripcion();
        void nuevoSuscripcion(string, Suscripcion *, dtFecha*);
        void cancelar(string);
        IDictionary * listarVideojuegoConCosto();
        bool listarPartidas(string);
        void cambiarEstado(int);
        void createNuevaIndcont(string, int, int, dtFecha *);
        void createNuevaInd(string, int,dtFecha *);
        bool listarPartidasActivas();
        void finalizarPartida(int, dtFecha*);
        float calcularDuracion(dtFecha*, dtFecha*);
        bool existeSus(string);
};
#endif 

