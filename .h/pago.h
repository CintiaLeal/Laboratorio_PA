#include <iostream>

using namespace std;

class Pago{
    private:
        dtFecha fechaV;
        dtFecha fechaContrato;
        string metodoPago;
        bool activa;
    public:
        //constructores
        Pago();
        Pago(dtFecha, dtFecha, string, bool);
        //gets
        dtFecha getFechaV();
        dtFecha getFechaC();
        string getMetodoPago();
        bool getActiva();
        //sets
        void setFechaV(dtFecha);
        void setFechaC(dtFecha);
        void setMetodoPago(string);
        void setFechaC(bool);
        //methods
        Videojuego getJuego();
        dtVideojuego buscarVideojuego(string);

        void cambiarEstado();
};