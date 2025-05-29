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
    Nodo *nodoPrincipio = crearNodo(dato);

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

void insertarAlFinal(Lista *lista, int dato)
{
    Nodo *nodoPrincipio = crearNodo(dato);

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

void eliminarNodo(Lista *lista, int dato)
{
    Nodo *nodoFinal = crearNodo(dato);
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

Nodo *buscarNodo(Lista *lista, int dato)
{
    Nodo *nodoActual = lista->head;
    Nodo *nodoBuscado = NULL;

    while (nodoActual != NULL)
    {
        if (nodoActual->dato == dato)
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

void imprimirLista(Lista *lista)
{
    Nodo *nodoActual = lista->head;
    printf("Elementos de la lista: \n");
    printf("[\n");
    for (int i = 0; i < lista->size; i++)
    {
        printf("%d\n", nodoActual->dato);
        nodoActual = nodoActual->next;
    }
    printf("]\n");
}

void liberarLista(Lista *lista)
{
    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;
    free(lista);
}

int main()
{
}