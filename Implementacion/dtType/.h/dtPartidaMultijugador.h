#ifndef Dt_PartidaMultijugador
#define Dt_PartidaMultijugador
#include <iostream>
#include "dtPartida.h"
#include "dtFecha.h"
using namespace std;
class dtPartidaMultijugador{
    private:
       bool EnVivo;
    public:
        dtPartidaMultijugador(bool);
        dtFecha getFecha();
        ~dtPartidaMultijugador();
};
#endif //Dt_PartidaMultijugador