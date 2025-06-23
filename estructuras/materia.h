#ifndef MATERIAS_H
#define MATERIAS_H

typedef struct Materia
{
    char nombreMateria[100];
    int aprobado;
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

NodoMateria *crearNodo(struct Materia dato);

void insertarAlInicio(ListaMaterias *lista, struct Materia dato);

void insertarAlFinal(ListaMaterias *lista, struct Materia dato);

void eliminarNodo(ListaMaterias *lista, struct Materia dato);

NodoMateria *buscarNodo(ListaMaterias *lista, struct Materia dato);

#endif