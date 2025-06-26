#ifndef ALUMNO_H
#define ALUMNO_H
#include "materia.h"

typedef struct Alumno
{
    char nombre[100];
    int edad;
    int legajo;
    struct ListaMaterias materias;
} Alumno;

typedef struct NodoAlumno {
    struct Alumno dato;
    struct NodoAlumno *next;
} NodoAlumno;

typedef struct ListaAlumnos {
    NodoAlumno *head;
    NodoAlumno *tail;
    int size;
} ListaAlumnos;

NodoAlumno *crearNodoAlumno(struct Alumno dato);

void insertarAlumnoAlInicio(ListaAlumnos *lista, struct Alumno dato);

void insertarAlumnoAlFinal(ListaAlumnos *lista, struct Alumno dato);

void eliminarAlumno(ListaAlumnos *lista, char nombreAlumnoAEliminar[]);

NodoAlumno *buscarAlumnoPorNombre(ListaAlumnos *lista, char nombreAlumnoBuscado[]);

NodoAlumno *buscarAlumnoPorRangoDeEdad(ListaAlumnos *lista, int edadMinima, int edadMaxima);

void listarAlumnos(ListaAlumnos *lista);

#endif