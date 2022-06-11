#ifndef usuario_
#define usuario_

#include <iostream>

#include "Partida.h"
//#include "../../dtType/.h/dtPartidaIndividual.h"
//#include "../../dtType/.h/dtPartida.h"
//#include "../../dtType/.h/dtUsuario.h"
//#include "../../dtType/.h/dtMostrarPartida.h"
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/collections/OrderedDictionary.h"

using namespace std;

class Usuario: public ICollectible{
    protected:
        string email;
        string contrasenia;
        //IDictionary * partidas; 
    public:
        Usuario(string,string);
        Usuario();
        ~Usuario();

        //get y set
        string getEmail();
        string getContrasenia();
        
        void setEmail(string);
        void setContrasenia(string);
             
        /*/metodos
        dtMostrarPartida listarPartidas();
        void confirmarPartidas(int);
        void confirmarMultijugador();
        void agregarPartida(Partida);
        dtPartidaIndividual getPartidasFinalizadas(string);
        void confirmarContinuar(int);
        void confirmarNueva(Partida *p);*/

};

#endif //Partida class