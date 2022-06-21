#ifndef ISISTEMA
#define ISISTEMA
#include <iostream>

#include "../.cpp/Partida.cpp"
#include "../.cpp/PartidaMultijugador.cpp"
#include "../.cpp/Usuario.cpp"
#include "../.cpp/Categoria.cpp"
#include "../.cpp/Desarrollador.cpp"
#include "../.cpp/Jugador.cpp"
#include "../.cpp/Videojuego.cpp"
#include "../.cpp/Suscripcion.cpp"
#include "../.cpp/Comentario.cpp"
#include "../.cpp/Pago.cpp"
//#include "../.h/VJ.h"
#include "../../ICollection/collections/List.cpp"
#include "../../ICollection\collections\ListIterator.cpp"
#include "../../ICollection\collections\ListNode.cpp"
#include "../../ICollection\collections\OrderedDictionary.cpp"
#include "../../ICollection\collections\OrderedDictionaryEntry.cpp"
#include "../../ICollection\interfaces\ICollectible.cpp"
#include "../../ICollection\interfaces\ICollection.cpp"
#include "../../ICollection\interfaces\IDictionary.cpp"
#include "../../ICollection\interfaces\IIterator.cpp"
#include "../../ICollection\interfaces\IKey.cpp"
#include "../../ICollection\interfaces\OrderedKey.cpp"
#include "../../ICollection\Integer.cpp"
#include "../../ICollection\String.cpp"

using namespace std;

class ISistema{
public:
    virtual ~ISistema(); //Destructor
  //  virtual void confirmarAltaUsuario(string,string,string,string) = 0;
    virtual void altaUsuarioDesarrollador(string email,string contrasenia,string nombreEmpresa) = 0;
    virtual void altaUsuarioJugador(string email,string contrasenia,string nick,string descripcion) = 0;
    virtual void listarCategoria() = 0;
    virtual dtVideojuego * altaVideojuego(string, string) = 0;
    virtual void nuevaCategoria(string nombre, string descripcion,int tipo) = 0;
    virtual bool existeCategoria(string) = 0;
    virtual Categoria * buscarCat(string) = 0;
    virtual void confirmarPublicarVideojuego(IDictionary *, dtVideojuego *) = 0;
    virtual void listarVideojuego() = 0;
    virtual void confirmarEliminarVideojuego(string) = 0;
    virtual void verEstadisticasVideojuego(string) = 0;
    virtual bool existeUsuario(string email,string contrasenia) =0;
    virtual string iniciarSesionActual(string email)=0;
    virtual void cerrarSesion()=0;
    virtual string getemailActual()=0;
    virtual string tipoUsuario(string email) = 0;
    virtual void agregarSuscripciones(string, int, int, int, int) = 0;
    virtual void verInformacionVideojuego(string) = 0;
    virtual bool existeVideojuego(string) = 0;
    virtual void listarVideojuegoCosto() = 0;
    virtual bool seleccionarVideojuegoSuscripcion(string nombre)= 0;
    virtual void cancelar(string nombre)= 0;
    virtual void confirmarSuscripcion(string tipo, string met, string nombre)= 0;
    virtual void puntuarVideojuego(string nomVideojuego, int punto) = 0;
    virtual void listarVideojuegoDescripcion() = 0;
    virtual bool listarVideojuegoSuscripcion() = 0;
    virtual bool listarPartidas(string) = 0;
    virtual void confirmarPartidaIndCont(string, int) = 0;
    virtual void confirmarPartidaInd(string) = 0;
    virtual bool listarPartidasActivas() = 0;
    virtual void confirmarFinalizarPartida(int)=0;
    virtual void cargarDatosPrueba()=0;
//<------------------Operaciones----------------------->
 /* 
    
    virtual void ingersarJugador(string, string, string, string) = 0;
    virtual void ingresarDesarrollador(string, string, string) = 0;
     //Retorna una lista de DtpPublicarVideojuego
   // virtual DtInfoVideojuego ingresarInfoVideojuego(set<float>,set<String>,set<String>,set<String>) = 0;
  
    //virtual DtMostrarPartida listarPartidas() = 0;
    virtual void confirmarPartida(int) = 0;
    virtual string nuevaPartidaMultijugador(string, bool) = 0;
    //virtual void confirmarMultijugador(set<String>) = 0;
    //virtual void nuevaPartidaIndividual(String) = 0;
    virtual void confirmarContinuar(int) = 0;
    virtual void confirmarNueva(string) = 0;
     //Retorna una lista de dtVideouegoCosto
    
    
    
    */

    virtual int hola() = 0;

};
#endif // ISISTEMA
