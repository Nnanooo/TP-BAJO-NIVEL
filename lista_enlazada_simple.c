#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo
{
    int dato;
    struct Nodo *next;
} Nodo;

typedef struct Lista
{
    Nodo *head;
    Nodo *tail;
    int size;
} Lista;

Nodo *crearNodo(int dato)
{
    Nodo *nodoNuevo = (Nodo *)malloc(sizeof(Nodo));
    nodoNuevo->dato = dato;
    nodoNuevo->next = NULL;
    return nodoNuevo;
}

void insertarAlInicio(Lista *lista, int dato)
{
}

void insertarAlFinal(Lista *lista, int dato)
{
}

void eliminarNodo(Lista *lista, int dato)
{
}

Nodo *buscarNodo(Lista *lista, int dato)
{
}

void imprimirLista(Lista *lista)
{
}

void liberarLista(Lista *lista)
{
}

int main()
{
}