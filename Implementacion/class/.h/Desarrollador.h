#ifndef desarrollador_
#define desarrollador_
#include <iostream>



#include "Usuario.h"
#include "../../dtType/.h/dtPublicarVideojuego.h"
using namespace std;

class Desarrollador:public Usuario{
    private:
            string nombreEmpresa;
    public:
        Desarrollador(string);
        Desarrollador();
        ~Desarrollador();

        //get y set 
        string getNombreEmpresa();
        void setPartidaIndividual(dtPartidaIndividual*);

        //metodo
        dtpPublicarVideojuego altaVideojuego(string,string); //implementar dtpPublicarvideojuego en los dtyp
};
#endif 
