#include <iostream>
#include "Usuario.cpp"
#include "Partida.cpp"



int main(){

Usuario *u = new Usuario("cintia@gmail.com","1233");
std:cout <<u->getEmail();
return 0;

}