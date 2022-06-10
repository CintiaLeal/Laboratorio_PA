#ifndef dtCategoria_
#define dtCategoria_

#include <iostream>
#include "..\..\ICollection\interfaces\ICollectible.h"
using namespace std;

class dtCategoria : public ICollectible{
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