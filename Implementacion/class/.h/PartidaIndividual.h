#ifndef partidaIndividual_
#define partidaIndividual_
#include <iostream>
#include "../../dtType/.h/dtPartidaIndividual.h"
#include "../../class/.h/Partida.h"
using namespace std;

class PartidaIndividual:public Partida{
    private:
            dtPartidaIndividual * partidaIndividual;
    public:
        PartidaIndividual(dtPartidaIndividual * partidaIndividual);
        PartidaIndividual();
        ~PartidaIndividual();

        //get y set 
        dtPartidaIndividual * getPartidaIndividual();
        void setPartidaIndividual(dtPartidaIndividual*);

        //metodo
        //confuso el getPatida
        //dtPartidaIndividual *getPartidas();
        void confirmarPartida(int);
        bool esFinalizada();
        bool iguales(int);
        //dtPartidaIndividual *getData();
};

#endif 

