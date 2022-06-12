#include <iostream>


using namespace std;
void menuPrincipal(){
printf(" ||==========================|| \n");
printf(" ||======MENU PRINCIPAL======|| \n");
printf(" ||========BIENVENIDO========|| \n");
printf(" ||==========================|| \n");
printf(" ||=1-Alta Usuario===========|| \n");
printf(" ||=2-Iniciar Sesion=========|| \n");
printf(" ||=2-Cargar datos prueba====|| \n");
printf(" ||=4-Salir==================|| \n");
printf(" ||==========================|| \n");
}

void menuDesarrollador(){
printf(" ||====================================|| \n");
printf(" ||=========MENU DESARROLLADOR=========|| \n");
printf(" ||====================================|| \n");
printf(" ||=1-Agregar Categoria================|| \n");
printf(" ||=2-Publicar videojuego==============|| \n");
printf(" ||=3-Eliminar videojuego==============|| \n");
printf(" ||=4-Consultar estadisticas===========|| \n");
printf(" ||=5-Ver informacion de videojuego====|| \n");
printf(" ||=6-Modificar fecha del sistema======|| \n");
printf(" ||=7-Listar Categoria=================|| \n");
printf(" ||=8-Salir============================|| \n");
printf(" ||====================================|| \n");
}

void menuJugador(){
printf(" ||====================================|| \n");
printf(" ||============MENU JUGADOR============|| \n");
printf(" ||====================================|| \n");
printf(" ||=1-Suscribirse a videojuego=========|| \n");
printf(" ||=2-Asignar puntaje a videojuego=====|| \n");
printf(" ||=3-Iniciar partida==================|| \n");
printf(" ||=4-Abandonar partida multijugador===|| \n");
printf(" ||=5-Finalizar partida================|| \n");
printf(" ||=6-Ver informacion de videojuego====|| \n");
printf(" ||=7-Modificar fecha del sistema======|| \n");
printf(" ||=8-Listar Categoria=================|| \n");
printf(" ||=9-Salir============================|| \n");
printf(" ||====================================|| \n");
}
void titulo(){
    //https://www.topster.es/texto-ascii/alpha.html
    //https://patorjk.com/software/taag/#p=display&f=Swamp%20Land&t=Type%20Something%20
    std::cout << R"(
  _             _      ___     _   
 | |     __ _  | |__  | _ \   /_\  
 | |__  / _` | | '_ \ |  _/  / _ \ 
 |____| \__,_| |_.__/ |_|   /_/ \_\)" << '\n';


}
void caraArte(){
   std::cout << R"(╲╲╭━━━━━━━╮╱╱ )" << '\n';
    cout <<"╲╭╯╭━╮┈╭━╮╰╮╱"<<endl;
    cout <<"╲┃┈┃┈▊┈┃┈▊┈┃╱"<<endl;
    cout <<"╲┃┈┗━┛┈┗━┛┈┃╱"<<endl;
    cout <<"╱┃┈┏━━━━━┓┈┃╲"<<endl;
    cout <<"╱┃┈┃┈┈╭━╮┃┈┃╲"<<endl;
    cout <<"╱╰╮╰━━┻━┻╯╭╯╲"<<endl;
}
