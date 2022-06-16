#ifndef desarrollador_
#define desarrollador_
#include <iostream>

#include "Usuario.h"
//#include "../../dtType/.h/dtPublicarVideojuego.h"
using namespace std;

class Desarrollador:public Usuario{
    private:
            string nombreEmpresa;
    public:
        Desarrollador(string, string, string);
        Desarrollador();
        ~Desarrollador();

        //get y set 
        string getNombreEmpresa();
        void setNombreEmpresa(string);
        string getTipo();
        //void setPartidaIndividual(dtPartidaIndividual*); RANDOM

        //metodo
        //dtPublicarVideojuego altaVideojuego(string,string); 
};
#endif 
