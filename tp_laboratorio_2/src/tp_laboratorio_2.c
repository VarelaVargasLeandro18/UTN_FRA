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

	Employee list [MAX];

	initEmployees (list, MAX);

	do
	{

		printf ("------------------------------------------------------------------\n");

		printf ("Menu:\n0. SALIR\n1. ALTAS\n2. MODIFICAR.\n3. BAJA\n4. INFORMAR.\n");

		do
		{

			option = get_int ("Ingrese su opción: ");

			if (isEmpty (list, MAX) && option > 1)
			{

				printf ("Aún no se ha ingresado ningún empleado!\n");

			}

		} while (isEmpty (list, MAX) && option > 1);

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

					if (amEmployee >= MAX)
					{

						printf ("Ha excedido el número máximo de empleados.\n");

						break;

					}

					ID = calculateID (list, MAX);

					printf ("El ID del empleado es: %d.\n", ID);

					salary = get_float ("Ingrese el salario del empleado: $");

					sector = get_int ("Ingrese el sector del empleado: ");

					__fpurge(stdin);

					printf ("Ingrese el nombre del empleado: ");

					fgets (name, 51, stdin);

					__fpurge (stdin);

					printf ("Ingrese el apellido del empleado: ");

					fgets (lastName, 51, stdin);

					addEmployee (list, MAX, ID, name, lastName, salary, sector);

					amEmployee++;

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

						ID = get_int ("Ingrese el ID del empleado en cuestión: ");

					} while (isValidID(list, MAX, ID) < 0);

					__fpurge (stdin);

					printf ("Ingrese el nombre del empleado: ");

					fgets (name, 51, stdin);

					__fpurge (stdin);

					printf ("Ingrese el apellido del empleado: ");

					fgets (lastName, 51, stdin);

					salary = get_float ("Ingrese el salario del empleado: $");

					sector = get_int ("Ingrese el sector del empleado: ");

					modifyEmployee (list, Index, name, lastName, salary, sector);

					break;

				}

			case 3:
				{

					int ID = 0;

					printf ("Ha ingreso al menú de BAJA de empleados.\n");

					do
					{

						ID = get_int ("Ingrese el ID del empleado en cuestión: ");

					} while (isValidID(list, MAX, ID) < 0);

					removeEmployee (list, MAX, ID);

					break;

				}

			case 4:
				{

					//INFORMAR 1.LISTADO DE EMPLEADOS ORDENADOS ALFABETICAMENTE POR APELLIDO Y SECTOR. 2.TOTAL Y PROM SALARIOS. CANT EMPLEADOS QUE SUPERAN SALARIO PROM.

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
