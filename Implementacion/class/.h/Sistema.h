#ifndef SISTEMA
#define SISTEMA
#include "ISistema.h"

class Sistema: public ISistema{
    private:
        // constructor
        Sistema();
        static Sistema * instancia;
    public:
        string listarVideojuego();
        void elegirVideojuegoEliminar(string);
        void confirmarEliminarVideojuego();
        void ingersarJugador(string,string,string,string);
        void ingresarDesarrollador(string,string ,string);
        void confirmarAltaUsuario();
        //DtpPublicarVideojuego altaVideojuego(String,String);
        //DtInfoVideojuego ingresarInfoVideojuego(set<float>,set<String>,set<String>,set<String>);
        void confirmarPublicarVideojuego();
        //DtMostrarPartida listarPartidas();
        void confirmarPartida(int);
        string nuevaPartidaMultijugador(string,bool);
        //void confirmarMultijugador(set<String>);
        void nuevaPartidaIndividual(string);
        void confirmarContinuar(int);
        void confirmarNueva(string);
        ICollection* listarVideojuegoConCosto();
        void seleccionarVideojuegoSuscripcion(string);
        void cancelarSuscr();
        void confirmarSuscripcion(string, string);
        void cancelar();
    


};
#endif // SISTEMA