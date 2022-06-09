#ifndef Dt_PublicarVideojuego
#define Dt_PublicarVideojuego
#include <iostream>
#include "dtFecha.h"
#include "dtGenero.h"
#include "dtPlataforma.h"
#include "dtOtros.h"
#include "ICollection\interfaces\ICollection.cpp"
#include "ICollection\collections\List.cpp"
using namespace std;
class dtPublicarVideojuego{
    private:
        ICollection * Generos;
        ICollection * Otros;
        ICollection * Plataformas;
    public:
        dtPublicarVideojuego();
        List* getGeneros();
        List* getOtros();
        List* getPlataformas();
    // FALTA HACER FUNCIONES QUE AGREGEN ELEMENTOS A LAS COLECCIONES

        ~dtPublicarVideojuego();
};
#endif //Dt_Pago