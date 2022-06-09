#include <iostream>
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
#include "ICollection\String.cpp"

int main(){
Usuario *u = new Usuario("cintia@gmail.com","1233");
std:cout <<u->getEmail();
return 0;

}