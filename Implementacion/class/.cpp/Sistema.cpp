#include "../../class/.h/Sistema.h"
#include <stdexcept>

Sistema * Sistema::instancia = 0;

Sistema::Sistema(){ }
Sistema::~Sistema(){ }

Sistema * Sistema::getInstancia() {
    if (instancia == 0) {
        instancia = new Sistema();
    }
    return instancia;
}