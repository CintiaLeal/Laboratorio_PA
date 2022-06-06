#ifndef Dt_Jugador
#define Dt_Jugador
#include <iostream>
using namespace std;
class dtJugador{
    private:
       string nickname;
       string descripcion;
    public:
        dtJugador();
        dtJugador(string, string);
        string getNickname();
        string getDescripcion();
        ~dtJugador();
};
#endif //Dt_Jugador