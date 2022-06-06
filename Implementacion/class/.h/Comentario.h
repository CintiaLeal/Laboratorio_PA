#ifndef comentario_
#define comentario_

#include "../../dtType/.h/dtFecha.h"
#include <iostream>
#include "../../dtType/.h/dtFecha.h"
using namespace std;

class Comentario{
    private:
        int idComentario;
        string texto;
        dtFecha fechaHora;
        dtFecha fecha;
    public:
        Comentario(int,string,dtFecha);
        Comentario();
        ~Comentario();

        //get y set
        int getIdComentario();
        string getTexto();

        dtFecha getFechaHora();

        void setIdComentario(int);
        void setTexto(string);
        void setFechaHora(dtFecha);

        dtFecha getFecha();

        void setIdComentario(int);
        void setTexto(string);
        void setFecha(dtFecha);
        void eliminarComentario();
};

#endif //Comentario class