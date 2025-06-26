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
 
NodoMateria *crearNodoMateria(struct Materia dato);

void insertarMateriaAlInicio(ListaMaterias *lista, struct Materia dato);

void insertarMateriaAlFinal(ListaMaterias *lista, struct Materia dato);

NodoMateria *buscarMateria(ListaMaterias *lista, char nombreMateria[]);

void eliminarMateria(ListaMaterias *lista, char nombreMateria[]);

void listarMaterias(ListaMaterias *lista);

#endif