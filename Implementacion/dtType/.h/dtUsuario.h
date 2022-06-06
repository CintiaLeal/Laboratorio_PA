#ifndef Dt_Usuario
#define Dt_Usuario
#include <iostream>

using namespace std;
class dtUsuario{
    private:
        string email;
        string contrasenia;
    public:
        dtUsuario();
        dtUsuario(string, string);
        dtUsuario getEmail();
        float getContrasenia();
        ~dtUsuario();
};
#endif //Dt_Usuario