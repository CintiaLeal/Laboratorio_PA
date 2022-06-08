#ifndef partida_
#define partida_

#include <iostream>
#include "../../dtType/.h/dtPartida.h"
#include "../../dtType/.h/dtVideojuego.h"
#include "../../class/.h/Usuario.h"
#include "../../dtType/.h/dtUsuario.h"
#include "../../dtType/.h/dtMostrarPartida.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/String.h"
#include "../../ICollection/Integer.h"
using namespace std;

class Partida: public ICollectible{
    protected:
        int idPartida;
        dtPartida * partida;
        IDictionary * jugadores;
        IDictionary * videojuego;
    public:
        Partida(int idPartida, dtPartida *);
        Partida();
        ~Partida();

        //get y set
        int getIdPartida();
        dtPartida * getPartida();
        void setIdPartida(int);
        void setPartida(dtPartida*);
        //metodos
        void eliminarPartida();
        dtMostrarPartida getMostrarPartida();
        void confirmarPartida(int);
        void continuar();
};

#endif //Partida class