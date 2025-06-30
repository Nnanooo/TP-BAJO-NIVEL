#include "materia.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

void convertirMateriaAMinusculas(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    str[i] = tolower(str[i]);
  }
}

NodoMateria *crearNodoMateria(struct Materia dato)
{
  NodoMateria *nodoNuevo = (NodoMateria *)malloc(sizeof(NodoMateria));
  nodoNuevo->dato = dato;
  nodoNuevo->next = NULL;
  return nodoNuevo;
}

void insertarMateria(ListaMaterias *lista, struct Materia dato)
{
  // Si la materia no está dentro de ListaMaterias, se agrega
  if (buscarMateria(lista, dato.nombreMateria) == NULL)
  {
    NodoMateria *nodoAInsertar = crearNodoMateria(dato);

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
  else
  {
    printf("La materia ya se encuentra dada de alta");
  }
}

NodoMateria *buscarMateria(ListaMaterias *lista, char nombreMateria[])
{
  NodoMateria *nodoActual = lista->head;
  NodoMateria *nodoBuscado = NULL;
  convertirMateriaAMinusculas(nombreMateria);

  while (nodoActual != NULL)
  {
    convertirMateriaAMinusculas(nodoActual->dato.nombreMateria);
    if (strcmp(nodoActual->dato.nombreMateria, nombreMateria) == 0)
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

void eliminarMateria(ListaMaterias *lista, char nombreMateria[])
{
  NodoMateria *nodoActual = lista->head;

  int tam = lista->size;

  if (nodoActual != NULL)
  {
    // por si es el primer elemento de la lista el que hay que borrar
    if (strcmp(nodoActual->dato.nombreMateria, nombreMateria) == 0)
    {
      lista->head = nodoActual->next;
      free(nodoActual);
      lista->size--;
    }
    else
    {
      for (int i = 0; i < lista->size; i++)
      {
        if ((nodoActual->next != NULL) &&
            strcmp(nodoActual->next->dato.nombreMateria, nombreMateria) == 0)
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
    printf("Materia no encontrada\n\n");
  }
}

void listarCatalogoDeMaterias(ListaMaterias *lista)
{
  NodoMateria *nodoActual = lista->head;
  printf("Materias disponibles: \n");
  for (int i = 0; i < lista->size; i++)
  {
    if (nodoActual->dato.estado)
    {
      printf("Materia: %s\n", nodoActual->dato.nombreMateria);
    }
    else
    {
      printf("Materia: %s\n", nodoActual->dato.nombreMateria);
    }
    nodoActual = nodoActual->next;
  }
}

void listarMateriasDeAlumno(ListaMaterias *lista)
{
  NodoMateria *nodoActual = lista->head;
  printf("Materias inscriptas del alumno: \n");
  for (int i = 0; i < lista->size; i++)
  {
    if (nodoActual->dato.estado)
    {
      printf("Materia: %s Estado: Aprobada Nota: %d\n", nodoActual->dato.nombreMateria, nodoActual->dato.nota);
    }
    else
    {
      printf("Materia: %s Estado: Desaprobada Nota: %d\n", nodoActual->dato.nombreMateria, nodoActual->dato.nota);
    }
    nodoActual = nodoActual->next;
  }
}

float promedioNota(ListaMaterias *lista)
{
  if (lista == NULL || lista->head == NULL || lista->size == 0)
  {
    return 0.0f;
  }
  NodoMateria *nodoActual = lista->head;
  int contador = 0;
  float sumaNota = 0.0f;

  for (int i = 0; i < lista->size; i++)
  {
    sumaNota += nodoActual->dato.nota;
    nodoActual = nodoActual->next;
    contador++;
  }

  return sumaNota / contador;
}

void modificarEstadoMateria(ListaMaterias *lista, char nombreMateria[], bool nuevoEstado)
{
  NodoMateria *nodoActual = lista->head;

  while (nodoActual != NULL)
  {
    if (nodoActual->dato.nombreMateria == nombreMateria)
    {
      nodoActual->dato.estado = nuevoEstado;
      printf("El estado de la materia %s ha sido modificado a %d \n", nodoActual->dato.nombreMateria, nodoActual->dato.estado);
      break;
    }
    else
    {
      nodoActual = nodoActual->next;
    }
  }

  if (nodoActual == NULL)
  {
    printf("Materia a modificar no encontrada\n\n");
  }
}

void modificarNotaMateria(ListaMaterias *lista, char nombreMateria[], int nuevaNotaMateria)
{
  NodoMateria *nodoActual = lista->head;

  while (nodoActual != NULL)
  {
    if (nodoActual->dato.nombreMateria == nombreMateria)
    { /*
      nodoActual->dato.estado = nuevoEstado;
      printf("El estado de la materia %s ha sido modificado a %d \n", nodoActual->dato.nombreMateria, nodoActual->dato.estado);
      break;
      */
    }
    else
    {
      nodoActual = nodoActual->next;
    }
  }

  if (nodoActual == NULL)
  {
    printf("Materia a modificar no encontrada\n\n");
  }
}