#include "../.h/Jugador.h"
#include "PartidaIndividual.cpp"
#include "../../dtType/.cpp/DtPartidaIndividual.cpp"
#include "../../dtType/.cpp/DtPartidaMultijugador.cpp"
#include "../../class/.cpp/PMJ.cpp"
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
                    do{
                      cin >> op;
                      if(op != 1 && op != 2){
                        cout<<"Ingrese una opcion correcta"<<endl;
                      }
                      }while(op != 1 && op != 2);
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

bool Jugador::listarPartidas(string nombre){
    IIterator * it;
    int cont = 0;
    for(it=this->getPartidas()->getIterator();it->hasCurrent();it->next()){
        PartidaIndividual * p = (PartidaIndividual *)it->getCurrent();
        
        if(p->getVideojuego()->getVideojuego()->getNombre() == nombre){
            if(!p->getActiva()){
                cout << "ID:" << p->getIdPartida() << " Fecha|Hora: ";
                p->getPartidaIndividual()->imprimirFecha(p->getPartidaIndividual()->getFecha());
                cout << " Duracion:" << p->getPartidaIndividual()->getDuracion() << endl;
                cont++;
            }
        }
    }
    if(cont == 0){
        //no se encontraron partidas para ese juego
        cout<<"no se encontraron partidas para ese juego"<<endl;
        return false;
    }
    else {return true;}
}

void Jugador::cambiarEstado(int pa){
IIterator * it;
    for(it=this->getPartidas()->getIterator();it->hasCurrent();it->next()){
        PartidaIndividual * p = (PartidaIndividual *)it->getCurrent();
        if (p->getIdPartida()==pa){
            p->setActiva(true);
        }
}
}

void Jugador::createNuevaIndcont(string nom, int pa, int id, dtFecha * fecha){
    dtPartidaIndividual * dtPCont;
    IKey * k = new Integer(pa);
    PartidaIndividual * pcont = (PartidaIndividual *)this->partidas->find(k);
    if(pcont->getIdPartida() == pa){
        dtPCont = pcont->getPartidaIndividual();
    }
    int aux = pcont->getPartidaIndividual()->getId();
    IIterator * it2;
    Videojuego * vid;
    for(it2=this->pagos->getIterator();it2->hasCurrent();it2->next()){
        Pago * p = (Pago*)it2->getCurrent();
        if(p->getSuscripcion()->getVideojuego()->getVideojuego()->getNombre() == nom){
             vid = p->getSuscripcion()->getVideojuego();
        }
    }
    dtPartidaIndividual * dtpi = new dtPartidaIndividual(id, fecha, 0, dtPCont,true);
    PartidaIndividual * pi = new PartidaIndividual(dtpi);
    pi->setActiva(true);
    pi->setIdPartida(id);
    pi->setIndividual(true);
    pi->setVideoJuego(vid);
    pi->getPartidaIndividual()->getContinua()->setId(aux);
    IKey * kid = new Integer(id);
    this->partidas->add(kid, pi);
}

void Jugador::createNuevaInd(string nom, int id, dtFecha * fecha){
    IIterator * it2;
    Videojuego * vid;
    for(it2=this->pagos->getIterator();it2->hasCurrent();it2->next()){
        Pago * p = (Pago*)it2->getCurrent();
        if(p->getSuscripcion()->getVideojuego()->getVideojuego()->getNombre() == nom){
             vid = p->getSuscripcion()->getVideojuego();
        }
    }
    dtPartidaIndividual * dtpi = new dtPartidaIndividual(id, fecha, 0, NULL,false);
    PartidaIndividual * pi = new PartidaIndividual();
    pi->setPartidaIndividual(dtpi);
    pi->setActiva(true);
    pi->setIdPartida(id);
    pi->setIndividual(true);
    pi->setVideoJuego(vid);
    IKey * kid = new Integer(id);
    this->partidas->add(kid, pi);
}

bool Jugador::listarPartidasActivas(){
    IIterator * it;
    int cont = 0;
    for(it=this->getPartidas()->getIterator();it->hasCurrent();it->next()){
        Partida * p = (Partida *)it->getCurrent();
            if(p->getActiva()){
                cout << "ID:" << p->getIdPartida() << " VideoJuego ";
                cout << p->getVideojuego()->getVideojuego()->getNombre();
                if(p->getIndividual()){
                    PartidaIndividual * pi = (PartidaIndividual*)p;
                    cout<<" Fecha|Hora:"<<endl;
                    pi->getPartidaIndividual()->imprimirFecha(pi->getPartidaIndividual()->getFecha());
                    if (pi->getPartidaIndividual()->getCont()){
                        cout<<"Es continuacion de la partida: "<< pi->getPartidaIndividual()->getContinua()->getId() << endl;;
                    }else{
                    }
                    if (pi->getPartidaIndividual()->getContinua() != NULL){
                        cout<<"Es continuacion de la partida: "<< pi->getPartidaIndividual()->getContinua()->getId()<<endl;
                    }
                    else{cout<<"No es continuacion de ninguna partida"<<endl; }
                }
                else{
                    PartidaMultijugador * pm = (PartidaMultijugador *)p;
                    cout<<"Fecha|Hora:  ";
                    pm->getPartidaMultijugador()->imprimirFecha(pm->getPartidaMultijugador()->getFecha()) ;
                    cout<<"La partida ";
                    if(pm->getPartidaMultijugador()->getEnVivo()){
                        cout<<"SI ";
                    }
                    else{cout<<"NO ";} 
                    cout<<"fue transmitida en vivo"<<endl;
                    cout<<"Jugadores que se unieron a la partida: "<< endl;
                    IIterator * it2;
                    for(it2=pm->getJugadores()->getIterator();it2->hasCurrent();it2->next()){
                        Jugador * jug =(Jugador*) it2->getCurrent();
                        cout<<jug->getNick()<<endl;
                    }
                }
                cont++;
            }
        
    }
    if(cont == 0){
        //no se encontraron partidas para ese juego
        cout<<"no se encontraron partidas para ese juego"<<endl;
        return false;
    }
    else {return true;}
}

 void Jugador::finalizarPartida(int id, dtFecha* fecha){
    IKey * kid = new Integer(id);
    Partida * p = (Partida*)this->partidas->find(kid);
    if(p->getIndividual()){
        PartidaIndividual * pi = (PartidaIndividual*)p;
        dtFecha * fechaI = pi->getPartidaIndividual()->getFecha();
        pi->setActiva(false);
        pi->getPartidaIndividual()->setDuracion(calcularDuracion(fechaI, fecha));
    }
    else{
        PartidaMultijugador * pm = (PartidaMultijugador*)p;
        dtFecha * fechaI = pm->getPartidaMultijugador()->getFecha();
        pm->setActiva(false);
        pm->getPartidaMultijugador()->setDuracion(calcularDuracion(fechaI, fecha));
        IIterator * it;
        for(it= pm->getPMJ()->getIterator();it->hasCurrent();it->next()){
            PMJ * pmj = (PMJ *)it->getCurrent();
            if (pmj->getHoraSalida() == NULL){
                pmj->setHoraSalida(fecha);
        }
        }
    
    
    }
 }

 float Jugador::calcularDuracion(dtFecha * fi, dtFecha * ff){
    float dur = 0;
    dur = dur + (( ff->getAnio() - fi->getAnio() ) * 8640);
    dur = dur + (( ff->getMes() - fi->getMes() ) * 720);
    dur = dur + (( ff->getDia() - fi->getDia() ) * 24);
    dur = dur + ( ff->getHora() - fi->getHora() );
    dur = dur + ( ( ff->getMinuto() - fi->getMinuto() ) / 60  );
    return dur;
 }