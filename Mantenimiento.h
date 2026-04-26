//
// Created by mcmar on 25/4/2026.
//

#ifndef PROYECTO_MANTENIMIENTO_H
#define PROYECTO_MANTENIMIENTO_H

#include "Equipo.h"
#include "Tecnicos.h"

class Mantenimiento {
public:
    static void repararEquipo(Equipo* equipo, Tecnicos& tecnico);
};
#endif //PROYECTO_MANTENIMIENTO_H