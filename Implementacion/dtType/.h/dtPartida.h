#ifndef Dt_Partida
#define Dt_Partida
#include <iostream>
#include "../.cpp/dtFecha.cpp"
using namespace std;
class dtPartida{
    private:
        int idPartida;
        dtFecha * fecha;
        float duracion;
    public:
        dtPartida();
        dtPartida(int , dtFecha * , float );
        int getIdPartida();
        dtFecha *getFecha();
        float getDuracion();
        ~dtPartida();
};
#endif //Dt_Partida
