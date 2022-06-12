#ifndef Categoria_
#define Categoria_
#include "../../ICollection/interfaces/ICollectible.h"
#include "../../ICollection/collections/OrderedDictionary.h"
#include "../../dtType/.cpp/dtCategoria.cpp"
#include <iostream>

using namespace std;

class Categoria:public ICollectible{
    private:
        string nombre;
        string descripcion;
    public:
        //constructores
        Categoria();
        Categoria(string, string);
        //gets
        string getNombre();
        string getDescripcion();
        //sets
        void setNombre(string);
        void setDescripcion(string);
        dtCategoria* getDataType();
};

#endif