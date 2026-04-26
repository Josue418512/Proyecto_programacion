//
// Created by mcmar on 25/4/2026.
//

#ifndef PROYECTO_INCIDENCIAS_H
#define PROYECTO_INCIDENCIAS_H
#include <string>
#include <random>
using namespace std;


/*incidencias tienen alto, medio y bajo impacto, afecta el estado
constructor
Destructor
*/
class Incidencias {
    private:
    string Tipo; //tipo de incidencia
    bool Inicio = false; //empieza el timer de random, sin esto explota el proyecto
    int diaIncidencias;
    public:
    //---
    Incidencias(int dia); // constructor
    //---
    string getTipo(); // un get tipo .-.
    int getDiaIncidencias();
    void setDiaIncidencias(int dia);
    //---
    //string diaDeIncidencia(); JOSUE HACER
    //---

};


#endif //PROYECTO_INCIDENCIAS_H