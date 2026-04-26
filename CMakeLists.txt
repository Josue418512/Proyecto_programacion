cmake_minimum_required(VERSION 4.0)
project(Proyecto_programacion)

set(CMAKE_CXX_STANDARD 20)

add_executable(Proyecto_programacion main.cpp
        Equipo.cpp
        Equipo.h
        Incidencias.cpp
        Incidencias.h
        Mantenimiento.cpp
        Mantenimiento.h
        Tecnicos.cpp
        Tecnicos.h
        Dia.h
        Dia.cpp
        SistemaCentral.h
        SistemaCentral.cpp
)