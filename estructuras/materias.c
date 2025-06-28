#include "materia.h"
#include <stdio.h>
#include <stdlib.h>

NodoMateria *crearNodoMateria(struct Materia dato) {
  NodoMateria *nodoNuevo = (NodoMateria *)malloc(sizeof(NodoMateria));
  nodoNuevo->dato = dato;
  nodoNuevo->next = NULL;
  return nodoNuevo;
}

void insertarMateria(ListaMaterias *lista, struct Materia dato) {
    //Si la materia no está dentro de ListaMaterias, se agrega
    if (buscarMateria(lista, dato.nombreMateria) == NULL) {
        NodoMateria *nodoAInsertar = crearNodoMateria(dato);

        if (lista->size == 0) {
        lista->head = nodoAInsertar;
        lista->tail = nodoAInsertar;
        nodoAInsertar->next = NULL;
        } else {
        lista->tail->next = nodoAInsertar;
        lista->tail = nodoAInsertar;
        nodoAInsertar->next = NULL;
        }
        
        lista->size++;
    } else {
        printf("La materia ya se encuentra dada de alta");
    }
}

NodoMateria *buscarMateria(ListaMaterias *lista, char nombreMateria[]) {
  NodoMateria *nodoActual = lista->head;
  NodoMateria *nodoBuscado = NULL;

  while (nodoActual != NULL) {
    if (nodoActual->dato.nombreMateria == nombreMateria) {
      nodoBuscado = nodoActual;
      break;
    } else {
      nodoActual = nodoActual->next;
    }
  }
  return nodoBuscado;
}

void eliminarMateria(ListaMaterias *lista, char nombreMateria[]) {
  NodoMateria *nodoActual = lista->head;

  int tam = lista->size;

  if (nodoActual != NULL) {
    // por si es el primer elemento de la lista el que hay que borrar
    if (nodoActual->dato.nombreMateria == nombreMateria) {
      lista->head = nodoActual->next;
      free(nodoActual);
      lista->size--;
    } else {
      for (int i = 0; i < lista->size; i++) {
        if ((nodoActual->next != NULL) &&
            nodoActual->next->dato.nombreMateria == nombreMateria) {
          // guardo la copia del puntero a borrar
          NodoMateria *nodoAEliminar = nodoActual->next;
          // cambio el next
          nodoActual->next = nodoActual->next->next;
          // libero el lugar donde esta la copia
          free(nodoAEliminar);

          if (nodoActual->next == NULL) {
            lista->tail = nodoActual;
          }
          lista->size--;
          break;
        } else {
          nodoActual = nodoActual->next;
        }
      }
    }
  }

  if (tam == lista->size) {
    printf("Materia no encontrada\n\n");
  }
}

void listarMaterias(ListaMaterias *lista) {
  NodoMateria *nodoActual = lista->head;
    printf("Materias inscriptas del alumno: \n");
    for (int i = 0; i < lista->size; i++)
    {  
        if (nodoActual->dato.aprobado) {
          printf("Materia: %s Estado: Aprobada \n", nodoActual->dato.nombreMateria);
        } else {
          printf("Materia: %s Estado: Desaprobada \n", nodoActual->dato.nombreMateria);
        }
        nodoActual = nodoActual->next;
    }
}

void modificarMateria(ListaMaterias *lista, char nombreMateria[], int nuevoEstado) {
  NodoMateria *nodoActual = lista->head;

  if (nuevoEstado == 0 || nuevoEstado == 1) {
    while (nodoActual != NULL) {
    if (nodoActual->dato.nombreMateria == nombreMateria) {
      nodoActual->dato.aprobado = nuevoEstado;
      printf("El estado de la materia %s ha sido modificada a %d \n", nodoActual->dato.nombreMateria,nodoActual->dato.aprobado);
      break;
    } else {
      nodoActual = nodoActual->next;
    }
  }

  if (nodoActual == NULL) {
    printf("Materia a modificar no encontrada\n\n");
  }
  } else {
    printf("El nuevo estado debe ser 0 (desaprobado) o 1 (aprobado)");
  }
}