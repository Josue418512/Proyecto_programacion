//
// Created by Dell on 25/4/2026.
//

#ifndef PROYECTO_SISTEMACENTRAL_H
#define PROYECTO_SISTEMACENTRAL_H
#include <vector>
#include "Equipo.h"
#include "Dia.h"
#include "Tecnicos.h"

using namespace std;

class SistemaCentral {
private:
    Equipo* equipos[100];
    int cantidadEquipos;
    Tecnicos* tecnicos[3];
    int cantidadTecnicos;
    Dia* dias[30];
    int totalDias;

    void procesarDia(int numDia);
    void ordenarEquipos(); // algoritmo
public:
    SistemaCentral();
    ~SistemaCentral();

    bool agregarEquipo(Equipo* e);
    bool agregarTecnicos(Tecnicos* t);

    void mostrarHistorial();

    void simular(int dias);

};


#endif //PROYECTO_SISTEMACENTRAL_H