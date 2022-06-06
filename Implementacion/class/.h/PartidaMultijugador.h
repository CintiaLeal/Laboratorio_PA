#ifndef partidaMultijugador_
#define partidaMultijugador_
#include <iostream>
//#include "../"
using namespace std;

class PartidaMultijugador:public Partida{
    private:
            dtPartidaMultijugador * partidaMultijugador;
            dtComentario * comentario;
    public:
        PartidaMultijugador(dtPartidaMultijugador * partidaMultijugador, dtComentario comentario);
        PartidaMultijugador();
        ~PartidaMultijugador();

        //get y set 
        dtPartidaMultijugador * getPartidaMultijugador();
        dtComentario * getComentario();
        void setPartidaMultijugador(dtPartidaMultijugador*);
        void setComentario(dtComentario*);
        
        //metodo
        void confirmarPartida(int);
        void agregarPartida(string);

        //El getPatidas del diagrama suponemos que es el getPartidaMultijugador y no lo ponemos 
}

#endif //PartidaMultijugador class
