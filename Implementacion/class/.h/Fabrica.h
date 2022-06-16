
#ifndef FABRICA_H
#define FABRICA_H
#include "Sistema.h"
#include "ISistema.h"
//Fabrica
class Fabrica{
public:
    static Fabrica * getInstancia(); //Devuelve la instancia de la fabrica(Singleton)
    static ISistema * crearSistema(); //Devuelve el controlador Sistema (Singleton)
    virtual ~Fabrica();
private:
    Fabrica();
    static Fabrica * instancia;
};

#endif // FABRICA_H