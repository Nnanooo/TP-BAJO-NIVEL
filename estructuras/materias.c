#include "materia.h"
#include <stdlib.h>
#include <stdio.h>

NodoMateria *crearNodo(struct Materia dato)
{
    NodoMateria *nodoNuevo = (NodoMateria *)malloc(sizeof(NodoMateria));
    nodoNuevo->dato = dato;
    nodoNuevo->next = NULL;
    return nodoNuevo;
}

void insertarAlInicio(ListaMaterias *lista, struct Materia dato)
{
    NodoMateria *nodoPrincipio = crearNodo(dato);

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

void insertarAlFinal(ListaMaterias *lista, struct Materia dato)
{
    NodoMateria *nodoFinal = crearNodo(dato);
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

void eliminarNodo(ListaMaterias *lista, struct Materia dato)
{
    NodoMateria *nodoActual = lista->head;

    int tam = lista->size;

    if (nodoActual != NULL)
    {
        // por si es el primer elemento de la lista el que hay que borrar
        if (nodoActual->dato.nombreMateria == dato.nombreMateria)
        {
            lista->head = nodoActual->next;
            free(nodoActual);
            lista->size--;
        }
        else
        {
            for (int i = 0; i < lista->size; i++)
            {
                if ((nodoActual->next != NULL) && nodoActual->next->dato.nombreMateria == dato.nombreMateria)
                {
                    // guardo la copia del puntero a borrar
                    NodoMateria *nodoAEliminar = nodoActual->next;
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

NodoMateria *buscarNodo(ListaMaterias *lista, struct Materia dato)
{
    NodoMateria *nodoActual = lista->head;
    NodoMateria *nodoBuscado = NULL;

    while (nodoActual != NULL)
    {
        if (nodoActual->dato.nombreMateria == dato.nombreMateria)
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