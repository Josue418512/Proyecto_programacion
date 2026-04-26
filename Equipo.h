//
// Created by mcmar on 25/4/2026.
//

#ifndef PROYECTO_EQUIPO_H
#define PROYECTO_EQUIPO_H
#include "Incidencias.h"
using namespace std;
#include <string>
#include <sstream>
#include <iostream>
/*Id  int
Criticidad int
estado (0–100) int
Incidencias[] //Array de punteros
Tiempo_inactivo (ocupa tecnico)
prioridad (calculada)
Severidad clase aparte *class severidad
–
CalcularPrioridad

IncidenciaRandom

 */
class Equipo {
private:
    string id;
    int criticidad;
    int estado = 100; //100  siendo perfecto estado
    Incidencias* incidencias[3];
    int cantidadIncidencias;
    int tiempo_inactivo = 0;
    int prioridad = 0;
    //Clase serveridad falta
public:

    Equipo(string x);

    void agregarIncidencia(Incidencias* inc);

    //-------calculoss
    double calcularCriticidad();
    double calcularPrioridad();
    //-----------gets
    string getId();
    int getPrioridad();
    int getEstado();
    void setEstado(int e);
    void setTiempoInactivo(int tiempo);
    Incidencias* getIncidencias(int num);
    int getCantidadIncidencias();
    //-----limpia de incie
    void limpiarIncidencias();
    // degradar el equipo
    void degradar();
    //--tostring
    string toString() const;

};


#endif //PROYECTO_EQUIPO_H