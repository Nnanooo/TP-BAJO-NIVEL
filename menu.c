#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras/alumno.h"
#include "estructuras/materia.h"

int main()
{
    int opcionMenuPrincipal;
    int opcionEstudiantes;
    int opcionMaterias;

    ListaAlumnos *alumnos = (ListaAlumnos *)malloc(sizeof(ListaAlumnos));
    alumnos->size = 0;

    do
    {
        printf("Menú principal \n\n");
        printf("Opción 1: Gestionar estudiantes\n");
        printf("Opción 2: Gestionar materias\n");
        printf("Opción 3: Salir\n");
        printf("\nIngrese una opción: ");

        scanf("%d", &opcionMenuPrincipal);

        switch (opcionMenuPrincipal)
        {
        // Menu de estudiantes
        case 1:
            do
            {
                printf("\nEstudiantes \n\n");
                printf("Opción 1: Ingresar a un nuevo estudiante\n");
                printf("Opción 2: Modificar datos de un estudiante\n");
                printf("Opción 3: Dar de baja a un estudiante\n");
                printf("Opción 4: Listar todos los estudiantes ingresados\n");
                printf("Opción 5: Buscar a un estudiante por nombre y apellido\n");
                printf("Opción 6: Buscar a estudiantes por rango de edad\n");
                printf("Opción 7: Volver al menú principal\n");

                scanf("%d", &opcionEstudiantes);
                switch (opcionEstudiantes)
                {
                case 1:
                {
                    Alumno alumnoAInsertar;
                    printf("Inserte el nombre del alumno: ");
                    scanf("%s", alumnoAInsertar.nombre);
                    printf("Ingrese el apellido del alumno: ");
                    scanf("%s", alumnoAInsertar.apellido);
                    printf("Inserte el legajo del alumno: ");
                    scanf("%d", &alumnoAInsertar.legajo);
                    if (buscarAlumnoPorLegajo(alumnos, alumnoAInsertar.legajo))
                    {
                        printf("\nLegajo repetido, ingrese un legajo distinto\n");
                        break;
                    }
                    printf("Inserte la edad del alumno: ");
                    scanf("%d", &alumnoAInsertar.edad);
                    if (alumnoAInsertar.edad < 16 || alumnoAInsertar.edad > 90)
                    {
                        printf("\nEdad invalida, el alumno debe de ser mayor o igual a 16 y menor a 90\n");
                        break;
                    }
                    insertarAlumno(alumnos, alumnoAInsertar);

                    alumnos->size = alumnos->size++;
                    break;
                }

                case 2:
                {
                    int legajoAlumnoAModificar;
                    int opcionAModificar;
                    listarAlumnos(alumnos);
                    printf("Ingrese el legajo del alumno a modificar: ");
                    scanf("%d", &legajoAlumnoAModificar);

                    if (buscarAlumnoPorLegajo(alumnos, legajoAlumnoAModificar) != NULL)
                    {
                        printf("¿Que desea modificar?\n");
                        printf("1. Nombre\n");
                        printf("2. Apellido\n");
                        printf("3. Edad\n");
                        printf("4. Legajo\n");
                        printf("5. Volver a la sección de estudiantes\n");
                        printf("Ingrese una opción: ");

                        scanf("%d", &opcionAModificar);

                        switch (opcionAModificar)
                        {
                        case 1:
                        {
                            char nuevoNombreAlumno[25];
                            printf("Ingrese el nuevo nombre: ");
                            scanf("%s", nuevoNombreAlumno);

                            modificarNombreAlumno(buscarAlumnoPorLegajo(alumnos, legajoAlumnoAModificar), nuevoNombreAlumno);
                            printf("\nNombre cambiado exitosamente\n\n");
                            break;
                        }
                        // IMPLEMENTAR APELLIDO EN STRUCT ALUMNO ANTES DE MODIFICAR
                        case 2:
                        {
                            char nuevoApellidoAlumno[25];
                            printf("Ingrese el nuevo apellido: ");
                            scanf("%s", nuevoApellidoAlumno);

                            modificarApellidoAlumno(buscarAlumnoPorLegajo(alumnos, legajoAlumnoAModificar), nuevoApellidoAlumno);

                            printf("\nApellido cambiado exitosamente\n\n");
                            break;
                        }
                        case 3:
                        {
                            int nuevaEdadAlumno;
                            printf("Ingrese la nueva edad: ");
                            scanf("%d", &nuevaEdadAlumno);

                            modificarEdadAlumno(buscarAlumnoPorLegajo(alumnos, legajoAlumnoAModificar), nuevaEdadAlumno);

                            if (buscarAlumnoPorLegajo(alumnos, legajoAlumnoAModificar)->dato.edad == nuevaEdadAlumno)
                            {
                                printf("\nEdad cambiada exitosamente\n\n");
                            }
                            break;
                        }
                        case 4:
                        {
                            int nuevoLegajoAlumno;
                            printf("Ingrese el nuevo legajo: ");
                            scanf("%d", &nuevoLegajoAlumno);

                            modificarLegajoAlumno(buscarAlumnoPorLegajo(alumnos, legajoAlumnoAModificar), nuevoLegajoAlumno);

                            printf("\nLegajo cambiado exitosamente\n\n");
                            break;
                        }
                        case 5:
                        {
                            break;
                        }
                        }
                    }
                    else
                    {
                        printf("\nEl alumno con el legajo solicitado no existe\n\n");
                    }
                    break;
                }
                case 3:
                {
                    int legajoAlumnoAEliminar;
                    printf("Ingrese el legajo del alumno a dar de baja: ");
                    scanf("%d", &legajoAlumnoAEliminar);
                    if (buscarAlumnoPorLegajo(alumnos, legajoAlumnoAEliminar) != NULL)
                    {
                        eliminarAlumno(alumnos, legajoAlumnoAEliminar);
                        alumnos->size = alumnos->size--;
                        printf("Alumno dado de baja exitosamente \n\n");
                    }
                    else
                    {
                        printf("El legajo del alumno a eliminar no existe\n\n");
                    }
                    break;
                }
                case 4:
                    listarAlumnos(alumnos);
                    break;
                case 5:
                {
                    char nombreBuscado[25];
                    char apellidoBuscado[25];

                    printf("Ingrese el nombre del alumno buscado: ");
                    scanf("%s", nombreBuscado);
                    printf("Ingrese el apellido del alumno buscado: ");
                    scanf("%s", apellidoBuscado);

                    NodoAlumno *alumnoBuscado = buscarAlumnoPorNombreYApellido(alumnos, nombreBuscado, apellidoBuscado);
                    if (alumnoBuscado == NULL)
                    {
                        printf("\nAlumno no encontrado\n");
                    }
                    else
                    {
                        printf("\n Nombre: %s \n Apellido: %s \n Legajo: %d \n Edad: %d\n ", alumnoBuscado->dato.nombre, alumnoBuscado->dato.apellido, alumnoBuscado->dato.legajo, alumnoBuscado->dato.edad);
                        // listarMaterias(alumnoBuscado->dato.materias);
                    }

                    break;
                }
                case 6:
                {
                    int edadMinima;
                    int edadMaxima;

                    printf("Ingrese edad minima del rango buscado: ");
                    scanf("%d", &edadMinima);
                    printf("Ingrese edad maxima del rango buscado: ");
                    scanf("%d", &edadMaxima);

                    if (edadMaxima < edadMinima)
                    {
                        printf("\nRango invalido\n");
                    }
                    else
                    {
                        ListaAlumnos *alumnosEncontrados = buscarAlumnoPorRangoDeEdad(alumnos, edadMinima, edadMaxima);
                        if (alumnosEncontrados->size == 0)
                        {
                            printf("\nAlumnos no encontrados dentro de ese rango.\n");
                        }
                        else
                        {
                            listarAlumnos(alumnosEncontrados);
                        }
                    }
                    break;
                }
                case 7:
                    break;
                }
            } while (opcionEstudiantes != 7);
            break;
        // Menu de materias
        case 2:
            do
            {
                printf("\nMaterias \n\n");
                printf("Opción 1: Crear una nueva materia\n");
                printf("Opción 2: Anotar a un estudiante a una materia\n");
                printf("Opción 3: Modificar materia de un estudiante\n");
                printf("Opción 4: Eliminar materia de un estudiante\n");
                printf("Opción 5: Listar todas las materias de un estudiante\n");
                printf("Opción 6: Rendir una materia\n");
                printf("Opción 7: Volver al menú principal\n");

                scanf("%d", &opcionMaterias);
                switch (opcionMaterias)
                {
                case 1:

                case 2:

                case 3:

                case 4:

                case 5:

                case 6:

                case 7:
                    break;
                }
            } while (opcionMaterias != 7);
            break;
        case 3:
            printf("Usted ha salido del menú\n");
            exit(EXIT_SUCCESS);

        default:
            printf("Opción inválida, intente nuevamente\n");
        }
    } while (opcionMenuPrincipal != 3);
}