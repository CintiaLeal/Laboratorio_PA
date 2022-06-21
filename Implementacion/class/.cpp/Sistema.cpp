#include "../../class/.h/Sistema.h"
#include <stdexcept>
#include <limits>
#include <iostream>

using namespace std;

Sistema * Sistema::instancia = 0;
//Datos actual usuario
string emailActual = "";
dtFecha *fecha = new dtFecha(21, 6, 2022, 12, 0);
int idAutoIncremental = 1;

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
    IIterator * it;
    for(it = vid->getSuscripciones()->getIterator(); it->hasCurrent(); it->next()){
        Suscripcion * s = (Suscripcion *)it->getCurrent();
        s->setVid(vid); 
    }
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
    vid->eliminarSuscripcion();
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

Jugador * Sistema::existeUsu(string nick){
    IIterator * it;

    for(it=dicUsuario->getIterator(); it->hasCurrent(); it->next()){
        Jugador * j = (Jugador *)it->getCurrent();
        if(j->getNick() == nick && j->getEmail() == this->getemailActual()){
            return NULL;
        }else if(j->getNick() == nick){
            return j;
        }
    }
    return NULL;
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
    else{
         IIterator * it3;
            for(it3 = jueguitos->getIterator(); it3->hasCurrent(); it3->next()){
                Videojuego * v = (Videojuego *)it3->getCurrent();

                cout << "Nombre:" << v->getVideojuego()->getNombre() << endl; 
            }
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

bool Sistema::listarVideojuegoSuscripcion(){
    IKey * k =new String(this->getemailActual().c_str());
    Jugador * j =(Jugador *)dicUsuario->find(k);
    IIterator * it;

    int cont = 0;

    cout << "Usted posee suscripciones activas en estos videojuegos:" << endl; 
    for(it=j->getPagos()->getIterator(); it->hasCurrent(); it->next()){
        Pago * p = (Pago *)it->getCurrent();
        if(p->getActiva()){
            cout << p->getSuscripcion()->getVideojuego()->getVideojuego()->getNombre() << endl;
            cont ++;
        }
    }
    if (cont == 0){
        cout<<"N/A"<<endl;
        return false;
        } //no hay suscripciones activas a ningun videojuego
    else {return true;}
}

bool Sistema::seleccionarVideojuegoSuscripcion(string nombre){
    IKey * k =new String(this->getemailActual().c_str());
    Jugador * j =(Jugador *)dicUsuario->find(k);
    return j->buscarSuscripcion(nombre);    
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
void Sistema::puntuarVideojuego(string nomVideojuego, int punto){
    IKey * k = new String(nomVideojuego.c_str());
    Videojuego * v = (Videojuego *)dicVideojuego->find(k);
    IKey * kuser =new String(this->getemailActual().c_str());
    Jugador * j =(Jugador *)dicUsuario->find(kuser);
    VJ * newjv = new VJ(punto,j);
    v->getVJ()->add(newjv);
}

void Sistema::listarVideojuegoDescripcion(){
    IIterator * it;
    for(it=this->dicVideojuego->getIterator();it->hasCurrent(); it->next()){
        Videojuego * v = (Videojuego*)it->getCurrent();
        cout << "Nombre:" << v->getVideojuego()->getNombre() <<" Descripcion:"<<v->getVideojuego()->getDescripcion()<< endl;
    }
}

bool Sistema::listarPartidas(string nombre){
    IKey * k = new String(this->getemailActual().c_str());

    Jugador * j = (Jugador *)dicUsuario->find(k);
    return j->listarPartidas(nombre);
}

void Sistema::confirmarPartidaIndCont(string nombre, int pa){
    IKey * k = new String(this->getemailActual().c_str());

    Jugador * j = (Jugador *)dicUsuario->find(k);
    j->createNuevaIndcont(nombre, pa, idAutoIncremental, fecha);
    dtFecha * fechasis = new dtFecha(fecha->getDia(), fecha->getMes(), fecha->getAnio(), fecha->getHora(), fecha->getMinuto());
    j->createNuevaIndcont(nombre, pa, idAutoIncremental, fechasis);
    idAutoIncremental++;
}

void Sistema::confirmarPartidaInd(string nombre){
    IKey * k = new String(this->getemailActual().c_str());

    Jugador * j = (Jugador *)dicUsuario->find(k);
    dtFecha * fechasis = new dtFecha(fecha->getDia(), fecha->getMes(), fecha->getAnio(), fecha->getHora(), fecha->getMinuto());
    j->createNuevaInd(nombre,idAutoIncremental,fechasis);
    idAutoIncremental++;
}   

bool Sistema::listarPartidasActivas(){
    IKey * k = new String(this->getemailActual().c_str());

    Jugador * j = (Jugador *)dicUsuario->find(k);
    return j->listarPartidasActivas();
}

void Sistema::confirmarFinalizarPartida(int id){
    IKey * k = new String(this->getemailActual().c_str());
    Jugador * j = (Jugador *)dicUsuario->find(k);
    dtFecha * fechasis = new dtFecha(fecha->getDia(), fecha->getMes(), fecha->getAnio(), fecha->getHora(), fecha->getMinuto());
    j->finalizarPartida(id,fechasis);
}

bool Sistema::listarJugadoresSuscripciones(string nombre){
    IIterator * it;
    int cont = 0;

    for(it=dicUsuario->getIterator(); it->hasCurrent(); it->next()){
        Usuario * u = (Usuario *)it->getCurrent();
        if (u->getTipo() != "soyDesarrollador"){
            Jugador * j = (Jugador *)u;
            if(j->existeSus(nombre)){
            cout << "Nickname:" << j->getNick() << endl;
            cont++;
        }
        }
        
    }

    if(cont == 0)
        return false;
    else
        return true;
}

void Sistema::CrearPartidaMultijugador(bool vivo, IDictionary * aux, string nombre){
    IKey * k = new String(this->getemailActual().c_str());

    Jugador * j = (Jugador *)dicUsuario->find(k);
    dtFecha * fechasis = new dtFecha(fecha->getDia(), fecha->getMes(), fecha->getAnio(), fecha->getHora(), fecha->getMinuto());

    j->crearMultijugador(idAutoIncremental, fechasis, vivo, nombre, aux);
}

void Sistema::cargarDatosPrueba(){
    altaUsuarioJugador("guzmanvera@hotmail.com", "123", "gusbera", "facherazo");
    altaUsuarioJugador("zebautes@hotmail.com", "123", "reyxtar", "ea");
    altaUsuarioJugador("hernancabara@hotmail.com", "123", "kuervou", "el mejor soldado");
    altaUsuarioJugador("cintialeal@hotmail.com", "123", "griffin", "juega re mal");

    altaUsuarioJugador("gamer@mail.com", "123", "gamer", "a");
    altaUsuarioJugador("ari@mail.com", "123", "ari", "a");
    altaUsuarioJugador("ibai@mail.com", "123", "ibai", "a");
    altaUsuarioJugador("camila@mail.com", "123", "camila", "a");

    //Cargar desarrolladores
    altaUsuarioDesarrollador("ironhide@email.com", "123", "Ironhide Game Studio");
    altaUsuarioDesarrollador("epic@mail.com", "123", "Epic Games");
    altaUsuarioDesarrollador("mojang@mail.com", "123", "Mojang Studios");
    altaUsuarioDesarrollador("ea@mail.com", "123", "EA Sports");

    //Cargar Categorías
    nuevaCategoria("PC","cat3",2);
    nuevaCategoria("PS4","cat4",2);
    nuevaCategoria("Xbox One","cat4",2);
    nuevaCategoria("Deporte","cat1",1);
    nuevaCategoria("Supervivencia","cat2",1);
    nuevaCategoria("Estrategia","cat2",1);
    nuevaCategoria("Teen","Su contenido está dirigido a jóvenes de 13 años en adelante",3);
    nuevaCategoria("E","Su contenido está dirigido para todo público",3);
    nuevaCategoria("Acción","cat2",1);
    nuevaCategoria("Aventura","cat2",1);
    nuevaCategoria("Switch","cat4",2);
    nuevaCategoria("Xbox X","cat4",2);
    nuevaCategoria("PS5","cat4",2);
//===========================================================================================
    //Videojuego 1
    dtVideojuego * v = new dtVideojuego("KingdomRush", "Juego",0);
    Videojuego * vid1 = new Videojuego(v);
    string nombreEmpresa = "Ironhide Game Studio";
    
    
    vid1->agregarSuscripcion(1,2,7,14);
    IIterator * it;
    for(it = vid1->getSuscripciones()->getIterator(); it->hasCurrent(); it->next()){
        Suscripcion * s = (Suscripcion *)it->getCurrent();
        s->setVid(vid1); 
    }
    //Categoria
    IDictionary *auxCat = new OrderedDictionary();
    string c1 = "PC"; string c2 = "PS4"; string c3 = "Xbox One";string c5 = "Supervivencia"; string c6 = "Estrategia";string c7 = "Teen"; string c8 = "E";
    IKey * kc1 = new String(c1.c_str());
    IKey * kc2 = new String(c2.c_str());
    IKey * kc3 = new String(c6.c_str());
    IKey * kc4 = new String(c8.c_str());
    auxCat->add(kc1, this->buscarCat(c1));
    auxCat->add(kc2, this->buscarCat(c2));
    auxCat->add(kc3, this->buscarCat(c6));
    auxCat->add(kc4, this->buscarCat(c8));
    vid1->setCategorias(auxCat);
    
    //nombre Empresa
    vid1->setEmpresa(nombreEmpresa);
   
    //lo agrega a  la coleccion
    IKey * k = new String(v->getNombre().c_str());
    dicVideojuego->add(k,vid1);
    
    //====================================
    //Videojuego 2
    dtVideojuego * v2 = new dtVideojuego("Fortnite", "Juego para niños",0);
    Videojuego * vid2 = new Videojuego(v2);
    string nombreEmpresa2 = "Epic Games";
    //cargar suscripciones
   
    vid2->agregarSuscripcion(3,8,30,60);
    IIterator * it2;
    for(it2 = vid2->getSuscripciones()->getIterator(); it2->hasCurrent(); it2->next()){
        Suscripcion * s2 = (Suscripcion *)it2->getCurrent();
        s2->setVid(vid2); 
    }
    //Categoria
    IDictionary *auxCat2 = new OrderedDictionary();
    string c1f = "PC"; string c2f = "PS4"; string c3f = "Xbox One";string c5f = "Supervivencia"; string c6f = "Estrategia";string c7f = "Teen"; string c8f = "E";
    IKey * kc1f = new String(c1f.c_str());
    IKey * kc2f = new String(c2f.c_str());
    IKey * kc3f = new String(c3f.c_str());
    IKey * kc4f = new String(c5f.c_str());
    IKey * kc5f = new String(c7f.c_str());
    auxCat2->add(kc1f, this->buscarCat(c1f));
    auxCat2->add(kc2f, this->buscarCat(c2f));
    auxCat2->add(kc3f, this->buscarCat(c3f));
    auxCat2->add(kc4f, this->buscarCat(c5f));
    auxCat2->add(kc5f, this->buscarCat(c7f));
    vid2->setCategorias(auxCat2);
    //nombre Empresa
    vid2->setEmpresa(nombreEmpresa2);
   
    //lo agrega a  la coleccion
    IKey * k2 = new String(v2->getNombre().c_str());
    dicVideojuego->add(k2,vid2);

//============================================================
    //Videojuego 3
    dtVideojuego * v3 = new dtVideojuego("Minecraft", "Juego aventura",0);
    Videojuego * vid3 = new Videojuego(v3);
    string nombreEmpresa3 = "Mojang Studios";
    //cargar suscripciones
    vid3->agregarSuscripcion(2,5,20,40);
    IIterator * it3;
    for(it3 = vid3->getSuscripciones()->getIterator(); it3->hasCurrent(); it3->next()){
        Suscripcion * s3 = (Suscripcion *)it3->getCurrent();
        s3->setVid(vid3); 
    }
    //Categoria
    IDictionary *auxCat3 = new OrderedDictionary();
    string c1m = "PC"; string c5m = "Supervivencia"; string c8m = "E";
    IKey * kc1m = new String(c1m.c_str());
    IKey * kc2m = new String(c5m.c_str());
    IKey * kc3m = new String(c8m.c_str());
   
    auxCat3->add(kc1m, this->buscarCat(c1m));
    auxCat3->add(kc2m, this->buscarCat(c5m));
    auxCat3->add(kc3m, this->buscarCat(c8m));

    vid3->setCategorias(auxCat3);
   
  
    //nombre Empresa
    vid3->setEmpresa(nombreEmpresa3);
   
    //lo agrega a  la coleccion
    IKey * k3 = new String(v3->getNombre().c_str());
    dicVideojuego->add(k3,vid3);
//============================================================
   //Videojuego 4
    dtVideojuego * v4 = new dtVideojuego("FIFA22", "Deportes messimessimessi",0);
    Videojuego * vid4 = new Videojuego(v4);
    string nombreEmpresa4 = "EA Sports";
  

    vid4->agregarSuscripcion(3,8,28,50);
    IIterator * it4;
    for(it4 = vid4->getSuscripciones()->getIterator(); it4->hasCurrent(); it4->next()){
        Suscripcion * s4 = (Suscripcion *)it4->getCurrent();
        s4->setVid(vid4); 
    }
   
    //Categoria
    IDictionary *auxCat4 = new OrderedDictionary();
    string c1fi = "PC"; string c2fi = "PS4"; string c3fi = "Xbox One";string c4fi = "Deporte"; string c8fi = "E";
    IKey * kc1fi = new String(c1fi.c_str());
    IKey * kc2fi = new String(c2fi.c_str());
    IKey * kc3fi = new String(c3fi.c_str());
    IKey * kc4fi = new String(c4fi.c_str());
    IKey * kc5fi = new String(c8fi.c_str());
    auxCat4->add(kc1fi, this->buscarCat(c1fi));
    auxCat4->add(kc2fi, this->buscarCat(c2fi));
    auxCat4->add(kc3fi, this->buscarCat(c3fi));
    auxCat4->add(kc4fi, this->buscarCat(c4fi));
    auxCat4->add(kc5fi, this->buscarCat(c8fi));
    vid4->setCategorias(auxCat4);
   
    //nombre Empresa
    vid4->setEmpresa(nombreEmpresa4);
   
    //lo agrega a  la coleccion
    IKey * k4 = new String(v4->getNombre().c_str());
    dicVideojuego->add(k4,vid4);
//===========================================================================================

//Puntaje a videojuego
//valoracion 1
string nomVideojuego = "KingdomRush";
string email = "gamer@mail.com";
int punto = 4;

IKey * kvid = new String(nomVideojuego.c_str());
Videojuego * vide = (Videojuego *)dicVideojuego->find(kvid);
IKey * kuser =new String(email.c_str());
Jugador * j =(Jugador *)dicUsuario->find(kuser);
VJ * newjv = new VJ(punto,j);
vide->getVJ()->add(newjv);

//valoracion 2
string nomVideojuego2 = "Fortnite";
string email2 = "gamer@mail.com";
int punto2 = 5;

IKey * kvid2 = new String(nomVideojuego2.c_str());
Videojuego * vide2 = (Videojuego *)dicVideojuego->find(kvid2);
IKey * kuser2 =new String(email2.c_str());
Jugador * j2 =(Jugador *)dicUsuario->find(kuser2);
VJ * newjv2 = new VJ(punto2,j2);
vide2->getVJ()->add(newjv2);

//valoracion 3
string nomVideojuego3 = "Fortnite";
string email3 = "ari@mail.com";
int punto3 = 5;

IKey * kvid3 = new String(nomVideojuego3.c_str());
Videojuego * vide3 = (Videojuego *)dicVideojuego->find(kvid3);
IKey * kuser3 =new String(email3.c_str());
Jugador * j3 =(Jugador *)dicUsuario->find(kuser3);
VJ * newjv3 = new VJ(punto3,j3);
vide3->getVJ()->add(newjv3);

//valoracion 4
string nomVideojuego4 = "Minecraft";
string email4 = "ari@mail.com";
int punto4 = 3;

IKey * kvid4 = new String(nomVideojuego4.c_str());
Videojuego * vide4 = (Videojuego *)dicVideojuego->find(kvid4);
IKey * kuser4 =new String(email4.c_str());
Jugador * j4 =(Jugador *)dicUsuario->find(kuser4);
VJ * newjv4 = new VJ(punto4,j4);
vide4->getVJ()->add(newjv4);
//================================================================================================================
//Suscripcion 1
  string emails = "gamer@mail.com";
    string nombres = "KingdomRush";
    string tipos = "Trimestral";
    string mets = "Paypal";
    dtFecha *fechas = new dtFecha(1, 6, 2022, 9, 0);

    IKey * ke = new String(nombres.c_str());
    Videojuego * video = (Videojuego *)dicVideojuego->find(ke);
    IIterator * itt;
    for(itt = video->getSuscripciones()->getIterator(); itt->hasCurrent(); itt->next()){
        Suscripcion * sus = (Suscripcion *)itt->getCurrent();
        if(sus->getNombre() == tipos){
            IKey * km =new String(emails.c_str());
            Jugador * jug =(Jugador *)dicUsuario->find(km);
            jug->nuevoSuscripcion(mets, sus, fechas);
        }
    }
//Suscripcion 2
  string emails2 = "gamer@mail.com";
    string nombres2 = "Fortnite";
    string tipos2 = "Trimestral";
    string mets2 = "Tarjeta";
    dtFecha *fechas2 = new dtFecha(2, 6, 2022, 11, 0);

    IKey * ke2 = new String(nombres2.c_str());
    Videojuego * video2 = (Videojuego *)dicVideojuego->find(ke2);
    IIterator * itt2;
    for(itt2 = video2->getSuscripciones()->getIterator(); itt2->hasCurrent(); itt2->next()){
        Suscripcion * sus2 = (Suscripcion *)itt2->getCurrent();
        if(sus2->getNombre() == tipos2){
            IKey * km2 =new String(emails2.c_str());
            Jugador * jug2 =(Jugador *)dicUsuario->find(km2);
            jug2->nuevoSuscripcion(mets2, sus2, fechas2);
        }
    }
//Suscripcion 3
    string emails3 = "ari@mail.com";
    string nombres3 = "Fortnite";
    string tipos3 = "Trimestral";
    string mets3 = "Paypal";
    dtFecha *fechas3 = new dtFecha(4, 6, 2022, 9, 0);

    IKey * ke3 = new String(nombres3.c_str());
    Videojuego * video3 = (Videojuego *)dicVideojuego->find(ke3);
    IIterator * itt3;
    for(itt3 = video3->getSuscripciones()->getIterator(); itt3->hasCurrent(); itt3->next()){
        Suscripcion * sus3 = (Suscripcion *)itt3->getCurrent();
        if(sus3->getNombre() == tipos3){
            IKey * km3 =new String(emails3.c_str());
            Jugador * jug3 =(Jugador *)dicUsuario->find(km3);
            jug3->nuevoSuscripcion(mets3, sus3, fechas3);
        }
    }
//Suscripcion 4
    string emails4 = "ari@mail.com";
    string nombres4 = "Minecraft";
    string tipos4 = "Anual";
    string mets4 = "Tarjeta";
    dtFecha *fechas4 = new dtFecha(11, 6, 2022, 9, 0);

    IKey * ke4 = new String(nombres4.c_str());
    Videojuego * video4 = (Videojuego *)dicVideojuego->find(ke4);
    IIterator * itt4;
    for(itt4 = video4->getSuscripciones()->getIterator(); itt4->hasCurrent(); itt4->next()){
        Suscripcion * sus4 = (Suscripcion *)itt4->getCurrent();
        if(sus4->getNombre() == tipos4){
            IKey * km4 =new String(emails4.c_str());
            Jugador * jug4 =(Jugador *)dicUsuario->find(km4);
            jug4->nuevoSuscripcion(mets4, sus4, fechas4);
        }
    }

//Suscripcion 5
    string emails5 = "ibai@mail.com";
    string nombres5 = "Fortnite";
    string tipos5 = "Mensual";
    string mets5 = "Tarjeta";
    dtFecha *fechas5 = new dtFecha(3, 6, 2022, 7, 0);

    IKey * ke5 = new String(nombres5.c_str());
    Videojuego * video5 = (Videojuego *)dicVideojuego->find(ke5);
    IIterator * itt5;
    for(itt5 = video5->getSuscripciones()->getIterator(); itt5->hasCurrent(); itt5->next()){
        Suscripcion * sus5 = (Suscripcion *)itt5->getCurrent();
        if(sus5->getNombre() == tipos5){
            IKey * km5 =new String(emails5.c_str());
            Jugador * jug5 =(Jugador *)dicUsuario->find(km5);
            jug5->nuevoSuscripcion(mets5, sus5, fechas5);
        }
    }
//Suscripcion 6
    string emails6 = "ibai@mail.com";
    string nombres6 = "Minecraft";
    string tipos6 = "Vitalicia";
    string mets6 = "Tarjeta";
    dtFecha *fechas6 = new dtFecha(22, 12, 2022, 3, 0);

    IKey * ke6 = new String(nombres6.c_str());
    Videojuego * video6 = (Videojuego *)dicVideojuego->find(ke6);
    IIterator * itt6;
    for(itt6 = video6->getSuscripciones()->getIterator(); itt6->hasCurrent(); itt6->next()){
        Suscripcion * sus6 = (Suscripcion *)itt6->getCurrent();
        if(sus6->getNombre() == tipos6){
            IKey * km6 =new String(emails6.c_str());
            Jugador * jug6 =(Jugador *)dicUsuario->find(km6);
            jug6->nuevoSuscripcion(mets6, sus6, fechas6);
        }
    }
    
}

