#ifndef Categoria_
#define Categoria_

#include <iostream>

using namespace std;

class Categoria{
    protected:
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
};

#endif