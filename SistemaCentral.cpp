//
// Created by Dell on 25/4/2026.
//

#include "SistemaCentral.h"
#include <iostream>

#include "Mantenimiento.h"
using namespace std;

SistemaCentral::SistemaCentral() {
    cantidadEquipos = 0;
    cantidadTecnicos = 0;
    totalDias = 0;

    for (int i = 0; i < 100; i++) {
        equipos[i] = nullptr;
    }
    for (int i=0; i < 3; i++){
        tecnicos[i] = nullptr;
    }
    for (int i=0; i < 30; i++){
        dias[i] = nullptr;
    }
}

SistemaCentral::~SistemaCentral() {
    for (int i = 0; i < cantidadEquipos; i++) {
        delete equipos[i];
    }
    for (int i = 0; i < cantidadTecnicos; i++) {
        delete tecnicos[i];
    }
    for (int i = 0; i < totalDias; i++) {
        delete dias[i];
    }
}

// Agregar equipo y tecnicos
bool SistemaCentral::agregarEquipo(Equipo* e) {
    if (cantidadEquipos >= 100) return false;

    equipos[cantidadEquipos] = e;
    cantidadEquipos++;

    return true;
}
bool SistemaCentral::agregarTecnicos(Tecnicos* t) {
    if (cantidadTecnicos >= 3) return false;

    tecnicos[cantidadTecnicos] = t;
    cantidadTecnicos++;
    return true;
}

// Simulación completa
void SistemaCentral::simular(int dias) {
    for (int i = 0; i < dias && i < 30; i++) {
        procesarDia(i + 1);
    }
}

void SistemaCentral::ordenarEquipos(){
    for (int i = 0; i < cantidadEquipos - 1; i++){
        for (int j = 0; j < cantidadEquipos - i - 1; j++){
            if (equipos[j]->calcularPrioridad() <
                equipos[j + 1]->calcularPrioridad()){
                Equipo* temp = equipos[j];
                equipos[j] = equipos[j + 1];
                equipos[j + 1] = temp;
            }
        }
    }
}

void SistemaCentral::mostrarHistorial() {
    for (int i = 0; i < totalDias; i++) {
        cout << dias[i]->toString() << endl;
    }
}

void SistemaCentral::procesarDia(int numDia) {

    Dia* dia = new Dia(numDia);

    // 1. Degradar
    for (int i = 0; i < cantidadEquipos; i++) {
        equipos[i]->degradar();
    }

    // 2. Calcular prioridades
    for (int i = 0; i < cantidadEquipos; i++) {
        double p = equipos[i]->calcularPrioridad();
        dia->registrarPrioridad(equipos[i], p);
    }

    // 3. Ordenar
    ordenarEquipos();

    // 4. Top 3 + atendidos
    for (int i = 0; i < 3 && i < cantidadEquipos; i++) {
        dia->agregarTop(equipos[i]);
        dia->agregarAtendido(equipos[i]);
    }

    // 5. Aplicar mantenimiento
    Mantenimiento m;
    for (int i = 0; i < 3 && i < cantidadEquipos && i < cantidadTecnicos; i++) {
        m.repararEquipo(equipos[i], *tecnicos[i]);
    }

    // 6. Pendientes
    for (int i = 3; i < cantidadEquipos; i++) {
        dia->agregarPendiente(equipos[i]);
    }

    // 7. Métricas
    double sumaEstado = 0;
    int totalIncidencias = 0;

    for (int i = 0; i < cantidadEquipos; i++) {
        sumaEstado += equipos[i]->getEstado();
        totalIncidencias += equipos[i]->getCantidadIncidencias();
    }

    double promedio = sumaEstado / cantidadEquipos;

    dia->setPromedioEstado(promedio);
    dia->setTotalIncidencias(totalIncidencias);

    double riesgo = totalIncidencias * 0.5 + (100 - promedio) * 0.5;
    dia->setRiesgoGlobal(riesgo);

    // 8. Guardar el dia
    if (totalDias < 30) {
        dias[totalDias] = dia;  // copia
        totalDias++;
    }

    // 9. Reporte
    dia->generarReporte("reporte.txt");
}