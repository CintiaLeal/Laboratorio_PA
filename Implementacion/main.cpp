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
