//
// Created by mcmar on 25/4/2026.
//

#include "Mantenimiento.h"

using namespace std;

void Mantenimiento::repararEquipo(Equipo* equipo, Tecnicos& tecnico) {

    if (!tecnico.getDisponible()) {
        cout << "Tecnico no disponible\n";
        return;
    }

    if (equipo->getCantidadIncidencias() == 0) {
        cout << "El equipo no tiene incidencias\n";
        return;
    }

    tecnico.ocupar();

    cout << "Tecnico " << tecnico.getNombre()
         << " reparando equipo...\n";

    equipo->limpiarIncidencias();

    if (equipo->getEstado() + 20 > 100){
        equipo->setEstado(100);
    }else{
        equipo->setEstado(equipo->getEstado() + 20);
    }
    equipo->setTiempoInactivo(0);

    cout << "Equipo reparado\n";

    tecnico.liberar();
}