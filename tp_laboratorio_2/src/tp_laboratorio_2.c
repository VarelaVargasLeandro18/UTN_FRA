/*
 ============================================================================
 Name        : tp_laboratorio_2.c
 Author      : VarelaVargasLeandro18
 Version     :
 Copyright   : Your copyright notice
 Description :
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"
#include "myFunc.h"

int main(void) {

	int option;
	int amEmployee = 0;
	int correcto = 0;

	Employee list [MAX];

	initEmployees (list, MAX);

	do
	{

		printf ("------------------------------------------------------------------\n");

		printf ("Menu:\n0. SALIR\n1. ALTAS\n2. MODIFICAR.\n3. BAJA\n4. INFORMAR.\n");

		do
		{

			option = (int)get_number ("Ingrese su opción: ");

			if (amEmployee == 0 && (option > 1 && option <= 4))
			{

				printf ("Aún no se ha ingresado ningún empleado!\n");

			}

		} while (amEmployee == 0 && (option > 1 && option <= 4));

		switch (option)
		{

			case 0:
				{

					printf ("Ha decidido salir del menú. Hasta Luego.\n");

					break;

				}

			case 1:
				{

					char name[51];
					char lastName[51];
					int ID;
					int sector;
					float salary;

					printf ("Ha ingresado al menú de ALTAS de empleados.\n");

					ID = calculateID (list, MAX);

					printf ("El ID del empleado es: %d.\n", ID);

					salary = get_number ("Ingrese el salario del empleado: $");

					sector = (int) get_number ("Ingrese el sector del empleado: ");

					__fpurge(stdin);

					printf ("Ingrese el nombre del empleado: ");

					fgets (name, 51, stdin);

					__fpurge (stdin);

					printf ("Ingrese el apellido del empleado: ");

					fgets (lastName, 51, stdin);

					correcto = addEmployee (list, MAX, ID, name, lastName, salary, sector);

					if (correcto == 0)
					{

						amEmployee++;

						printf ("El empleado se ha ingresado correctamente.\n");

					}
					else
					{

						printf ("Ha habido un error! Vuelva a intentarlo.\n");

						if (amEmployee >= MAX)
						{

							printf ("Ha excedido el número máximo de empleados.\n");

							break;

						}

					}

					break;

				}

			case 2:
				{

					char name[51];
					char lastName[51];
					int ID = 0;
					int Index = 0;
					int sector;
					float salary;

					printf ("Ha ingresado al menú de MODIFICACIÓN de empleados.\n");

					do
					{

						ID = (int)get_number ("Ingrese el ID del empleado en cuestión: ");

					} while (isValidID(list, MAX, ID) < 0);

					__fpurge (stdin);

					printf ("Ingrese el nombre del empleado: ");

					fgets (name, 51, stdin);

					__fpurge (stdin);

					printf ("Ingrese el apellido del empleado: ");

					fgets (lastName, 51, stdin);

					salary = get_number ("Ingrese el salario del empleado: $");

					sector = (int)get_number ("Ingrese el sector del empleado: ");

					modifyEmployee (list, Index, name, lastName, salary, sector);

					printf ("Se ha modificado el empleado correctamente.\n");

					break;

				}

			case 3:
				{

					int ID = 0;

					printf ("Ha ingreso al menú de BAJA de empleados.\n");

					do
					{

						ID = (int)get_number ("Ingrese el ID del empleado en cuestión: ");

					} while (isValidID(list, MAX, ID) < 0);

					removeEmployee (list, MAX, ID);

					printf ("Ha dado de baja al empleado correctamente.\n");

					break;

				}

			case 4:
				{

					//INFORMAR 1.LISTADO DE EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR. 2.TOTAL Y PROM SALARIOS. CANT EMPLEADOS QUE SUPERAN SALARIO PROM.

					printf ("Ha ingresado al menu de listado de empleados.\n");
					printf ("0. Salir.\n1.Listar Empleados.\n");
					printf ("2.Conocer la cantidad total y el promedio de salario, junto con la cantidad de empleados que lo superan.\n");

					int oplistado = (int) get_nr_bt ("Ingrese su opcion: ", 0, 2, "El ingreso no se encuentra entre los valores válidos.");

					if (oplistado == 0)
					{

						break;

					}

					if (oplistado == 1)
					{

						printf ("0.Orden descendente.\t1.Orden ascendente.\n");

						int order = (int) get_nr_bt ("Ingrese su opcion: ", 0 , 1, "El ingreso no se encuentra entre los valores válidos.");

						if (sortEmployees (list, MAX, order) == 0)
						{

							printEmployees (list, MAX);

						}

					}
					else
					{

						float salaries = sumSalary (list, MAX);

						int qEmployeeMayorSalary = amBetterSalary (list, MAX, salaries/amEmployee);

						printf ("Opción 2.\nSumatoria salario empleados: %f.2.\nPromedio de salarios: %.2f.\n", salaries, salaries/amEmployee);

						printf ("Cantidad de Empleados con salarios mayores al promedio: %d\n", qEmployeeMayorSalary);

					}

					break;

				}

			default:
			{

				printf ("La opción introducida no es correcta.\n");

			}

		}
	} while (option != 0);

	return EXIT_SUCCESS;
}
