//
// Created by mcmar on 25/4/2026.
//

#ifndef PROYECTO_TECNICOS_H
#define PROYECTO_TECNICOS_H
#include <string>
using namespace std;

class Tecnicos {
    private:
    string nombre;
    bool disponible;

    public:
    Tecnicos(string n);
    // gets
    string getNombre();
    bool getDisponible();

    //liberar y ocupar al tecnico(para que se ocupen el dia entero)
    void ocupar();
    void liberar();
};


#endif //PROYECTO_TECNICOS_H