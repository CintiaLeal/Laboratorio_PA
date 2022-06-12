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
menuAdmin();
while (op != 7){
cin>>op;

if(op==1){
  string nombre, descripcion;
  cout <<"INGRESAR INFORMACION PARA UNA NUEVA CATEGORIA"<<endl;
  cout <<"Nombre:"<<endl;
  cin>>nombre;
  cout <<"Descripcion:"<<endl;
  cin>>descripcion;
  sis->nuevaCategoria(nombre,descripcion);
  sis->listarCategoria();
  menuAdmin();
 
}
if(op==2){
  cout <<"LISTA CATEGORIAS"<<endl;
  sis->listarCategoria();
  menuAdmin();
 
}
else{
menuAdmin();
}
}

  return 0;
}