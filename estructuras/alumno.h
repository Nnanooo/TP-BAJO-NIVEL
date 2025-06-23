#ifndef ALUMNO_H
#define ALUMNO_H
#include "materias.h"

typedef struct Alumno
{
    char nombre[100];
    char apellido[100];
    int edad;
    int legajo;
    struct ListaMaterias materias;
} Alumno;

#endif