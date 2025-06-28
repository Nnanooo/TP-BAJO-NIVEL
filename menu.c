#include <stdio.h>
#include <stdlib.h>
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
                printf("Estudiantes \n\n");
                printf("Opción 1: Ingresar a un nuevo estudiante\n");
                printf("Opción 2: Modificar datos de un estudiante\n");
                printf("Opción 3: Dar de baja a un estudiante\n");
                printf("Opción 4: Listar todos los estudiantes ingresados\n");
                // hay quilombos con nombres y apellidos iguales debatir eso
                printf("Opción 5: Buscar a un estudiante por nombre\n");
                printf("Opción 6: Buscar a estudiantes por rango de edad\n");
                printf("Opción 7: Volver al menú principal\n");

                scanf("%d", &opcionEstudiantes);
                switch (opcionEstudiantes)
                {
                case 1:
                {
                    Alumno alumnoAInsertar;
                    // Separar nombre y apellido en la struct alumno
                    printf("Inserte el nombre del alumno: ");
                    scanf("%s", alumnoAInsertar.nombre);
                    printf("Inserte el legajo del alumno: ");
                    scanf("%d", &alumnoAInsertar.legajo);
                    printf("Inserte la edad del alumno: ");
                    scanf("%d", &alumnoAInsertar.edad);

                    insertarAlumno(alumnos, alumnoAInsertar);

                    alumnos->size = alumnos->size++;
                    break;
                }

                case 2:
                {
                    int legajoAlumnoAModificar;
                    int opcionAModificar;
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
                            char nuevoNombreAlumno[100];
                            printf("Ingrese el nuevo nombre: ");
                            scanf("%s", nuevoNombreAlumno);

                            modificarNombreAlumno(buscarAlumnoPorLegajo(alumnos, legajoAlumnoAModificar), nuevoNombreAlumno);
                            printf("Nombre cambiado exitosamente\n\n");
                            break;
                        }
                        // IMPLEMENTAR APELLIDO EN STRUCT ALUMNO ANTES DE MODIFICAR
                        case 2:
                        {
                            char nuevoApellidoAlumno[100];
                            printf("Ingrese el nuevo apellido: ");
                            scanf("%s", nuevoApellidoAlumno);

                            modificarNombreAlumno(buscarAlumnoPorLegajo(alumnos, legajoAlumnoAModificar), nuevoApellidoAlumno);

                            printf("Apellido cambiado exitosamente\n\n");
                            break;
                        }
                        case 3:
                        {
                            int nuevaEdadAlumno;
                            printf("Ingrese la nueva edad: ");
                            scanf("%d", &nuevaEdadAlumno);

                            modificarEdadAlumno(buscarAlumnoPorLegajo(alumnos, legajoAlumnoAModificar), nuevaEdadAlumno);

                            printf("Edad cambiada exitosamente\n\n");
                            break;
                        }
                        case 4:
                        {
                            int nuevoLegajoAlumno;
                            printf("Ingrese el nuevo legajo: ");
                            scanf("%d", &nuevoLegajoAlumno);

                            modificarLegajoAlumno(buscarAlumnoPorLegajo(alumnos, legajoAlumnoAModificar), nuevoLegajoAlumno);

                            printf("Legajo cambiado exitosamente\n\n");
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
                        printf("El alumno con el legajo solicitado no existe\n\n");
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
                    break;
                case 6:
                    break;
                case 7:
                    break;
                }
            } while (opcionEstudiantes != 7);
            break;
        // Menu de materias
        case 2:
            do
            {
                printf("Materias \n\n");
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