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

int get_option (int minor, int Mayor, int amEmployee)
{

	int option;

	do
	{

		option = (int)get_number ("Ingrese su opción: ");

		if ( amEmployee == 0 && (option > minor && option <= Mayor) )
		{

			printf ("Aún no se ha ingresado ningún empleado!\n");

		}

	} while ( amEmployee == 0 && (option > minor && option <= Mayor) );

	return option;

}

void str_eliminate (char str[], int len, char chara)
{

	for (int Iterator = 0; Iterator < len; Iterator++)
	{

		if ( str[Iterator] == chara )
		{

			str[Iterator] = '\0';

		}

	}

}
