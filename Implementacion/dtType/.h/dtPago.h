#ifndef Dt_Pago
#define Dt_Pago
#include <iostream>
#include "dtFecha.h"
using namespace std;
class dtPago{
    private:
        dtFecha fechaV; //fechaVencimiento
        dtFecha fechaContrato;  
        string metodoPago;
        bool activa;
    public:
       //constructores
        dtPago();
        dtPago(dtFecha, dtFecha, string, bool);
        //gets
        dtFecha getFechaV();
        dtFecha getFechaC();
        string getMetodoPago();
        bool getActiva();
};
#endif //Dt_Pago