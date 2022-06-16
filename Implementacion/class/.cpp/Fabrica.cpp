#include "../../class/.h/Fabrica.h"


Fabrica::Fabrica(){ //Constructor
}

Fabrica * Fabrica::instancia = 0;

Fabrica * Fabrica::getInstancia(){
    if( instancia == 0 ){
        instancia = new Fabrica();
    }
    return instancia;
   
}

ISistema * Fabrica::crearSistema(){
    return Sistema::getInstancia();  
}

Fabrica::~Fabrica(){ //Destructor
}