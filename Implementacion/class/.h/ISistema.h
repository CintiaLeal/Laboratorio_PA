#ifndef ISISTEMA
#define ISISTEMA
#include <iostream>

#include "../.cpp/Usuario.cpp"
#include "../.cpp/Categoria.cpp"
#include "../.cpp/Desarrollador.cpp"
#include "../../ICollection/collections/List.h"
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
    virtual void nuevaCategoria(string nombre, string descripcion) = 0;
    virtual ICollection* listarCategoria() = 0;
    virtual void confirmarPublicarVideojuego(string, string) = 0;

//<------------------Operaciones----------------------->
 /* virtual string listarVideojuego() = 0;
    virtual void elegirVideojuegoEliminar(string) = 0;
    virtual void confirmarEliminarVideojuego() = 0;
    virtual void ingersarJugador(string, string, string, string) = 0;
    virtual void ingresarDesarrollador(string, string, string) = 0;
    virtual ICollection * altaVideojuego(string, string) = 0; //Retorna una lista de DtpPublicarVideojuego
   // virtual DtInfoVideojuego ingresarInfoVideojuego(set<float>,set<String>,set<String>,set<String>) = 0;
    
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
    virtual void cancelar() = 0;*/

    virtual int hola() = 0;

};
#endif // ISISTEMA