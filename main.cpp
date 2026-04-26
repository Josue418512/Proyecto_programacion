#include <iostream>
#include "Equipo.h"
#include "Incidencias.h"
#include "Tecnicos.h"
#include "Mantenimiento.h"
#include "SistemaCentral.h"

using namespace std;

int main() {
/*
    // ===============================
    // 🔹 CREAR TECNICOS
    // ===============================
    Tecnicos tecnicos[3] = {
        Tecnicos("Juan"),
        Tecnicos("Maria"),
        Tecnicos("Carlos")
    };

    // ===============================
    // 🔹 CREAR EQUIPOS
    // ===============================
    const int N = 5;
    Equipo* equipos[N];

    for (int i = 0; i < N; i++) {
        equipos[i] = new Equipo("EQ-" + to_string(i));

        // 🔥 agregar incidencias (1 a 3)
        int cant = rand() % 3 + 1;

        for (int j = 0; j < cant; j++) {
            equipos[i]->agregarIncidencia(new Incidencias(0));
        }

        equipos[i]->calcularCriticidad();
        equipos[i]->calcularPrioridad();
    }

    // ===============================
    // 🔹 MOSTRAR EQUIPOS INICIALES
    // ===============================
    cout << "===== EQUIPOS INICIALES =====\n";
    for (int i = 0; i < N; i++) {
        cout << equipos[i]->toString() << endl;
    }

    // ===============================
    // 🔧 MANTENIMIENTO (manual)
    // ===============================
    cout << "\n===== MANTENIMIENTO =====\n";

    for (int i = 0; i < N; i++) {

        cout << "\n--- Revisando " << equipos[i]->getId() << " ---\n";

        if (equipos[i]->getCantidadIncidencias() > 0) {

            // buscar técnico disponible
            for (int t = 0; t < 3; t++) {
                if (tecnicos[t].getDisponible()) {
                    Mantenimiento::repararEquipo(equipos[i], tecnicos[t]);
                    break;
                }
            }
        } else {
            cout << "No necesita mantenimiento\n";
        }
    }

    // ===============================
    // 🔹 MOSTRAR DESPUÉS
    // ===============================
    cout << "\n===== DESPUES DE MANTENIMIENTO =====\n";
    for (int i = 0; i < N; i++) {
        cout << equipos[i]->toString() << endl;
    }

    // ===============================
    // 🧹 LIBERAR MEMORIA
    // ===============================
    for (int i = 0; i < N; i++) {
        delete equipos[i];
    }
    */


    // ===============================
    // 🔹 Prueba de sistema central
    // ===============================
    SistemaCentral sistema;

    // CREAR TECNICOS
    Tecnicos tecnicos[3] = {
        Tecnicos("Juan"),
        Tecnicos("Maria"),
        Tecnicos("Carlos")
    };
    for (int i = 0; i < 3; i++){
        sistema.agregarTecnicos(&tecnicos[i]);
    }

    // CREAR EQUIPOS
    const int N = 100;
    Equipo* equipos[N];

    for (int i = 0; i < N; i++) {
        equipos[i] = new Equipo("EQ-" + to_string(i));

        // agregar incidencias (1 a 3)
        int cant = rand() % 3 + 1;

        for (int j = 0; j < cant; j++) {
            equipos[i]->agregarIncidencia(new Incidencias(0));
        }

        equipos[i]->calcularCriticidad();
        equipos[i]->calcularPrioridad();

        sistema.agregarEquipo(equipos[i]);
    }

    sistema.simular(3);

    sistema.mostrarHistorial();

    return 0;
}