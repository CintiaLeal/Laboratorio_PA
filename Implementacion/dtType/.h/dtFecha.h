#ifndef Dt_Fecha
#define Dt_Fecha
#include <iostream>
using namespace std;
class dtFecha{
    private:
        int dia;
        int mes;
        int anio;
        int hora;
        int minuto;
    public:
        dtFecha();
        dtFecha(int, int, int, int, int);
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMinuto();
};

#endif //Dt_Fecha