#ifndef comentario_
#define comentario_

#include <iostream>
//#include "../"
using namespace std;

class Comentario{
    private:
        int idComentario;
        string texto;
        dtFechaHora fechaHora;
    public:
        Comentario(int,string,dtFechaHora);
        Comentario();
        ~Comentario();

        //get y set
        int getIdComentario();
        string getTexto();
        dtFechaHora getFechaHora();

        void setIdComentario(int);
        void setTexto(string);
        void setFechaHora(dtFechaHora);

        void eliminarComentario();
};

#endif //Comentario class