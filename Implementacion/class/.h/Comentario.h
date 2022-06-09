#ifndef comentario_
#define comentario_

#include <iostream>

#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../ICollection/String.h"
#include "../../ICollection/Integer.h"
#include "../../dtType/.h/dtFecha.h"
using namespace std;

class Comentario: public ICollectible{
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