#ifndef partidaMultijugador_
#define partidaMultijugador_
#include <iostream>
#include "Partida.h"
#include "../../dtType/.h/dtPartidaMultijugador.h"
#include "../../class/.h/Comentario.h"

using namespace std;


class PartidaMultijugador:public Partida{
    private:
        dtPartidaMultijugador * partidaMultijugador;
        IDictionary * comentarios; 
        IDictionary * jugadores; 
        ICollection * pmj;
    public:
        PartidaMultijugador(dtPartidaMultijugador *);
        PartidaMultijugador();
        ~PartidaMultijugador();

        //get y set 
        dtPartidaMultijugador * getPartidaMultijugador();
        void setPartidaMultijugador(dtPartidaMultijugador*);

        IDictionary * getComentarios();
        IDictionary * getJugadores();
        ICollection * getPMJ();
        //metodo
        void confirmarPartida(int);
        void agregarPartida(string);
        //El getPatidas del diagrama suponemos que es el getPartidaMultijugador y no lo ponemos 
};

#endif //PartidaMultijugador class
