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
#include "ArrayEmployees.h"

int main(void) {

	//int amEmployees = 0;
	int valID = 1;

	Employee list [MAX];

	printf ("%d\n", initEmployees (list, MAX));

	char name [] = "A";

	char lastname [] = "Z";

	for (int Count = valID - 1; Count < MAX; Count++)
	{

		name [0]++;

		addEmployee (list, MAX, valID, lastname, name, 100000.5, 5);

		valID++;

	}

	printEmployees (list, MAX);

	removeEmployee (list, MAX, 5);

	sortEmployees (list, MAX, UP);

	printEmployees (list, MAX);

	sortEmployees (list, MAX, DOWN);

	printEmployees (list, MAX);


	return EXIT_SUCCESS;
}
