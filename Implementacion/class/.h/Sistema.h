#ifndef SISTEMA
#define SISTEMA
#include "ISistema.h"

class Sistema: public ISistema{
    private:
        // constructor
        Sistema();
        static Sistema * instancia;
        IDictionary * dicUsuario;
        IDictionary * dicCategoria;
        IDictionary * dicVideojuego;
    public:
        virtual ~Sistema();              //Destructor
        static Sistema * getInstancia(); //Devuelve el controlador Sistema (Singleton)
        //void confirmarAltaUsuario(string,string,string,string);
        void altaUsuarioDesarrollador(string email,string contrasenia,string nombreEmpresa);

    /*    //<------------------Operaciones----------------------->
        void ingersarJugador(string,string,string,string);
        void ingresarDesarrollador(string,string,string);
        string listarVideojuego();
        void elegirVideojuegoEliminar(string);
        void confirmarEliminarVideojuego();
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
    */
        int hola(){
         int hola = 10;
         return hola;  
        }


};
#endif // SISTEMA