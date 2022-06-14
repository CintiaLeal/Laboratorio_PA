#ifndef partidaMultijugador_
#define partidaMultijugador_
#include <iostream>
#include "../../class/.h/Partida.h"
#include "../../dtType/.h/dtPartidaMultijugador.h"
#include "../../class/.h/Comentario.h"

using namespace std;

class PartidaMultijugador:public Partida{
    private:
        dtPartidaMultijugador * partidaMultijugador;
        IDictionary * comentarios; 
    public:
        PartidaMultijugador(int idPartida, dtPartida * p,dtPartidaMultijugador * partidaMultijugador);
        PartidaMultijugador();
        ~PartidaMultijugador();

        //get y set 
        dtPartidaMultijugador * getPartidaMultijugador();
        void setPartidaMultijugador(dtPartidaMultijugador*);

        IDictionary * getComentarios();
        
        //metodo
        void confirmarPartida(int);
        void agregarPartida(string);
        //El getPatidas del diagrama suponemos que es el getPartidaMultijugador y no lo ponemos 
};

#endif //PartidaMultijugador class
