#include <iostream>

using namespace std;

class Categoria{
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
        void setNombre();
        void setDescripcion();
};