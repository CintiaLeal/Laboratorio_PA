#ifndef Videojuego_
#define Videojuego_

#include <iostream>
#include "../../dtType/.h/dtVideojuego.h"
#include "../.cpp/PartidaMultijugador.cpp"
#include "../.cpp/PartidaIndividual.cpp"
using namespace std;

class Videojuego{
    private:
        dtVideojuego videojuego;
        //coleccion de partidas (IDictionary *partidas)
        //coleccion de V-J (IDictionary *VJ)
        //coleccion de Suscripciones (IDictionary *Suscripciones)
        //coleccion de Categorias (IDictionary *Categorias)
    public:
        //constructores
        Videojuego();
        Videojuego(dtVideojuego);
        //gets
        dtVideojuego getVideojuego();
        //sets
        void setVideojuego(dtVideojuego);
        //asuntos de la coleccion
        /*
        void agregarPartida(partida *p);
        void eliminarPartida(partida *p);
        void agregarVJ(VJ *vj);
        void eliminarVJ(VJ *vj);
        void agregarSuscripcion(Suscripcion *suscr);
        void eliminarSuscripcion(Suscripcion *suscr);
        void agregarCategoria(Categoria *suscr);
        void eliminarCategoria(Categoria *suscr);
        */
        
        //methods
        string getNombre();
        void eliminarVideojuego();
        void agregarPM(PartidaMultijugador);
        void agregarPI(PartidaIndividual);
        string getDescripcion();
        float getCantHorasJug();
        set<DtSuscripciones> listarSusSuscripciones();
        void nuevaSuscripcion(string);
};

#endif