#ifndef Dt_PublicarVideojuego
#define Dt_PublicarVideojuego
#include <iostream>
#include "dtFecha.h"
#include "dtGenero.h"
#include "dtPlataforma.h"
#include "dtOtros.h"
using namespace std;
class dtPublicarVideojuego{
    private:
        dtGenero * genero;
        dtOtros * otros;
        dtPlataforma * plataforma;

    public:
        dtPublicarVideojuego(dtGenero, dtOtros, dtPlataforma);
        dtPublicarVideojuego();

        dtGenero getGenero();
        dtOtros getOtros();
        dtPlataforma getPlataforma();
};
#endif //Dt_Pago