#ifndef partida_
#define partida_

#include <iostream>
#include "../../dtType/.h/dtPartida.h"
#include "../../class/.h/Usuario.h"
#include "../../dtType/.h/dtUsuario.h"
#include "../../dtType/.h/dtMostrarPartida.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/String.h"
#include "../../ICollection/Integer.h"
using namespace std;

class Videojuego;

class Partida: public ICollectible{
    protected:
        int idPartida;
        bool activa;
        bool individual;
        Videojuego * videojuego;
    public:
        Partida(int idPartida, Videojuego *);
        Partida();
        ~Partida();

        //get y set
        int getIdPartida();
        bool getActiva();
        bool getIndividual();
        Videojuego * getVideojuego();

        void setIdPartida(int);
        void setActiva(bool);
        void setIndividual(bool);
        void setVideoJuego(Videojuego *);
        //metodos
        void eliminarPartida();
        dtMostrarPartida getMostrarPartida();
        void confirmarPartida(int);
        void continuar();
        
};

#endif //Partida class