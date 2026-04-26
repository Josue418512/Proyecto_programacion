//
// Created by mcmar on 25/4/2026.
//

#include "Incidencias.h"

#include <iostream>


Incidencias::Incidencias(int dia) {
    static random_device rd; //inicia random
    static mt19937 gen(rd()); //planta "semilla"
    static uniform_int_distribution<> dist(0, 2); // rango de 0 a 2
    int random = dist(gen);
    switch (random) {  //casos de impacto
        case 0: Tipo = "Bajo Impacto"; break;
        case 1: Tipo = "Medio Impacto"; break;
        case 2: Tipo = "Alto Impacto"; break;
    }
    diaIncidencias = dia;
}
string Incidencias::getTipo() {
    return Tipo;
}

int Incidencias::getDiaIncidencias(){
    return diaIncidencias;
}
void Incidencias::setDiaIncidencias(int dia){
    diaIncidencias = dia;
}