#ifndef ALUMNO_H
#define ALUMNO_H
#include "materia.h"

typedef struct Alumno
{
    char nombre[25];
    char apellido[25];
    int edad;
    int legajo;
    struct ListaMaterias *materias;
} Alumno;

typedef struct NodoAlumno
{
    struct Alumno dato;
    struct NodoAlumno *next;
} NodoAlumno;

typedef struct ListaAlumnos
{
    NodoAlumno *head;
    NodoAlumno *tail;
    int size;
} ListaAlumnos;

NodoAlumno *crearNodoAlumno(struct Alumno dato);

void insertarAlumno(ListaAlumnos *lista, struct Alumno dato);

void eliminarAlumno(ListaAlumnos *lista, int legajo);

NodoAlumno *buscarAlumnoPorNombreYApellido(ListaAlumnos *lista, char nombreAlumnoBuscado[], char apellidoAlumnoBuscado[]);

ListaAlumnos *buscarAlumnoPorRangoDeEdad(ListaAlumnos *lista, int edadMinima, int edadMaxima);

NodoAlumno *buscarAlumnoPorLegajo(ListaAlumnos *lista, int legajoAlumnoBuscado);

// Antes de llamar a alguno de las siguientes funciones ubicar al alumno por legajo
// Por si hay 2 alumnos con mismo nombre y apellido
void modificarNombreAlumno(NodoAlumno *alumnoAModificar, char nuevoNombreAlumno[]);

void modificarApellidoAlumno(NodoAlumno *alumnoAModificar, char nuevoApellidoAlumno[]);

void modificarEdadAlumno(NodoAlumno *alumnoAModificar, int nuevaEdadAlumno);

void modificarLegajoAlumno(NodoAlumno *alumnoAModificar, int nuevoLegajoAlumno);

void listarAlumnos(ListaAlumnos *lista);

#endif