#ifndef Dt_PublicarVideojuego
#define Dt_PublicarVideojuego
#include <iostream>
#include "dtFecha.h"
#include "dtGenero.h"
#include "dtOtros.h"
#include "dtPlataforma.h"

#include "../../ICollection\interfaces\ICollection.cpp"
#include "../../ICollection\collections\List.cpp"


using namespace std;
class dtPublicarVideojuego{
    private:
        ICollection * Generos;
        ICollection * Otros;
        ICollection * Plataformas;
    public:
        dtPublicarVideojuego();
        ICollection* getGeneros();
        ICollection* getOtros();
        ICollection* getPlataformas();

        void agregarGenero(dtGenero*);
        void agregarOtro(dtOtros*);
        void agregarPlataforma(dtPlataforma*);
        ~dtPublicarVideojuego();
};
#endif //Dt_Pago