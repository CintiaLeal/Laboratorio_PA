#include "../../class/.h/Sistema.h"
#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

Sistema * Sistema::instancia = 0;

Sistema::Sistema(){
    this->dicUsuario = new OrderedDictionary();
    this->dicCategoria = new OrderedDictionary();
    this->dicVideojuego = new OrderedDictionary();
}
Sistema::~Sistema(){ }

Sistema * Sistema::getInstancia() {
    if (instancia == 0) {
        instancia = new Sistema();
    }
    return instancia;
}

void Sistema::altaUsuarioDesarrollador(string email,string contrasenia,string nombreEmpresa){
    IKey * k = new String(email.c_str());
    if(this->dicUsuario->member(k)){
        cout<<"Un usuario con este nombre ya existe, por favor ingrese otro";
        
    }
    else{
        Desarrollador *d = new Desarrollador(email,contrasenia, nombreEmpresa);
        dicUsuario->add(k,d);
        
    }
}
void Sistema::altaUsuarioJugador(string email,string contrasenia,string nick,string descripcion){
    IKey * k = new String(email.c_str());
    if(this->dicUsuario->member(k)){
        cout<<"Ya existe";
        
    }
    else{
        
        Jugador * jug = new Jugador(email,contrasenia,nick,descripcion);
        dicUsuario->add(k,jug);
        
    }
}
void Sistema::nuevaCategoria(string nombre,string descripcion,int tipo){
    string tipog;
    if(tipo==1){
        tipog="Plataforma";
    }
    if(tipo==2){
        tipog="Genero";
    }
    if(tipo==3){
        tipog="Otro";
    }
    IKey * k = new String(nombre.c_str());
    if(this->dicCategoria->member(k)){
        cout<<"Ya existe"<<endl; 
    }
    else{
        Categoria *c = new Categoria(nombre,descripcion,tipog);
        dicCategoria->add(k,c);
        
    }
}

bool Sistema::existeCategoria(string nombre){
    IKey * k = new String(nombre.c_str());
    if(dicCategoria->member(k)){
        return true;
    }else{
        return false;
    }
}

Categoria * Sistema::buscarCat(string nombre){
    IKey * k = new String(nombre.c_str());
    Categoria * aux = (Categoria *)dicCategoria->find(k);
    delete(k);
    return aux;
}

dtVideojuego* Sistema::altaVideojuego(string nombre, string descripcion){
    bool existe = true;
    string nom = nombre;
    do{
        IKey * k = new String(nom.c_str());
        if(this->dicVideojuego->member(k)){
            cout << "Este videojuego ya existe, ingrese otro nombre" << endl;
            cin >> nom;
        }else{
            existe = false;
        }
    }while(existe);
    dtVideojuego * vid = new dtVideojuego(nom, descripcion, 0);
    return vid;
}

void Sistema::confirmarPublicarVideojuego(IDictionary * cat, IDictionary * sus, dtVideojuego * videojuego){

    Videojuego * vid = new Videojuego(videojuego);
    vid->setSuscripciones(sus);
    vid->setCategorias(cat);
    IKey * k = new String(videojuego->getNombre().c_str());
    dicVideojuego->add(k,vid);
}

void Sistema::listarCategoria(){ 
    IIterator * it;
    //IMPRIMIR SOLO PLATAFORMAS
    cout << "PLATAFORMAS" << endl;
	for (it= this->dicCategoria->getIterator();it->hasCurrent();it -> next()){
        Categoria * u = (Categoria*)it->getCurrent();
        if(u->getTipog() == "Plataforma"){
		    string nombre = u->getNombre();
		    cout << nombre << endl;
        }
	}
    //IMPRIMIR SOLO GENEROS
    cout << "GENEROS" << endl;
    for (it= this->dicCategoria->getIterator();it->hasCurrent();it -> next()){
        Categoria * u = (Categoria*)it->getCurrent();
        if(u->getTipog() == "Genero"){
		    string nombre = u->getNombre();
		    cout << nombre << endl;
        }
	}
    //IMPRIMIR SOLO OTROS
    cout << "OTROS" << endl;
    for (it= this->dicCategoria->getIterator();it->hasCurrent();it -> next()){
        Categoria * u = (Categoria*)it->getCurrent();
        if(u->getTipog() == "Otro"){
		    string nombre = u->getNombre();
		    cout << nombre << endl;
        }
	}
}

void Sistema::listarVideojuego(){
    IIterator * it;
    IIterator * it2;
    
    for(it=this->dicVideojuego->getIterator(); it->hasCurrent(); it->next()){
        Videojuego * v = (Videojuego*)it->getCurrent();

        if(!v->getPartidas()->getIterator()->hasCurrent()){
            cout << "Nombre:" << v->getVideojuego()->getNombre() << endl;
        }else{
            for (it2 = v->getPartidas()->getIterator(); it2->hasCurrent(); it2->next()){
                Partida * p = (Partida*)it->getCurrent();
                
                if(p->getActiva()){
                    cout << "Nombre:" << v->getVideojuego()->getNombre() << endl;
                }
            }
        }
    }
}

void Sistema::confirmarEliminarVideojuego(string nombre){
    string nom = nombre; 
    bool existe = false;
    
    do{
        IKey * k = new String(nom.c_str());
        if(dicVideojuego->member(k)){
            existe = true;
            delete k;
        }else{
            cout << "No existe este videojuego, ingrese uno correcto" << endl;
            cin >> nom;
        }
    }while(!existe);

    IIterator * it;
    IIterator * it2;

    IKey * k = new String(nom.c_str());
    Videojuego * vid = (Videojuego *)dicVideojuego->find(k);

    //Borrar partidas y comentarios
    for(it = vid->getPartidas()->getIterator(); it->hasCurrent(); it->next()){
        Partida * p = (Partida *)it->getCurrent();
        
        if(!p->getIndividual()){
            PartidaMultijugador * pm = (PartidaMultijugador *)p;

            for(it2 = pm->getComentarios()->getIterator(); it2->hasCurrent(); it2->next()){
                Comentario * c = (Comentario *)it2->getCurrent();
                IKey * k2 = new Integer(c->getIdComentario());
                pm->getComentarios()->remove(k2);
                delete(k2);
                delete(it2->getCurrent());
            }
            delete(pm);
        }
        IKey * k2 = new Integer(p->getIdPartida());
        vid->getPartidas()->remove(k2);
        delete(k2);
        delete(it->getCurrent());
    }

    //Borrar VJ
    for(it = vid->getVJ()->getIterator(); it->hasCurrent(); it->next()){
        VJ * vj = (VJ *)it->getCurrent();
        Jugador * j = vj->getJugador();
        //Borra pagos
        j->borrarPagos(nom);
        j->borrarPartidas(nom);

        delete(vj);
    }

    //BorrarSuscripcioens
    vid->eliminarSuscripcion(nom);

    dicVideojuego->remove(k);
    delete(k);
    delete(vid);
}