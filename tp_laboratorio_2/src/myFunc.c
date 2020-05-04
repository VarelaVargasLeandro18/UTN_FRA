#include <stdio.h>
#include <stdlib.h>

float get_nr_bt (char* msg, float less, float mayor, char* al_msg)
{

	float input;

	do
	{

		printf ("%s", msg);

		scanf ("%f", &input);

		if (input < less || input > mayor)
		{

			printf ("%s\n", al_msg);

		}

	} while (input < less || input > mayor);

	return input;

}

float get_number (char* msg)
{

	float usr_input;

	printf ("%s", msg);

	scanf ("%f", &usr_input);

	return usr_input;

}
