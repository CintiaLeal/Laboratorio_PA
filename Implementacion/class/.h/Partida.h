#ifndef partida_
#define partida_

#include <iostream>
#include "../../dtType/.h/dtPartida.h"
#include "../../dtType/.h/dtVideojuego.h"
#include "../../dtType/.h/dtUsuario.h"
#include "../../dtType/.h/dtMostrarPartida.h"
using namespace std;

class Partida{
    protected:
        int idPartida;
        dtPartida * partida;
        dtUsuario * jugadores;
        dtVideojuego * videojuego;
    public:
        Partida(int idPartida, dtPartida * partida ,dtUsuario * jugadores,dtVideojuego * videojuego);
        Partida();
        ~Partida();

        //get y set
        int getIdPartida();
        dtPartida* getPartida();
        dtUsuario* getJugadores();
        dtVideojuego* getVideojuego();


        void setIdPartida(int);
        void setPartida(dtPartida*);
        void setJugadores(dtUsuario*);
        void setVideojuego(dtVideojuego*);
        
        //metodos
        void eliminarPartida();
        dtMostrarPartida getMostrarPartida();
        void confirmarPartida(int);
        void continuar();
};

#endif //Partida class