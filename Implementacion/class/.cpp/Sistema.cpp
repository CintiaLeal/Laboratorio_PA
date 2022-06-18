#include "../../class/.h/Sistema.h"
#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

Sistema * Sistema::instancia = 0;
//Datos actual usuario
string emailActual = "";
dtFecha *fecha = new dtFecha(21, 6, 2022, 12, 0);
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

void Sistema::agregarSuscripciones(string nombre, int a, int b, int c, int d){
    IKey * k = new String(nombre.c_str());

    Videojuego * vid = (Videojuego *)dicVideojuego->find(k);
    vid->agregarSuscripcion(a,b,c,d);
   
}

void Sistema::confirmarPublicarVideojuego(IDictionary * cat, dtVideojuego * videojuego){
    Videojuego * vid = new Videojuego(videojuego);
    vid->setCategorias(cat);
    IKey * k = new String(videojuego->getNombre().c_str());
    IKey * k2 = new String(emailActual.c_str());
    Desarrollador * d = (Desarrollador *)dicUsuario->find(k2);
    vid->setEmpresa(d->getNombreEmpresa());
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

void Sistema::verEstadisticasVideojuego(string nombre){
    string nom = nombre;
    bool existe = true;
    Videojuego * v;
    do{
        IKey * k =new String(nom.c_str());
        if(!dicVideojuego->member(k)){
            existe = false;
            cout << "Este videojuego no existe, ingrese uno correcto" << endl;
            cin >> nom;
        }else{
            existe = true;
            v = (Videojuego *)dicVideojuego->find(k);
        }
        delete(k);
    }while(!existe);

    cout << v->getEstadisticas() << endl;
}

bool Sistema::existeUsuario(string email,string contrasenia){
IKey * k = new String(email.c_str());
Usuario * aux = (Usuario *)dicUsuario->find(k);
if(dicUsuario->member(k) && aux->getContrasenia() == contrasenia){
    emailActual = email;
        return true;
    }else{
        return false;
    }
}

string Sistema::iniciarSesionActual(string email){
    string sesion = email;
    return sesion;
}

void Sistema::cerrarSesion(){
    emailActual = "";    
}

string Sistema::getemailActual(){
    return emailActual;
}

string Sistema::tipoUsuario(string email){
IKey * k = new String(email.c_str());
Usuario * aux = (Usuario *)dicUsuario->find(k);
if(aux->getTipo()=="soyJugador"){
    string res ="jugador";
        return res;
    }else{
        string resu ="nojugador";
        return resu;
    }
}

bool Sistema::existeVideojuego(string nombre){
    IKey * k = new String(nombre.c_str());
    return dicVideojuego->member(k);
}

void Sistema::verInformacionVideojuego(string nombre){
    IKey * k = new String(nombre.c_str());
    Videojuego * v = (Videojuego *)dicVideojuego->find(k);

    cout << "DATOS DE SU VIDEOJUEGO" << endl;
    cout << "Nombre:" << v->getVideojuego()->getNombre() << endl;
    cout << "Descripcion:" << v->getVideojuego()->getDescripcion() << endl;
    cout << "Categorias" << endl;
    IIterator * it;
    for (it= v->getCategorias()->getIterator();it->hasCurrent();it -> next()){
            Categoria * u = (Categoria*)it->getCurrent();
            cout << "-" << u->getNombre() << endl;
    }
    cout << "Suscripciones" << endl;

    for(it = v->getSuscripciones()->getIterator(); it->hasCurrent(); it->next()){
        Suscripcion * s = (Suscripcion *)it->getCurrent();
        cout << "-Nombre:" << s->getNombre() <<" | Precio:" << s->getPrecio() << endl;
    }
    cout << "Empresa:" <<v->getEmpresa() << endl;
    cout << "Valoracion media:" << v->getEstadisticas() << endl;

    IKey * usu = new String(this->getemailActual().c_str());
    Usuario * usuario = (Usuario *)dicUsuario->find(usu);

    if(usuario->getTipo() == "soyDesarrollador")
        cout << "Horas totales jugadas:" << v->getCantHorasJug() << endl;

}

void Sistema::listarVideojuegoCosto(){
    IKey * k =new String(this->getemailActual().c_str());
    Jugador * j =(Jugador *)dicUsuario->find(k);
    IDictionary * jueguitos = new OrderedDictionary();

    cout << "Usted posee suscripciones activas en estos videojuegos" << endl; 
    jueguitos = j->listarVideojuegoConCosto();
    if(jueguitos->isEmpty()){
        cout << "N/A" << endl;
    }

    cout << "Usted no posee suscripciones activas en estos videojuegos" << endl;
    IIterator* it;
    for(it=dicVideojuego->getIterator(); it->hasCurrent(); it->next()){
        Videojuego * v = (Videojuego *)it->getCurrent();
        IKey * k2 = new String(v->getVideojuego()->getNombre().c_str());
        
        if(!jueguitos->member(k2)){
            cout << "Nombre:" << v->getVideojuego()->getNombre() << endl;
            IDictionary * aux = v->getSuscripciones();
            IIterator * it2;
            for(it2 = aux->getIterator(); it2->hasCurrent(); it2->next()){
                Suscripcion * s = (Suscripcion *)it2->getCurrent();

                cout << "Nombre:" << s->getNombre() << " | Precio:" << s->getPrecio() << endl;
            }
        }
    }
}

bool Sistema::seleccionarVideojuegoSuscripcion(string nombre){
    IKey * k =new String(this->getemailActual().c_str());
    Jugador * j =(Jugador *)dicUsuario->find(k);
    j->buscarSuscripcion(nombre);
    return true;    
}

void Sistema::cancelar(string nombre){
    IKey * k =new String(this->getemailActual().c_str());
    Jugador * j =(Jugador *)dicUsuario->find(k);
    j->cancelar(nombre);
}

 void Sistema::confirmarSuscripcion(string tipo, string met, string nombre){
    IKey * k = new String(nombre.c_str());
    Videojuego * v = (Videojuego *)dicVideojuego->find(k);
    IIterator * it;
    for(it = v->getSuscripciones()->getIterator(); it->hasCurrent(); it->next()){
        Suscripcion * s = (Suscripcion *)it->getCurrent();
        if(s->getNombre() == tipo){
            IKey * k =new String(this->getemailActual().c_str());
            Jugador * j =(Jugador *)dicUsuario->find(k);
            j->nuevoSuscripcion(met, s, fecha);
        }
    }

 }

/*
void Sistema::cargarDatosPrueba(){
    //Cargar jugadores
    altaUsuarioJugador("guzmanvera@hotmail.com", "123", "gusbera", "facherazo");
    altaUsuarioJugador("zebautes@hotmail.com", "123", "reyxtar", "ea");
    altaUsuarioJugador("hernancabara@hotmail.com", "123", "kuervou", "el mejor soldado");
    altaUsuarioJugador("cintialeal@hotmail.com", "123", "griffin", "juega re mal");
    
    //Cargar desarrolladores
    altaUsuarioDesarrollador("carlossantana@gmail.com", "123", "amazon");
    altaUsuarioDesarrollador("elpipe@gmail.com", "123", "ubisoft");
    altaUsuarioDesarrollador("desarrollador3@gmail.com", "123", "ea");
    
    //Cargar Categorías
    nuevaCategoria("accion","cat1",1);
    nuevaCategoria("aventura","cat2",1);
    nuevaCategoria("play","cat3",2);
    nuevaCategoria("pc","cat4",2);
    nuevaCategoria("cooperativo","cat5",3);
    nuevaCategoria("logros","cat6",3);

    //cargar suscripciones
    Suscripcion * sus1 = new Suscripcion("Mensual", 1, "Temporal");
    IKey * s1 = new String(sus1->getNombre().c_str());
    Suscripcion * sus2 = new Suscripcion("Trimestral", 2, "Temporal");
    IKey * s2 = new String(sus2->getNombre().c_str());
    Suscripcion * sus3 = new Suscripcion("Anual", 3, "Temporal");
    IKey * s3 = new String(sus3->getNombre().c_str());
    Suscripcion * sus4 = new Suscripcion("Vitalicia", 5, "Vitalicia");
    IKey * s4 = new String(sus4->getNombre().c_str());

    //Cargar videojuegos
    dtVideojuego * v = new dtVideojuego("Albion", "Juegazo",0);
    Videojuego * vid1 = new Videojuego(v);
    vid1->getSuscripciones()->add(s1, sus1);
    vid1->getSuscripciones()->add(s2, sus2);
    vid1->getSuscripciones()->add(s3, sus3);
    vid1->getSuscripciones()->add(s4, sus4);
    
    vid1->getCategorias()->add(k2, c2);
    vid1->getCategorias()->add(k4, c4);

    dtVideojuego * v2 = new dtVideojuego("fifa","El mismo juego todos los años", 0);
    Videojuego * vid2 = new Videojuego(v2);
    vid2->getSuscripciones()->add(s1, sus1);
    vid2->getSuscripciones()->add(s2, sus2);
    vid2->getSuscripciones()->add(s3, sus3);
    vid2->getSuscripciones()->add(s4, sus4);
    vid1->getCategorias()->add(k, c);
    vid1->getCategorias()->add(k3, c3);

    dtVideojuego * v3 = new dtVideojuego("lol","juego horrible", 0);
    Videojuego * vid3 = new Videojuego(v3);
    vid3->getSuscripciones()->add(s1, sus1);
    vid3->getSuscripciones()->add(s2, sus2);
    vid3->getSuscripciones()->add(s3, sus3);
    vid3->getSuscripciones()->add(s4, sus4);
    vid1->getCategorias()->add(k, c);
    vid1->getCategorias()->add(k2, c2);
    vid1->getCategorias()->add(k5, c5);
}
*/
