//
// Created by mcmar on 25/4/2026.
//

#include "Tecnicos.h"

Tecnicos::Tecnicos(string nombre) {
    this->nombre = nombre;
    disponible = true;
}

string Tecnicos::getNombre()  {
    return nombre;
}

bool Tecnicos::getDisponible() {
    return disponible;
}

void Tecnicos::ocupar() {
    disponible = false;
}

void Tecnicos::liberar() {
    disponible = true;
}
