#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include "ArrayEmployees.h"
#include "myFunc.h"

int main(void) {

	//Creamos las variables:
	int option;
	int correcto;
	int ID;
	int amEmployee = 0; // Contador de Empleados.
	int Index;
	int order;
	int qEmployeeMayorSalary;
	float salaries;
	char hardcodear;

	//Creamos la lista de employees:
	Employee list [MAX];
	//Employee Auxiliar para ingresar los datos:
	Employee Aux;

	//Inicializamos los employees
	initEmployees (list, MAX);

	printf ("¿Desea utilizar algunos valores de prueba ingresados manualmente? ('s' para sí, cualquier otro valor será no): ");

	scanf ("%c", &hardcodear);

	if (hardcodear == 's')
	{

		amEmployee = HardcodeEmployees (list);

		printf ("HARDCODE REALIZADO!!\n");

	}

	do
	{

		printf ("------------------------------------------------------------------\n");

		printf ("Menu:\n0. SALIR\n1. ALTAS\n2. MODIFICAR.\n3. BAJA\n4. INFORMAR.\n");

		option = get_option (1, 4, amEmployee);

		switch (option)
		{

			case 0:
				{

					printf ("Ha decidido salir del menú. Hasta Luego.\n");

					break;

				}

			case 1:
				{

					printf ("Ha ingresado al menú de ALTAS de empleados.\n");

					ID = calculateID (list, MAX);

					printf ("El ID del empleado es: %d.\n", ID);

					Aux = enterEmployee();

					correcto = addEmployee (list, MAX, ID, Aux.name, Aux.lastname, Aux.salary, Aux.sector);

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

					printEmployees (list, MAX);

					do
					{

						ID = (int)get_number ("Ingrese el ID del empleado en cuestión: ");

					} while (isValidID(list, MAX, ID) < 0);

					Index = findEmployeeById (list, MAX, ID);

					Aux = enterEmployee();

					modifyEmployee (list, Index, Aux.name, Aux.lastname, Aux.salary, Aux.sector);

					printf ("Se ha modificado el empleado correctamente.\n");

					break;

				}

			case 3:
				{

					printf ("Ha ingreso al menú de BAJA de empleados.\n");

					printEmployees (list, MAX);

					do
					{

						ID = (int)get_number ("Ingrese el ID del empleado en cuestión: ");

					} while (isValidID(list, MAX, ID) < 0);

					removeEmployee (list, MAX, ID);

					amEmployee--;

					printf ("Ha dado de baja al empleado correctamente.\n");

					break;

				}

			case 4:
				{

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

						order = (int) get_nr_bt ("Ingrese su opcion: ", 0 , 1, "El ingreso no se encuentra entre los valores válidos.");

						if (sortEmployees (list, MAX, order) == 0)
						{

							printEmployees (list, MAX);

						}

					}
					else
					{

						salaries = sumSalary (list, MAX);

						qEmployeeMayorSalary = amBetterSalary (list, MAX, salaries/amEmployee);

						printf ("Opción 2.\nSumatoria salario empleados: $%.2f\nPromedio de salarios: $%.2f\n", salaries, salaries/amEmployee);

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
