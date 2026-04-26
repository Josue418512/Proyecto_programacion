#ifndef PROYECTO_PROGRAMACION_DIA_H
#define PROYECTO_PROGRAMACION_DIA_
#include <string>
#include <sstream>
#include "Equipo.h"

using namespace std;
class Dia {
private:
    int numDia;

    vector<pair<Equipo*, double>> prioridades;

    vector<Equipo*> top3;
    vector<Equipo*> atendidos;
    vector<Equipo*> pendientes;

    double riesgoGlobal;
    int totalIncidenciasActivas;
    double promedioEstado;

public:
    Dia(int numDia);

    int getNumDia() const;

    void registrarPrioridad(Equipo* equipo, double prioridad);

    void agregarTop(Equipo* equipo);
    void agregarAtendido(Equipo* equipo);
    void agregarPendiente(Equipo* equipo);

    void setRiesgoGlobal(double riesgo);
    void setTotalIncidencias(int total);
    void setPromedioEstado(double promedio);

    string toString();

    void generarReporte(const string& nombreArchivo) const;
};

#endif //PROYECTO_PROGRAMACION_DIA_H