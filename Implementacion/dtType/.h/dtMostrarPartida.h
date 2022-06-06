#ifndef dtMostrarPartida_
#define dtMostrarPartida_

#include <iostream>
//#include "../"
using namespace std;

class dtMostrarPartida{
    private:
        string nombreVideojuego;
        dtPartida * partida;
    public:
        dtMostrarPartida(string, dtPartida*);
        dtMostrarPartida();
        ~dtMostrarPartida();

        //get y set
        string getNombreVideojuego();
        dtPartida getPartida();
       
};

#endif //dtMostrarPartida dt