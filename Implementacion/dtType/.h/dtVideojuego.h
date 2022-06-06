#ifndef Dt_Videojuego
#define Dt_Videojuego
#include <iostream>
using namespace std;
class dtVideojuego{
    private:
       string nombre;
       string descripcion;
       float cantHorasJug;
    public:
        dtVideojuego();
        dtVideojuego(string, string, float);
        string getNombre();
        string getDescripcion();
        float getCantHorasJug();
        ~dtVideojuego();
};
#endif //Dt_Videojuego