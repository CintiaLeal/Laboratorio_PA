#include "../.h/dtPago.h"

dtPago::dtPago(){
};

dtPago::dtPago(dtFecha fv, dtFecha fc, string m, bool a){
    this->fechaV = fv;
    this->fechaContrato = fc;
    this->metodoPago = m;
    this->activa = a;
};

dtFecha dtPago::getFechaV(){
    return this->fechaV;
};

dtFecha dtPago::getFechaC(){
    return this->fechaContrato;
};

string dtPago::getMetodoPago(){
    return this->metodoPago;
};

bool dtPago::getActiva(){
    return this->activa;
};

dtPago::~dtPago(){};


        