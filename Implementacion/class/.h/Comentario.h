#ifndef comentario_
#define comentario_

#include <iostream>
#include "../../dtType/.h/dtFecha.h"
using namespace std;

class Comentario{
    private:
        int idComentario;
        string texto;
        dtFecha fecha;
    public:
        Comentario(int,string,dtFecha);
        Comentario();
        ~Comentario();

        //get y set
        int getIdComentario();
        string getTexto();
        dtFecha getFecha();

        void setIdComentario(int);
        void setTexto(string);
        void setFecha(dtFecha);

        void eliminarComentario();
};

#endif //Comentario class