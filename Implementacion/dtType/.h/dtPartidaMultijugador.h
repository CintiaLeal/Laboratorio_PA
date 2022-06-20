#ifndef Dt_PartidaMultijugador
#define Dt_PartidaMultijugador
#include <iostream>
#include "dtPartida.h"
#include "dtFecha.h"
using namespace std;
class dtPartidaMultijugador: public dtPartida{
    private:
       bool EnVivo;
    public:
       dtPartidaMultijugador();
        dtPartidaMultijugador(int, dtFecha *, float, bool);
        bool getEnVivo();
        ~dtPartidaMultijugador();
};
#endif //Dt_PartidaMultijugador