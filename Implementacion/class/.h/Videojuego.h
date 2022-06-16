#ifndef Videojuego_
#define Videojuego_

#include <iostream>
#include "../../dtType/.cpp/dtVideojuego.cpp"
#include "PartidaMultijugador.h"
#include "PartidaIndividual.h"
using namespace std;

class Partida;

class Videojuego : public ICollectible{
    private:
        dtVideojuego * videojuego;
        IDictionary * partidas;
        ICollection * vj;
        IDictionary * suscripciones;
        IDictionary * categorias;
        string empresa;
    public:
        //constructores
        Videojuego();
        Videojuego(dtVideojuego*);
        //gets
        dtVideojuego * getVideojuego();
        IDictionary * getPartidas();
        IDictionary * getSuscripciones();
        IDictionary * getCategorias();
        ICollection * getVJ();
        string getEmpresa();
        //sets
        void setVideojuego(dtVideojuego*);
        void setSuscripciones(IDictionary *);
        void setCategorias(IDictionary *);
        int getEstadisticas();
        void agregarSuscripcion(int, int, int, int);
        void setEmpresa(string);
        float getCantHorasJug();
        //asuntos de la coleccion
        /*
        void agregarPartida(partida *p);
        void eliminarPartida(partida *p);
        void agregarVJ(VJ *vj);
        void eliminarVJ(VJ *vj);
        void agregarSuscripcion(Suscripcion *suscr);
        
        void agregarCategoria(Categoria *suscr);
        void eliminarCategoria(Categoria *suscr);
        */
        
        //methods
        string getNombre();
        void eliminarVideojuego();
        void agregarPM(PartidaMultijugador);
        void agregarPI(PartidaIndividual);
        string getDescripcion();
        
        void eliminarSuscripcion(string);
       // set<DtSuscripciones> listarSusSuscripciones();
        void nuevaSuscripcion(string);
};

#endif