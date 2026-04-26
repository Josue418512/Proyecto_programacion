//
// Created by mcmar on 25/4/2026.
//

#include "Equipo.h"



Equipo::Equipo(string x) {
    id = x;
    criticidad = 0;
    cantidadIncidencias = 0;
}

void Equipo::agregarIncidencia(Incidencias* inc) {
    if (cantidadIncidencias < 3) {
        incidencias[cantidadIncidencias] = inc;
        cantidadIncidencias++;

    } else {
        cout << "No se pueden agregar más incidencias\n";
    }
}


double Equipo::calcularCriticidad() {
    double total = 0;

    for (int i = 0; i < cantidadIncidencias; i++) {
        if (incidencias[i] != nullptr) {
            string tipo = incidencias[i]->getTipo();

            if (tipo == "Bajo Impacto") {
                total += 10;
            }
            else if (tipo == "Medio Impacto") {
                total += 20;
            }
            else if (tipo == "Alto Impacto") {
                total += 30;
            }
        }
    }

    criticidad = total; // opcional, si quieres guardar
    return total;
}
double Equipo::calcularPrioridad() {
    double crit = calcularCriticidad();

    prioridad = crit * 0.5
              + cantidadIncidencias * 0.3
              + tiempo_inactivo * 0.2;

    return prioridad;
}

string Equipo::getId() {
    return id;
}
int Equipo::getPrioridad() {
    return prioridad;
}

int Equipo::getEstado(){
    return estado;
}

void Equipo::setEstado(int e){
    estado = e;
}

void Equipo::setTiempoInactivo(int tiempo){
    tiempo_inactivo = tiempo;
}

Incidencias* Equipo::getIncidencias(int num){
    return incidencias[num];
}

int Equipo::getCantidadIncidencias() {
    return cantidadIncidencias;
}
void Equipo::limpiarIncidencias() {
    for (int i = 0; i < cantidadIncidencias; i++) {
        delete incidencias[i];
        incidencias[i] = nullptr;
    }
    cantidadIncidencias = 0;
}

void Equipo::degradar() {
    int desgaste = 2 + cantidadIncidencias;
    estado -= desgaste;

    if (estado < 0) estado = 0;

    tiempo_inactivo++;
}

string Equipo::toString() const {
    stringstream s;

    s << "Equipo ID: " << id << "\n";
    s << "Criticidad: " << criticidad << "\n";
    s << "Estado: " << estado << "\n";
    s << "Tiempo inactivo: " << tiempo_inactivo << "\n";
    s << "Prioridad: " << prioridad << "\n";
    s << "cantidadIncidencias = " << cantidadIncidencias << endl;
    s << "Incidencias:\n";

    for (int i = 0; i < cantidadIncidencias; i++) {
        s << "- " << incidencias[i]->getTipo() << "\n";
    }

    return s.str();
}
