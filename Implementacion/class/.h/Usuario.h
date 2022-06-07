#ifndef usuario_
#define usuario_

#include <iostream>

#include "Partida.h"
#include "../../dtType/.h/dtPartidaIndividual.h"
#include "../../dtType/.h/dtPartida.h"
#include "../../dtType/.h/dtUsuario.h"
#include "../../dtType/.h/dtMostrarPartida.h"
using namespace std;

class Usuario{
    protected:
        string email;
        string contrasenia;
        dtPartida * partidas; 
    public:
        Usuario(string,string,Partida);
        Usuario();
        ~Usuario();

        //get y set
        string getEmail();
        string getContrasenia();
        dtPartida * getPartidas();

        void setEmail(string);
        void setContrasenia(string);
        void setPartidas(dtPartida*);
        
        
        //metodos
        dtMostrarPartida ListarPartidas();
        void confirmarPartidas(int);
        void confirmarMultijugador(/*set<string>*/);
        void agregarPartida(Partida);
        dtPartidaIndividual getPartidasFinalizadas(string);
        void confirmarContinuar(int);
        void confirmarNueva(string);

};

#endif //Partida class