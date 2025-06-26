#include "materia.h"
#include <stdio.h>
#include <stdlib.h>

NodoMateria *crearNodoMateria(struct Materia dato) {
  NodoMateria *nodoNuevo = (NodoMateria *)malloc(sizeof(NodoMateria));
  nodoNuevo->dato = dato;
  nodoNuevo->next = NULL;
  return nodoNuevo;
}

void insertarMateriaAlInicio(ListaMaterias *lista, struct Materia dato) {
    //Si la materia no está dentro de ListaMaterias, se agrega
    if (buscarMateria(lista, dato.nombreMateria) == NULL) {
        NodoMateria *nodoPrincipio = crearNodoMateria(dato);

        if (lista->size == 0) {
            lista->head = nodoPrincipio;
            lista->tail = nodoPrincipio;
            nodoPrincipio->next = NULL;
        } else {
            nodoPrincipio->next = lista->head;
            lista->head = nodoPrincipio;
        }

        lista->size++;
    } else {
        printf("La materia ya se encuentra dada de alta");
    }
}

void insertarMateriaAlFinal(ListaMaterias *lista, struct Materia dato) {
    //Si la materia no está dentro de ListaMaterias, se agrega
    if (buscarMateria(lista, dato.nombreMateria) == NULL) {
        NodoMateria *nodoFinal = crearNodoMateria(dato);

        if (lista->size == 0) {
        lista->head = nodoFinal;
        lista->tail = nodoFinal;
        nodoFinal->next = NULL;
        } else {
        lista->tail->next = nodoFinal;
        lista->tail = nodoFinal;
        nodoFinal->next = NULL;
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
  // IMPLEMENTAR
}