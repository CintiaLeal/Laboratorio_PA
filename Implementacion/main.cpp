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
int main(){

int op;
ISistema * sis = Fabrica::crearSistema();
  //sis->hola();
 // int holas = sis->hola();
  //cout <<sis->hola();
menuAdmin();
cin>>op;
if(op==1){
  string nombre, descripcion;
  cout <<"nombre"<<endl;
  cin>>nombre;
  cout <<"descripcion"<<endl;
  cin>>descripcion;
  sis->nuevaCategoria(nombre,descripcion);
  menuAdmin();
   cout <<"nombre"<<endl;
  cin>>nombre;
  cout <<"descripcion"<<endl;
  cin>>descripcion;
  sis->nuevaCategoria(nombre,descripcion);
}
else{
cout <<"descripcion"<<endl;
menuAdmin();
}
  sis->altaUsuarioDesarrollador("sd","sd","fg");
  return 0;


}