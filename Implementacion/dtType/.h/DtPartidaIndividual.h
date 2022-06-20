#ifndef Dt_PartidaIndividual
#define Dt_PartidaIndividual
#include <iostream>
#include "../.cpp/dtPartida.cpp"
#include "dtFecha.h"
using namespace std;

class dtPartidaIndividual:public dtPartida{
    private:
       dtPartidaIndividual* continua;
    public:
        dtPartidaIndividual();
        dtPartidaIndividual( int, dtFecha *, float, dtPartidaIndividual*);
        dtPartidaIndividual* getContinua();
        ~dtPartidaIndividual();
};
#endif //Dt_PartidaIndividual
