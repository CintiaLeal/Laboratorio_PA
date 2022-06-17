#ifndef SISTEMA
#define SISTEMA
#include "ISistema.h"
//#include "../../dtType/.cpp/dtCategoria.cpp"

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
        string getemailActual();  
        void altaUsuarioJugador(string email,string contrasenia,string nick,string descripcion);
        void altaUsuarioDesarrollador(string email,string contrasenia,string nombreEmpresa);
        void nuevaCategoria(string nombre, string descripcion, int tipo);
        virtual dtVideojuego * altaVideojuego(string, string);
        void listarCategoria();
        bool existeCategoria(string);
        Categoria * buscarCat(string);
        void confirmarPublicarVideojuego(IDictionary *, dtVideojuego *);
        void listarVideojuego();
        void confirmarEliminarVideojuego(string);
        void verEstadisticasVideojuego(string);
        bool existeUsuario(string email,string contrasenia);
        string iniciarSesionActual(string email);
        void cerrarSesion();
        string tipoUsuario(string email);
        //void cargarDatosPrueba();
        void agregarSuscripciones(string, int, int, int, int);
        void verInformacionVideojuego(string);
        bool existeVideojuego(string);
        void listarVideojuegoCosto();
        void seleccionarVideojuegoSuscripcion(string);
    /*    //<------------------Operaciones----------------------->
        //void confirmarAltaUsuario(string,string,string,string);
        void ingersarJugador(string,string,string,string);
        void ingresarDesarrollador(string,string,string);
        string listarVideojuego();
        void elegirVideojuegoEliminar(string);
        void confirmarEliminarVideojuego();
        //DtpPublicarVideojuego altaVideojuego(String,String);
        //DtInfoVideojuego ingresarInfoVideojuego(set<float>,set<String>,set<String>,set<String>);
        
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
