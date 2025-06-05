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
    Nodo *nodoNuevo = crearNodo(dato);

    if (lista->size == 0)
    {
        lista->head = nodoNuevo;
        lista->tail = nodoNuevo;
        nodoNuevo->next = NULL;
    }
    else
    {
        nodoNuevo->next = lista->head;
        lista->head = nodoNuevo;
    }

    lista->size++;
}

void insertarAlFinal(Lista *lista, int dato)
{
    Nodo *nodoNuevo = crearNodo(dato);

    if (lista->size == 0)
    {
        lista->head = nodoNuevo;
        lista->tail = nodoNuevo;
        nodoNuevo->next = NULL;
    }
    else
    {
        nodoNuevo->next = lista->head;
        lista->head = nodoNuevo;
    }

    lista->size++;
}

void eliminarNodo(Lista *lista, int dato)
{
    Nodo *nodoActual = lista->head;

    int tam = lista->size;

    if (nodoActual != NULL) {
        //por si es el primer elemento de la lista el que hay que borrar
        if (nodoActual->dato == dato) {
            lista->head = nodoActual->next;
            free(nodoActual);
            lista->size --;
        } else {
            for(int i = 0; i < lista->size; i++) {
                if ((nodoActual->next != NULL) && nodoActual->next->dato == dato) {
                    //guardo la copia del puntero a borrar
                    Nodo *nodoAEliminar = nodoActual->next;
                    //cambio el next 
                    nodoActual->next = nodoActual->next->next;
                    //libero el lugar donde esta la copia
                    free(nodoAEliminar);
                    
                    if (nodoActual->next == NULL) {
                        lista->tail = nodoActual;
                    }
                    lista->size --;
                    break;
                } else {
                    nodoActual = nodoActual->next;
                }
            }
        }
    }

    if (tam == lista->size) {
        printf("Elemento no encontrado\n\n");
    }
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
    int opcion = 0;
    int datoAAgregar;
    int datoAEliminar;
    int datoABuscar;
    Lista *nuevaLista = (Lista *)malloc(sizeof(Lista));
    nuevaLista->size = 0;

    do
    {
        printf("Lista Enlazada \n\n");
        printf("Opción 1: Insertar un elemento al inicio de la lista\n");
        printf("Opción 2: Insertar un elemento al final de la lista\n");
        printf("Opción 3: Eliminar un elemento de la lista\n");
        printf("Opción 4: Buscar un elemento en la lista\n");
        printf("Opción 5: Imprimir todos los elementos de la lista\n");
        printf("Opción 6: Liberar la memoria utilizada por la lista\n");
        printf("Opción 7: Salir\n");
        printf("\nIngrese una opción: ");

        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            printf("Ingrese el número a agregar al principio de la lista: ");
            scanf("%d", &datoAAgregar);

            insertarAlInicio(nuevaLista, datoAAgregar);
            break;

        case 2:
            printf("Ingrese el número a agregar al final de la lista: ");
            scanf("%d", &datoAAgregar);

            insertarAlFinal(nuevaLista, datoAAgregar);
            break;

        case 3:
            printf("Ingrese el número a eliminar de la lista: ");
            scanf("%d", &datoAEliminar);

            eliminarNodo(nuevaLista, datoAEliminar);
            break;

        case 4:
            printf("Ingrese el número a buscar en la lista: ");
            scanf("%d", &datoABuscar);

            Nodo *nodoEncontrado = buscarNodo(nuevaLista, datoABuscar);
            if (nodoEncontrado != NULL)
            {
                printf("El elemento buscado se encuentra en la lista\n");
            }
            else
            {
                printf("El elemento buscado no se encuentra en la lista\n");
            }
            break;

        case 5:
            imprimirLista(nuevaLista);
            break;

        case 6:
            liberarLista(nuevaLista);
            printf("Memoria liberada\n");
            break;

        case 7:
            printf("Usted ha salido del menú\n");
            exit(EXIT_SUCCESS);

        default:
            printf("Opción inválida, intente nuevamente\n");
        }
    } while (opcion != 7);
}