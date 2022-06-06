#ifndef Dt_Comentario
#define Dt_Comentario
#include <iostream>
#include "dtFecha.h"
using namespace std;
class dtComentario{
    private:
        int idComentario;
        string texto;
        dtFecha fecha; 
    public:
        dtComentario();
        dtComentario(int, string, dtFecha);
        int getIdComentario();
        string getTexto();
        dtFecha getFecha();
        ~dtComentario();
};
#endif //Dt_Comentario