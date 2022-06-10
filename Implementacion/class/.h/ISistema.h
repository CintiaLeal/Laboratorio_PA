#ifndef ISISTEMA
#define ISISTEMA
#include <iostream>

#include "../../ICollection/interfaces/ICollection.h"
#include "../../ICollection/interfaces/IDictionary.h"
using namespace std;

class ISistema{
public:
    virtual ~ISistema(); //Destructor

//<------------------Operaciones----------------------->
    virtual string listarVideojuego() = 0;
    virtual void elegirVideojuegoEliminar(string) = 0;
    virtual void confirmarEliminarVideojuego() = 0;
    virtual void ingersarJugador(string, string, string, string) = 0;
    virtual void ingresarDesarrollador(string, string, string) = 0;
    virtual void confirmarAltaUsuario() = 0;
    virtual ICollection * altaVideojuego(string, string) = 0; //Retorna una lista de DtpPublicarVideojuego
   // virtual DtInfoVideojuego ingresarInfoVideojuego(set<float>,set<String>,set<String>,set<String>) = 0;
    virtual void confirmarPublicarVideojuego() = 0;
    //virtual DtMostrarPartida listarPartidas() = 0;
    virtual void confirmarPartida(int) = 0;
    virtual string nuevaPartidaMultijugador(string, bool) = 0;
    //virtual void confirmarMultijugador(set<String>) = 0;
    //virtual void nuevaPartidaIndividual(String) = 0;
    virtual void confirmarContinuar(int) = 0;
    virtual void confirmarNueva(string) = 0;
    virtual ICollection * listarVideojuegoConCosto() = 0; //Retorna una lista de dtVideouegoCosto
    virtual void seleccionarVideojuegoSuscripcion(string) = 0;
    virtual void cancelarSuscr() = 0;
    virtual void confirmarSuscripcion(string,string) = 0;
    virtual void cancelar() = 0;

};
#endif // ISISTEMA