#include "alumno.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertirNombreAMinusculas(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
    }
}

NodoAlumno *crearNodoAlumno(struct Alumno dato)
{
    NodoAlumno *nodoNuevo = (NodoAlumno *)malloc(sizeof(NodoAlumno));
    nodoNuevo->dato = dato;
    nodoNuevo->next = NULL;
    return nodoNuevo;
}

void insertarAlumno(ListaAlumnos *lista, struct Alumno dato)
{
    NodoAlumno *nodoAInsertar = crearNodoAlumno(dato);
    if (lista->size == 0)
    {
        lista->head = nodoAInsertar;
        lista->tail = nodoAInsertar;
        nodoAInsertar->next = NULL;
    }
    else
    {
        lista->tail->next = nodoAInsertar;
        lista->tail = nodoAInsertar;
        nodoAInsertar->next = NULL;
    }
    lista->size++;
}

void eliminarAlumno(ListaAlumnos *lista, int legajo)
{
    NodoAlumno *nodoActual = lista->head;

    int tam = lista->size;

    if (nodoActual != NULL)
    {
        // por si es el primer elemento de la lista el que hay que borrar
        if (nodoActual->dato.legajo == legajo)
        {
            lista->head = nodoActual->next;
            free(nodoActual);
            lista->size--;
        }
        else
        {
            for (int i = 0; i < lista->size; i++)
            {
                if ((nodoActual->next != NULL) && nodoActual->next->dato.legajo == legajo)
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

NodoAlumno *buscarAlumnoPorNombreYApellido(ListaAlumnos *lista, char nombreAlumnoBuscado[], char apellidoAlumnoBuscado[])
{
    NodoAlumno *nodoActual = lista->head;
    NodoAlumno *nodoBuscado = NULL;
    convertirNombreAMinusculas(nombreAlumnoBuscado);
    convertirNombreAMinusculas(apellidoAlumnoBuscado);
    while (nodoActual != NULL)
    {
        convertirNombreAMinusculas(nodoActual->dato.nombre);
        convertirNombreAMinusculas(nodoActual->dato.apellido);
        if (strcmp(nodoActual->dato.nombre, nombreAlumnoBuscado) == 0 && strcmp(nodoActual->dato.apellido, apellidoAlumnoBuscado) == 0)
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

NodoAlumno *buscarAlumnoPorLegajo(ListaAlumnos *lista, int legajoAlumnoBuscado)
{
    NodoAlumno *nodoActual = lista->head;
    NodoAlumno *nodoBuscado = NULL;

    while (nodoActual != NULL)
    {
        if (nodoActual->dato.legajo == legajoAlumnoBuscado)
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

ListaAlumnos *buscarAlumnoPorRangoDeEdad(ListaAlumnos *lista, int edadMinima, int edadMaxima)
{
    NodoAlumno *nodoActual = lista->head;
    struct ListaAlumnos *alumnosEnRango = (struct ListaAlumnos *)malloc(sizeof(struct ListaAlumnos));
    alumnosEnRango->size = 0;
    alumnosEnRango->head = NULL;
    while (nodoActual != NULL)
    {
        if (nodoActual->dato.edad >= edadMinima && nodoActual->dato.edad <= edadMaxima)
        {
            insertarAlumno(alumnosEnRango, nodoActual->dato);
            nodoActual = nodoActual->next;
        }
        else
        {
            nodoActual = nodoActual->next;
        }
    }
    return alumnosEnRango;
}

// Probar esto bien después por tema punteros (linea 160)
void modificarNombreAlumno(NodoAlumno *alumnoAModificar, char nuevoNombreAlumno[])
{
    if (strlen(nuevoNombreAlumno) <= 25)
    {
        strcpy(alumnoAModificar->dato.nombre, nuevoNombreAlumno);
    }
    else
    {
        printf("El nuevo nombre debe incluir menos de 25 caracteres");
    }
}

void modificarApellidoAlumno(NodoAlumno *alumnoAModificar, char nuevoApellidoAlumno[])
{
    if (strlen(nuevoApellidoAlumno) <= 25)
    {
        strcpy(alumnoAModificar->dato.apellido, nuevoApellidoAlumno);
    }
    else
    {
        printf("El nuevo apellido debe incluir menos de 25 caracteres");
    }
}

void modificarEdadAlumno(NodoAlumno *alumnoAModificar, int nuevaEdadAlumno)
{
    if (nuevaEdadAlumno >= 16 && nuevaEdadAlumno < 90)
    {
        alumnoAModificar->dato.edad = nuevaEdadAlumno;
    }
    else
    {
        printf("\nLa edad ingresada debe ser mayor o igual a 16 y menor a 90\n");
    }
}

void modificarLegajoAlumno(NodoAlumno *alumnoAModificar, int nuevoLegajoAlumno)
{
    if (nuevoLegajoAlumno >= 0)
    {
        alumnoAModificar->dato.legajo = nuevoLegajoAlumno;
    }
    else
    {
        printf("El legajo ingresado debe ser mayor o igual a 0");
    }
}

void listarAlumnos(ListaAlumnos *lista)
{
    NodoAlumno *nodoActual = lista->head;
    printf("\nAlumnos: \n");
    for (int i = 0; i < lista->size; i++)
    {
        printf("Nombre: %s  Apellido: %s  Legajo: %d  Edad: %d\n", nodoActual->dato.nombre, nodoActual->dato.apellido, nodoActual->dato.legajo, nodoActual->dato.edad);
        nodoActual = nodoActual->next;
    }
}
