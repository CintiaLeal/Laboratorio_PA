#ifndef dtCategoria_
#define dtCategoria_

#include <iostream>

using namespace std;

class dtCategoria{
    protected:
        string nombre;
        string descripcion;
    public:
        //constructores
        dtCategoria();
        dtCategoria(string, string);
        //gets
        string getNombre();
        string getDescripcion();
        
};

#endif