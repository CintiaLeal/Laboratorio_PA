#ifndef Dt_Partida
#define Dt_Partida
#include <iostream>
#include "../.cpp/dtFecha.cpp"
using namespace std;
class dtPartida{
    private:
        int id;
        dtFecha * fecha;
        float duracion;
    public:
        dtPartida();
        dtPartida(int, dtFecha * , float );
        dtFecha *getFecha();
        float getDuracion();
        void setId(int);
        int getId();
        ~dtPartida();
        void imprimirFecha(dtFecha *);
        void setDuracion(float);
};
#endif //Dt_Partida
