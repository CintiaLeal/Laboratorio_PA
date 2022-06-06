#ifndef Dt_PartidaIndividual
#define Dt_PartidaIndividual
#include <iostream>
#include "Partida.h"
#include "dtFecha.h"
using namespace std;
class dtPartidaIndividual{
    private:
       dtPartidaIndividual* continua;
    public:
        dtPartidaIndividual();
        dtFecha getFecha();
        float getDuracion();
        ~dtPartidaIndividual();
};
#endif //Dt_PartidaIndividual

