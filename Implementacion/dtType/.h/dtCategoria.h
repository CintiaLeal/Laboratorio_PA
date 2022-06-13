#ifndef dtCategoria_
#define dtCategoria_

#include <iostream>
#include <string>

using namespace std;

class dtCategoria : public ICollectible{
    protected:
        string nombre;
        string descripcion;
    public:
        //constructores
       
        dtCategoria(string nombre, string descripcion);
        //gets
        string getNombredt();
        string getDescripciondt();
        
};

#endif