/*#include <iostream>
#include "class\.cpp\Usuario.cpp"
#include "class\.cpp\Partida.cpp"
#include "class\.cpp\Videojuego.cpp"
#include "class\.cpp\Pago.cpp"
#include "ICollection\collections\List.cpp"
#include "ICollection\collections\ListIterator.cpp"
#include "ICollection\collections\ListNode.cpp"
#include "ICollection\collections\OrderedDictionary.cpp"
#include "ICollection\collections\OrderedDictionaryEntry.cpp"
#include "ICollection\interfaces\ICollectible.cpp"
#include "ICollection\interfaces\ICollection.cpp"
#include "ICollection\interfaces\IDictionary.cpp"
#include "ICollection\interfaces\IIterator.cpp"
#include "ICollection\interfaces\IKey.cpp"
#include "ICollection\interfaces\OrderedKey.cpp"
#include "ICollection\Integer.cpp"
#include "ICollection\String.cpp"*/

#include <iostream>
#include "class/.cpp/Fabrica.cpp"
#include "class/.cpp/Sistema.cpp"
#include "class/.cpp/ISistema.cpp"

#include "consola.cpp"
using namespace std;
int op;
ISistema * sis = Fabrica::crearSistema();
int main(){
op=0;
/*
do{
  system("cls");
  titulo();
  menuPrincipal();
  cin >> op;
  if(op == 1){
    system("cls");
    string descripcion, nombreEmpresa, email, nick, contrasenia;
    int si;
    cout << "Ingrese su email" << endl;
    cin >> email;
    
    cout << "Ingrse su contrasenia" << endl;
    cin >> contrasenia;

    cout << "Es usted un Jugador? 1-Si || 2-No" << endl;
    cin >> si;

    if(si == 1){
      cout << "Ingrese su nick" << endl;
      cin >> nick;

      cout << "Ingrese su descripcion" << endl;
      cin >> descripcion;
      
      sis->altaUsuarioJugador(email, contrasenia, nick, descripcion);
    }else{
      cout << "Ingrese el Nombre de Empresa" << endl;
      cin >> nombreEmpresa;

      sis->altaUsuarioDesarrollador(email, contrasenia, nombreEmpresa);
    }
    
  }else if(op == 2){

  }
}while(op != 4);*/

menuDesarrollador();
while (op != 8){
cin>>op;
if(op==1){
 string nombre, descripcion;
  int tipo;
  cout <<"INGRESAR INFORMACION PARA UNA NUEVA CATEGORIA"<<endl;
  cout <<"Nombre:"<<endl;
  cin>>nombre;
  cout <<"Descripcion:"<<endl;
  cin>>descripcion;
  cout <<"Tipo:"<<endl;
  cout <<"1-Plataforma"<<endl;
  cout <<"2-Genero"<<endl;
  cout <<"3-Otra"<<endl;
  cin>>tipo;
  sis->nuevaCategoria(nombre,descripcion,tipo);
  sis->listarCategoria();
  menuDesarrollador();
 
}
if(op == 2){
  string nombre, descripcion;
  cout << "Ingrese el nombre del Videojuego" << endl;
  cin >> nombre;

  cout << "Ingrse la descripcion del Videojuego" << endl;
  cin >> descripcion;

  dtVideojuego * datosVideojuego = sis->altaVideojuego(nombre, descripcion);

  sis->listarCategoria();

  cout << "Seleccione las categorías de su videojuego" << endl;
  cout << "Debe incluir al menos una categoría de tipo Plataforma y Genero" << endl;
  cout << "Ingrese 0 para salir" << endl;
  IDictionary * aux = new OrderedDictionary();
  string opcion;
  int gen = 0;
  int plat = 0;
  do{
    do{
      cin >> opcion;
      IKey * k = new String(opcion.c_str());
      if(sis->existeCategoria(opcion) && !aux->member(k)){
        aux->add(k,sis->buscarCat(opcion));
      }else{
        cout << "Ingrese una categoría valida" << endl;
      }
    }while(opcion != "0");

    IIterator * it;
    for(it = aux->getIterator(); it->hasCurrent(); it->next()){
      Categoria * u = (Categoria*)it->getCurrent();
      if(u->getTipog() == "Plataforma")
        plat++;
      else if(u->getTipog() == "Genero")
        gen++;
    }
  system("cls");
  }while(gen == 0 || plat == 0);

  int sus;
  //Suscripcion Mensual
  cout << "Ingrese el costo de la suscripcion MENSUAL en dolares" << endl;
  cin >> sus;
  Suscripcion * mensual = new Suscripcion("Mensual", sus, "Temporal");
  //Suscripcion Trimestral
  cout << "Ingrese el costo de la suscripcion TRIMESTRAL en dolares" << endl;
  cin >> sus;
  Suscripcion * trimestral = new Suscripcion("Trimestral", sus, "Temporal");
  //Suscripcion Anual
  cout << "Ingrese el costo de la suscripcion Anual en dolares" << endl;
  cin >> sus;
  Suscripcion * anual = new Suscripcion("Anual", sus, "Temporal");
    //Suscripcion Vitalicia
  cout << "Ingrese el costo de la suscripcion Vitalicia en dolares" << endl;
  cin >> sus;
  Suscripcion * vitalicia = new Suscripcion("Vitalicia", sus, "Vitalicia");

  system("cls");
  cout << "DATOS DE SU VIDEOJUEGO" << endl;
  cout << "Nombre:" << nombre << endl;
  cout << "Descripcion:" << descripcion << endl;
  cout << "Categorias" << endl;
  IIterator * it;
	for (it= aux->getIterator();it->hasCurrent();it -> next()){
        Categoria * u = (Categoria*)it->getCurrent();
        cout << "-" << u->getNombre() << endl;
	}
  cout << "Suscripciones" << endl;
  cout << "-Nombre:" << mensual->getNombre() << " Precio:" << mensual->getPrecio() << endl;
  cout << "-Nombre:" << trimestral->getNombre() << " Precio:" << trimestral->getPrecio() << endl;  
  cout << "-Nombre:" << anual->getNombre() << " Precio:" << anual->getPrecio() << endl;  
  cout << "-Nombre:" << vitalicia->getNombre() << " Precio:" << vitalicia->getPrecio() << endl;

  cout << "Desea confirmar? 1-si || 2-no" << endl;
  int confirmar;
  cin >> confirmar;
  IDictionary * aux2 = new OrderedDictionary();
  if(confirmar == 1){
    IKey * kmensual = new String(mensual->getNombre().c_str());
    IKey * ktrimestral = new String(trimestral->getNombre().c_str());
    IKey * kanual = new String(anual->getNombre().c_str());
    IKey * kvitalicia = new String(vitalicia->getNombre().c_str());
    aux2->add(kmensual, mensual);
    aux2->add(ktrimestral, trimestral);
    aux2->add(kanual, anual);
    aux2->add(kvitalicia, vitalicia);
    sis->confirmarPublicarVideojuego(aux, aux2, datosVideojuego);
  }else{
    delete(datosVideojuego);
    delete(aux);
    delete(aux2);
  }
}
if(op==7){
  cout <<"LISTA CATEGORIAS"<<endl;
  sis->listarCategoria();
  menuDesarrollador();
 
}
else{
menuDesarrollador();
}
}

  return 0;
}
