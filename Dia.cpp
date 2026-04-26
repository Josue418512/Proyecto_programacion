#include "Dia.h"
#include <fstream>
#include <iostream>

using namespace std;

Dia::Dia(int numDia) {
    this->numDia = numDia;
    riesgoGlobal = 0;
    totalIncidenciasActivas = 0;
    promedioEstado = 0;
}

int Dia::getNumDia() const {
    return numDia;
}

void Dia::registrarPrioridad(Equipo* equipo, double prioridad) {
    prioridades.push_back(make_pair(equipo, prioridad));
}

void Dia::agregarTop(Equipo* equipo) {
    top3.push_back(equipo);
}

void Dia::agregarAtendido(Equipo* equipo) {
    atendidos.push_back(equipo);
}

void Dia::agregarPendiente(Equipo* equipo) {
    pendientes.push_back(equipo);
}

void Dia::setRiesgoGlobal(double riesgo) {
    riesgoGlobal = riesgo;
}

void Dia::setTotalIncidencias(int total) {
    totalIncidenciasActivas = total;
}

void Dia::setPromedioEstado(double promedio) {
    promedioEstado = promedio;
}

string Dia::toString(){
    stringstream ss;

    ss << "========================\n";
    ss << "Dia " << numDia << "\n";
    ss << "========================\n\n";

    ss << "Prioridades:\n";
    for (int i = 0; i < prioridades.size(); i++) {
        ss << prioridades[i].first->getId()
           << " -> " << prioridades[i].second << "\n";
    }

    ss << "\nTop 3:\n";
    for (int i = 0; i < top3.size(); i++) {
        ss << top3[i]->getId() << "\n";
    }

    ss << "\nAtendidos:\n";
    for (int i = 0; i < atendidos.size(); i++) {
        ss << atendidos[i]->getId() << "\n";
    }

    ss << "\nPendientes:\n";
    for (int i = 0; i < pendientes.size(); i++) {
        ss << pendientes[i]->getId() << "\n";
    }

    ss << "Total pendientes: " << pendientes.size() << "\n";

    ss << "\nRiesgo global: " << riesgoGlobal << "\n";
    ss << "Total incidencias activas: " << totalIncidenciasActivas << "\n";
    ss << "Promedio estado: " << promedioEstado << "\n";

    ss << "\n------------------------\n";

    return ss.str();
}


void Dia::generarReporte(const string& nombreArchivo) const {
    ofstream archivo(nombreArchivo, ios::app);

    if (!archivo) {
        cout << "Error al abrir archivo" << endl;
        return;
    }

    archivo << "========================\n";
    archivo << "Dia " << numDia << "\n";
    archivo << "========================\n\n";

    archivo << "Prioridades:\n";
    for (int i = 0; i < prioridades.size(); i++) {
        archivo << prioridades[i].first->getId()
                << " -> " << prioridades[i].second << "\n";
    }

    archivo << "\nTop 3:\n";
    for (int i = 0; i < top3.size(); i++){
        archivo << top3[i]->getId() <<"\n";
    }

    archivo << "\nAtendidos:\n";
    for (int i = 0; i < atendidos.size(); i++) {
        archivo << atendidos[i]->getId() << "\n";
    }

    archivo << "\nPendientes:\n";
    for (int i = 0; i < pendientes.size(); i++) {
        archivo << pendientes[i]->getId() << "\n";
    }

    archivo << "Total pendientes: " << pendientes.size() << "\n";

    archivo << "\nRiesgo global: " << riesgoGlobal << "\n";
    archivo << "Total incidencias activas: " << totalIncidenciasActivas << "\n";
    archivo << "Promedio estado: " << promedioEstado << "\n";

    archivo << "\n------------------------\n\n";

    archivo.close();
}