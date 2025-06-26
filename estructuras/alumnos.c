#include "alumno.h"
#include <stdlib.h>
#include <stdio.h>

NodoAlumno *crearNodoAlumno(struct Alumno dato)
{
    NodoAlumno *nodoNuevo = (NodoAlumno *)malloc(sizeof(NodoAlumno));
    nodoNuevo->dato = dato;
    nodoNuevo->next = NULL;
    return nodoNuevo;
}

void insertarAlumnoAlInicio(ListaAlumnos *lista, struct Alumno dato)
{
    NodoAlumno *nodoPrincipio = crearNodoAlumno(dato);

    if (lista->size == 0)
    {
        lista->head = nodoPrincipio;
        lista->tail = nodoPrincipio;
        nodoPrincipio->next = NULL;
    }
    else
    {
        nodoPrincipio->next = lista->head;
        lista->head = nodoPrincipio;
    }

    lista->size++;
}

void insertarAlumnoAlFinal(ListaAlumnos *lista, struct Alumno dato)
{
    NodoAlumno *nodoFinal = crearNodoAlumno(dato);
    if (lista->size == 0)
    {
        lista->head = nodoFinal;
        lista->tail = nodoFinal;
        nodoFinal->next = NULL;
    }
    else
    {
        lista->tail->next = nodoFinal;
        lista->tail = nodoFinal;
        nodoFinal->next = NULL;
    }
    lista->size++;
}

void eliminarAlumno(ListaAlumnos *lista, char nombreAlumnoAEliminar[])
{
    NodoAlumno *nodoActual = lista->head;

    int tam = lista->size;

    if (nodoActual != NULL)
    {
        // por si es el primer elemento de la lista el que hay que borrar
        if (nodoActual->dato.nombre == nombreAlumnoAEliminar)
        {
            lista->head = nodoActual->next;
            free(nodoActual);
            lista->size--;
        }
        else
        {
            for (int i = 0; i < lista->size; i++)
            {
                if ((nodoActual->next != NULL) && nodoActual->next->dato.nombre == nombreAlumnoAEliminar)
                {
                    // guardo la copia del puntero a borrar
                    NodoAlumno *nodoAEliminar = nodoActual->next;
                    // cambio el next
                    nodoActual->next = nodoActual->next->next;
                    // libero el lugar donde esta la copia
                    free(nodoAEliminar);

                    if (nodoActual->next == NULL)
                    {
                        lista->tail = nodoActual;
                    }
                    lista->size--;
                    break;
                }
                else
                {
                    nodoActual = nodoActual->next;
                }
            }
        }
    }

    if (tam == lista->size)
    {
        printf("Elemento no encontrado\n\n");
    }
}

NodoAlumno *buscarAlumnoPorNombre(ListaAlumnos *lista, char nombreAlumnoBuscado[])
{
    NodoAlumno *nodoActual = lista->head;
    NodoAlumno *nodoBuscado = NULL;

    while (nodoActual != NULL)
    {
        if (nodoActual->dato.nombre == nombreAlumnoBuscado)
        {
            nodoBuscado = nodoActual;
            break;
        }
        else
        {
            nodoActual = nodoActual->next;
        }
    }
    return nodoBuscado;
}

NodoAlumno *buscarAlumnoPorRangoDeEdad(ListaAlumnos *lista, int edadMinima, int edadMaxima)
{
    //IMPLEMENTAR
    return NULL;
}

void listarAlumnos(ListaAlumnos *lista) {
    //IMPLEMENTAR
}