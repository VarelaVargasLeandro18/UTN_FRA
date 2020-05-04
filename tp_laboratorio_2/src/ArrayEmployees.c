#include <stdio.h>
#include <string.h>
#include "ArrayEmployees.h"

int initEmployees (Employee* list, int len)
{

	if (list == NULL || len > MAX)
	{

		return -1;

	}

	for (int iterator = 0; iterator < len; iterator++)
	{

		list[iterator].isEmpty = TRUE;


		list[iterator].id = 0;

	}

	return 0;

}

int findFreeEmployee (Employee* list, int len)
{

	if (len > MAX || list == NULL)
	{

		return -1;

	}

	for (int Index = 0; Index < len; Index++)
	{

		if (list[Index].isEmpty == TRUE)
		{

			return Index;

		}

	}

	return -1;

}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

	if (list == NULL || len > MAX)
	{

		return -1;

	}

	int Index = findFreeEmployee (list, len);

	if (Index == -1)
	{

		return -1;

	}

	// Paso los valores entregados por el usuario al nuevo empleado.
	list[Index].id = id;
	strcpy (list[Index].name, name);
	strcpy (list[Index].lastname, lastName);
	list[Index].salary = salary;
	list[Index].sector = sector;
	list[Index].isEmpty = FALSE;

	return 0;

}

int findEmployeeById(Employee* list, int len, int id)
{

	if (len > MAX || list == NULL)
	{

		return -1;

	}

	for (int Index = 0; Index < len; Index++)
	{

		if (list[Index].id == id  && list[Index].isEmpty == FALSE)
		{

			return Index;

		}

	}

	return -1;

}

int removeEmployee(Employee* list, int len, int id)
{

	if (len > MAX || list == NULL)
	{

		return -1;

	}

	int Index = findEmployeeById (list, len, id);

	if (Index == -1)
	{

		return -1;

	}

	list[Index].isEmpty = TRUE;

	return 0;

}

void swapEmployee (Employee* one, Employee* two)
{

	Employee Aux = *one;
	*one = *two;
	*two = Aux;

}

int sortEmployees(Employee* list, int len, int order)
{

	if (len > MAX || list == NULL)
	{

		return -1;

	}

	order = (order == UP) ? 1 : -1;

	for (int Index = 0; Index < len - 1; Index++)
	{

		for (int j = Index + 1; j < len; j++)
		{

			int comparison = strcmp (list[Index].lastname, list[j].lastname);

			if (comparison == 0)
			{

				comparison = (list[Index].sector > list[j].sector) ? 1 : -1;

			}

			if (comparison == order)
			{

				swapEmployee (&list[Index], &list[j]);

			}

		}

	}

	return 0;

}

int printEmployees(Employee* list, int length)
{

	int AmDisplayed = 0;

	if (list == NULL || length > MAX)
	{

		return -1;

	}

	for (int Index = 0; Index < length; Index++)
	{

		if (list[Index].isEmpty == FALSE)
		{

			printf ("-------------------------------------------------------------------");
			printf ("\nID: %d\nNombre: %s\nApellido: %s\n", list[Index].id, list[Index].name, list[Index].lastname);
			printf ("Salario: %.2f\nSector: %d\n", list[Index].salary, list[Index].sector);
			AmDisplayed++;

		}

	}

	printf ("-------------------------------------------------------------------\n");

	return AmDisplayed;

}

int calculateID (Employee* list, int len)
{

	/*
	if (list == NULL || len > MAX)
	{

		return -1;

	}

	int ID = 1;
	int Index = findFreeEmployee (list, len);

	if (Index == -1)
	{

		return -1;

	}
	else if (list[Index].id != 0)
	{

		ID = list[Index].id;

	}
	else
	{

		for (Index = 0; Index < len; Index++)
		{

			if (list[Index].id == ID)
			{

				ID++;

			}

		}

	}

	return ID;
	*/

	int MaxID = 0;

	for (int Iterator = 0; Iterator < len; Iterator++)
	{

		if (list[Iterator].id > MaxID)
		{

			MaxID = list[Iterator].id;

		}

	}

	int Devolver = MaxID + 1;

	return Devolver;

}

void modifyEmployee (Employee* list, int Index, char name[],char lastName[],float salary,int sector)
{

	strcpy (list[Index].name, name);
	strcpy (list[Index].lastname, lastName);
	list[Index].salary = salary;
	list[Index].sector = sector;

}

int isValidID (Employee* list, int len, int ID)
{

	int Index;

	if (ID < 0)
	{

		printf ("No es un ID válido.\n");

		return -1;

	}
	else
	{

		Index = findEmployeeById (list, MAX, ID);
		if (Index == -1)
		{

			printf ("No existe ese Empleado!\n");

			return -1;

		}

	}

	return 0;

}

int isEmpty (Employee* list, int len)
{

	for (int Index = 0; Index < len; Index++)
	{

		if (list[Index].isEmpty == FALSE)
		{

			return 0;
		}

	}

	return -1;

}

float sumSalary (Employee* list, int len)
{

	float promSalary = 0;

	for (int Iterator = 0; Iterator < len; Iterator++)
	{

		promSalary += list[Iterator].salary;

	}

	return promSalary;

}

int amBetterSalary (Employee* list, int len, float value)
{

	int amount = 0;

	for (int Iterator = 0; Iterator < len; Iterator++)
	{

		if (list[Iterator].salary > value)
		{

			amount++;

		}

	}

	return amount;

}
