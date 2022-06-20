#include "../.h/Jugador.h"

#include <iostream>

using namespace std;

Jugador::Jugador(){
    this->pagos = new List();
    this->partidas = new OrderedDictionary();
}
Jugador::~Jugador(){
    
}
Jugador::Jugador(string email, string contrasenia,string nick, string descripcion): Usuario(email, contrasenia){
    this->nick = nick;
    this->descripcion = descripcion;
    this->pagos = new List();
    this->partidas = new OrderedDictionary();
  
}

ICollection * Jugador::getPagos(){
    return this->pagos;
}

IDictionary * Jugador::getPartidas(){
    return this->partidas;
}
string Jugador::getTipo(){
    string s = "soyJugador";
    return s;
}
//methods 
bool Jugador::member(string){}

string Jugador::listarVideojuego(){}

string Jugador::getNick(){
    return this->getNick();
}

void Jugador::borrarPagos(string nombre){
    IIterator * it;

    for(it = this->pagos->getIterator(); it->hasCurrent(); it->next()){
        Pago * p = (Pago *)it->getCurrent();
        if(p->getJuego()->getVideojuego()->getNombre() == nombre){
            this->pagos->remove(p);
            delete p;
        }
    }
}

void Jugador::borrarPartidas(string nombre){
    IIterator * it;

    for(it = this->partidas->getIterator(); it->hasCurrent(); it->next()){
        Partida * p = (Partida *)it->getCurrent();

        if(p->getVideojuego()->getVideojuego()->getNombre() == nombre){
            IKey * k = new Integer(p->getIdPartida());
            this->partidas->remove(k);
        }
    }
}

bool Jugador::buscarSuscripcion(string nombre){ //retorna true si el videojuego seleccionado no tiene pagos activos asociados o si desea cancelar la suscr actual
    IIterator * it;
    for(it=pagos->getIterator(); it->hasCurrent(); it->next()){
        Pago * p = (Pago *)it->getCurrent();
        //se encuentra un pago para el videojuego seleccionado
        if(p->getSuscripcion()->iguales(nombre)){
            //tiene una suscripcion activa
            if(p->getActiva()){
                //la suscripcion es vitalicia
                if(p->getSuscripcion()->getNombre() == "Vitalicia"){
                    cout << "Su suscripcion es vitalicia, no se puede cancelar." << endl;
                    return false;
                }
                //la suscripcion es temporal
                else{
                    cout<<"Usted posee una suscripcion temporal:"<<endl;
                    cout<< "Nombre:" << p->getSuscripcion()->getNombre();
                    cout<< "Precio:" << p->getSuscripcion()->getPrecio();
                    cout<<"Desea cancelar su suscripcion actual? 1-Si || 2-No"<<endl;
                    int op;
                    cin >> op;
                    if(op == 2){ //No desea cancelar su suscripcion actual
                        return false;
                    }
                    else{ //desea cancelar su suscripcion actual
                        p->setActiva(false);
                        return true;
                    }
                }
            }
        }     
    }
    return true;
}

void Jugador::cancelarSuscripcion(){}

void Jugador::nuevoSuscripcion(string met, Suscripcion* s, dtFecha * f){
    int mes = f->getMes(), anio = f->getAnio();
    if(s->getNombre() == "Mensual"){
        if(mes == 12){
            mes = 1;
            anio ++;
        }
        else {mes++;}
    }
    if(s->getNombre() == "Trimestral"){
        if((mes + 3) > 12){
            mes = (mes + 3) - 12;
            anio ++;
        }
    }
    if(s->getNombre() == "Anual"){
        anio ++;
    }
     if(s->getNombre() == "Vitalicia"){
        anio = 2420;
    }
    dtFecha * fv = new dtFecha(f->getDia() , mes, anio, f->getHora(), f->getMinuto());
    bool act = true;
    Pago * p = new Pago(fv, f, met, act, s);
    this->pagos->add(p);
}

void Jugador::cancelar(string nombre){
    IIterator * it;
    for(it=pagos->getIterator(); it->hasCurrent(); it->next()){
        Pago * p = (Pago *)it->getCurrent();
        //se encuentra el pago 
        if(p->getSuscripcion()->iguales(nombre)){
            p->setActiva(true);
        }
    }    
}

IDictionary * Jugador::listarVideojuegoConCosto(){
    IIterator * it;
    Suscripcion * s;
    IDictionary * jueguitos = new OrderedDictionary();
    if(this->pagos->isEmpty()){
        return jueguitos;
    }else{
        for(it=this->pagos->getIterator(); it->hasCurrent(); it->next()){
            Pago * p = (Pago *)it->getCurrent();
            if(p->getActiva()){
                s = p->getSuscripcion();
                Videojuego * v = s->getVideojuego();
                IKey * k = new String(v->getVideojuego()->getNombre().c_str());
                jueguitos->add(k, v);
            }
        }
    }
    return jueguitos;
}

void Jugador::listarPartidas(string nombre){
    IIterator * it;

    for(it=this->getPartidas()->getIterator();it->hasCurrent();it->next()){
        PartidaIndividual * p = (PartidaIndividual *)it->getCurrent();
        
        if(p->getVideojuego()->getVideojuego()->getNombre() == nombre){
            cout << "ID:" << p->getIdPartida() << " Fecha|Hora:" << /*p->getPartida()->getFecha()*/ " Duracion:" << p->getPartida()->getDuracion() << endl;
        }
    }
}