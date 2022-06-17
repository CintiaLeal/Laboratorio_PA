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
int opcionMenuDesarrollador;
ISistema *sis = Fabrica::crearSistema();


int main()
{
  op = 0;
  sis->altaUsuarioDesarrollador("pipe", "123", "ubisoft");
  sis->nuevaCategoria("accion", "cat1", 1);
  sis->nuevaCategoria("play", "cat2", 2);
  do
  {
    system("cls");
    titulo();
    menuPrincipal();
    cin >> op;
    if (op == 1)
    {
      system("cls");
      string descripcion, nombreEmpresa, email, nick, contrasenia;
      int si;
      cout << "Ingrese su email" << endl;
      cin >> email;

      cout << "Ingrse su contrasenia" << endl;
      cin >> contrasenia;

      cout << "Es usted un Jugador? 1-Si || 2-No" << endl;
      cin >> si;

      if (si == 1)
      {
        cout << "Ingrese su nick" << endl;
        cin >> nick;

        cout << "Ingrese su descripcion" << endl;
        cin >> descripcion;

        sis->altaUsuarioJugador(email, contrasenia, nick, descripcion);
      }
      else
      {
        cout << "Ingrese el Nombre de Empresa" << endl;
        cin >> nombreEmpresa;

        sis->altaUsuarioDesarrollador(email, contrasenia, nombreEmpresa);
      }
    }
    else if (op == 2)
    {
      string email, contrasenia;
      cout << "Ingrese su emaill" << endl;
      cin >> email;
      cout << "Ingrese su contrasenia" << endl;
      cin >> contrasenia;
      bool b = sis->existeUsuario(email, contrasenia);
      if (b != false)
      {
        string tipoUsuario = sis->tipoUsuario(email);
        if (tipoUsuario == "jugador")
        {
          int opcionMenuJugador;
          do{
            menuJugador();
            cin >> opcionMenuJugador;
            if(opcionMenuJugador == 1){
              string nombre;
              sis->listarVideojuegoCosto();
              cout << "Ingrese el videojuego al que se desea suscribir" << endl;
              do{
                  cin >> nombre;
              }while(!sis->existeVideojuego(nombre));
              if(sis->seleccionarVideojuegoSuscripcion(nombre)){
                cout<< "Ingrese el tipo de suscripcion que desea contratar" << endl;
                string tipo;
                cin >> tipo;
                cout<< "Ingrese el metodo de pago que desea utilizar" << endl;
                string met;
                cin >> met;
                cout<<"Desea confirmar su nueva suscripcion? 1-Si || 2-No"<<endl;
                    int op;
                    do{
                      cin >> op;
                      if(op != 1 && op != 2){
                        cout<<"Ingrese una opcion correcta"<<endl;
                      }
                    }while(op != 1 && op != 2);
                    if(op == 2){
                      sis->cancelar(nombre);
                    }
                    if(op == 1){
                      sis->confirmarSuscripcion(tipo, met,nombre);
                    }
              }
              
            }
          }while(opcionMenuJugador != 8);
        }
        else
        {
          menuDesarrollador();

          do
          {
            cin >> opcionMenuDesarrollador;
            if (opcionMenuDesarrollador == 1)
            {
              string nombre, descripcion;
              int tipo;
              cout << "INGRESAR INFORMACION PARA UNA NUEVA CATEGORIA" << endl;
              cout << "Nombre:" << endl;
              cin >> nombre;
              cout << "Descripcion:" << endl;
              cin >> descripcion;
              cout << "Tipo:" << endl;
              cout << "1-Plataforma" << endl;
              cout << "2-Genero" << endl;
              cout << "3-Otra" << endl;
              cin >> tipo;
              sis->nuevaCategoria(nombre, descripcion, tipo);
              sis->listarCategoria();
              // menuDesarrollador();
            }
            if (opcionMenuDesarrollador == 2)
            {
              string nombre, descripcion;
              cout << "Ingrese el nombre del Videojuego" << endl;
              cin >> nombre;

              cout << "Ingrse la descripcion del Videojuego" << endl;
              cin >> descripcion;

              dtVideojuego *datosVideojuego = sis->altaVideojuego(nombre, descripcion);

              sis->listarCategoria();

              cout << "Seleccione las categorías de su videojuego" << endl;
              cout << "Debe incluir al menos una categoría de tipo Plataforma y Genero" << endl;
              cout << "Ingrese 0 para salir" << endl;
              IDictionary *aux = new OrderedDictionary();
              string opcion;
              int gen = 0;
              int plat = 0;
              do
              {
                do
                {
                  cin >> opcion;
                  IKey *k = new String(opcion.c_str());
                  if (sis->existeCategoria(opcion) && !aux->member(k))
                  {
                    aux->add(k, sis->buscarCat(opcion));
                  }
                  else
                  {
                    cout << "Ingrese una categoría valida" << endl;
                  }
                } while (opcion != "0");

                IIterator *it;
                for (it = aux->getIterator(); it->hasCurrent(); it->next())
                {
                  Categoria *u = (Categoria *)it->getCurrent();
                  if (u->getTipog() == "Plataforma")
                    plat++;
                  else if (u->getTipog() == "Genero")
                    gen++;
                }
                system("cls");
              } while (gen == 0 || plat == 0);

              int sus1, sus2, sus3, sus4;
              // Suscripcion Mensual
              cout << "Ingrese el costo de la suscripcion MENSUAL en dolares" << endl;
              cin >> sus1;
              // Suscripcion Trimestral
              cout << "Ingrese el costo de la suscripcion TRIMESTRAL en dolares" << endl;
              cin >> sus2;
              // Suscripcion Anual
              cout << "Ingrese el costo de la suscripcion ANUAL en dolares" << endl;
              cin >> sus3;
              // Suscripcion Vitalicia
              cout << "Ingrese el costo de la suscripcion Vitalicia en dolares" << endl;
              cin >> sus4;

              system("cls");
              cout << "DATOS DE SU VIDEOJUEGO" << endl;
              cout << "Nombre:" << datosVideojuego->getNombre() << endl;
              cout << "Descripcion:" << descripcion << endl;
              cout << "Categorias" << endl;
              IIterator *it;
              for (it = aux->getIterator(); it->hasCurrent(); it->next())
              {
                Categoria *u = (Categoria *)it->getCurrent();
                cout << "-" << u->getNombre() << endl;
              }
              cout << "Suscripciones" << endl;
              cout << "-Nombre:Mensual | Precio:" << sus1 << endl;
              cout << "-Nombre:Trimestral | Precio:" << sus2 << endl;
              cout << "-Nombre:Anual | Precio:" << sus3 << endl;
              cout << "-Nombre:Vitalicia | Precio:" << sus4 << endl;

              cout << "Desea confirmar? 1-si || 2-no" << endl;
              int confirmar;
              cin >> confirmar;
              if (confirmar == 1)
              {

                sis->confirmarPublicarVideojuego(aux, datosVideojuego);
                sis->agregarSuscripciones(datosVideojuego->getNombre(), sus1, sus2, sus3, sus4);
              }
              else
              {
                delete (datosVideojuego);
                delete (aux);
              }
            }
            if (opcionMenuDesarrollador == 3)
            {
              string nombre;
              sis->listarVideojuego();
              cout << "Ingrese el videojuego que desea eliminar" << endl;
              cin >> nombre;

              sis->confirmarEliminarVideojuego(nombre);
            }
            if (opcionMenuDesarrollador == 4)
            {
              string nombre;
              sis->listarVideojuego();
              cout << "Ingrese el videojuego que desea ver las estadisticas" << endl;
              cin >> nombre;
              sis->verEstadisticasVideojuego(nombre);
            }
            if (opcionMenuDesarrollador == 5)
            {
              string nombre;
              bool existe = false;
              sis->listarVideojuego();
              do
              {
                cout << "Ingrese el nombre del videojuego que desea ver" << endl;
                cin >> nombre;
                if (!sis->existeVideojuego(nombre))
                {
                  cout << "Debe ingresar un videojuego que exista" << endl;
                  cin >> nombre;
                }
                else
                {
                  existe = true;
                }
              } while (!existe);

              sis->verInformacionVideojuego(nombre);
            }
            if (opcionMenuDesarrollador == 6)
            {
              int dia, mes, anio, hora, minuto;

              do
              {
                cout << "DIA:" << endl;
                cin >> dia;
              } while ((dia < 0) || (dia > 32));
              do
              {
                cout << "MES:" << endl;
                cin >> mes;
              } while ((mes < 0) || (mes > 13));
              do
              {
                cout << "ANIO" << endl;
                cin >> anio;
              } while ((anio < 1900) || (anio > 2030));
              do
              {
                cout << "HORA" << endl;
                cin >> hora;
              } while ((hora < 0) || (hora > 25));
              do
              {
                cout << "MINUTO" << endl;
                cin >> minuto;
              } while ((minuto < 0) || (minuto > 61));

              fecha->setFechaActual(dia, mes, anio, hora, minuto);
            }
          if (opcionMenuDesarrollador == 7)
          {
            cout << "LISTA CATEGORIAS" << endl;
            sis->listarCategoria();
            menuDesarrollador();
          }
          if(opcionMenuDesarrollador == 8){
            sis->cerrarSesion();
          }
          else
          {
            menuDesarrollador();
          }
        }
        while (opcionMenuDesarrollador != 8)
          ;
      }
    }
  }
  else if (op == 3)
  {
    // sis->cargarDatosPrueba();
  }
}
while (op != 4)
  ;
}
