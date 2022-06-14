#ifndef Videojuego_
#define Videojuego_

#include <iostream>
#include "../../dtType/.cpp/dtVideojuego.cpp"
#include "PartidaMultijugador.h"
#include "PartidaIndividual.h"
#include "VJ.h"
using namespace std;

class Videojuego : public ICollectible{
    private:
        dtVideojuego * videojuego;
        IDictionary * partidas;
        ICollection * VJ;
        IDictionary * suscripciones;
        IDictionary * categorias;
    public:
        //constructores
        Videojuego();
        Videojuego(dtVideojuego*);
        //gets
        dtVideojuego * getVideojuego();
        IDictionary * getPartidas();
        //sets
        void setVideojuego(dtVideojuego*);
        void setSuscripciones(IDictionary *);
        void setCategorias(IDictionary *);
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
       // set<DtSuscripciones> listarSusSuscripciones();
        void nuevaSuscripcion(string);
};

#endif