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
<<<<<<< HEAD
        dtFecha fechaHora;
=======
        dtFecha fecha;
>>>>>>> 569f72cbd27fe852a386e0dfe3af202ed3ae725d
    public:
        Comentario(int,string,dtFecha);
        Comentario();
        ~Comentario();

        //get y set
        int getIdComentario();
        string getTexto();
<<<<<<< HEAD
        dtFecha getFechaHora();

        void setIdComentario(int);
        void setTexto(string);
        void setFechaHora(dtFecha);
=======
        dtFecha getFecha();

        void setIdComentario(int);
        void setTexto(string);
        void setFecha(dtFecha);
>>>>>>> 569f72cbd27fe852a386e0dfe3af202ed3ae725d

        void eliminarComentario();
};

#endif //Comentario class