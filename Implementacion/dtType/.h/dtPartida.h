#ifndef Dt_Partida
#define Dt_Partida
#include <iostream>
#include "dtFecha.h"
using namespace std;
class dtPartida{
    private:
       dtFecha fecha;
       float durcion;
    public:
        dtPartida();
        dtFecha getFecha();
        float getDuracion();
        ~dtPartida();
};
#endif //Dt_Partida