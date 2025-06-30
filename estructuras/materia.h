#ifndef MATERIAS_H
#define MATERIAS_H
#include <stdbool.h>

typedef struct Materia
{
    char nombreMateria[100];
    bool estado;
    int nota;
} Materia;

typedef struct NodoMateria
{
    struct Materia dato;
    struct NodoMateria *next;
} NodoMateria;

typedef struct ListaMaterias
{
    NodoMateria *head;
    NodoMateria *tail;
    int size;
} ListaMaterias;

NodoMateria *crearNodoMateria(struct Materia dato);

void insertarMateria(ListaMaterias *lista, struct Materia dato);

NodoMateria *buscarMateria(ListaMaterias *lista, char nombreMateria[]);

void eliminarMateria(ListaMaterias *lista, char nombreMateria[]);

void listarCatalogoDeMaterias(ListaMaterias *lista);

void listarMateriasDeAlumno(ListaMaterias *lista);

void modificarMateria(ListaMaterias *lista, char nombreMateria[], int nuevoEstado);

#endif