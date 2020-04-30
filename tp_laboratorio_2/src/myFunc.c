#include <stdio.h>
#include <stdlib.h>

int get_int (char* msg)
{

	int usr_input;

	printf ("%s", msg);

	scanf ("%d", &usr_input);

	return usr_input;

}

float get_float (char* msg)
{

	float usr_input;

	printf ("%s", msg);

	scanf ("%f", &usr_input);

	return usr_input;

}
