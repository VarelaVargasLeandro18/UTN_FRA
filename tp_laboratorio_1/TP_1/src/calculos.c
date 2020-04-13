#include <stdio.h>

int Float_a_Int (float Convertir)
{

	int Auxiliar = 0;

	Auxiliar = (int)(Convertir * 10)-(int) Convertir * 10;

	if (Auxiliar > 4)
	{

		return (int)Convertir + 1;

	}
	else
	{

		return (int)Convertir;

	}

}

float Suma (float uno, float dos)
{

	float resultado = 0;

	resultado = uno + dos;

	return resultado;

}

float Resta (float uno, float dos)
{

	float resultado = 0;

	resultado = uno - dos;

	return resultado;

}

float Multiplicacion (float uno, float dos)
{

	float resultado = 0;

	resultado = uno * dos;

	return resultado;

}

float Division (float uno, float dos)
{

	float resultado = 0;

	if (dos == 0)
	{

		printf ("\nATENCIÓN DIVIDIENDO POR CERO!!\n");

		return 0;

	}

	resultado = uno / dos;

	return resultado;

}

long long int Factorial (float operando)
{

	int resultado = 0;

	resultado = Float_a_Int (operando);

	for (int fact_cont = operando; fact_cont > 0; fact_cont--)
	{

		resultado *= fact_cont;

	}

	return resultado;

}

void Imprimir_Menu (float uno, float dos)
{

	/* En caso de preferirlo descomentar alguna de las siguientes funciones para limpiar la pantalla.
	 * Preferí no hacerlo ya que tengo entendido que no son un estándar y no se consideran como una práctica recomendada.

	system ("clear");
	system ("cls");

	 */

	printf ("Valor de A: %.2f\n", uno);

	printf ("Valor de B: %.2f\n", dos);

	printf ("Opciones:\n");

	printf ("1. Ingresar primer operando.\n2.Ingresar segundo operando.\nEl valor por defecto de los mismos será 0.\n");

	printf ("3.Realizar todas las operaciones disponibles:\na) Suma (A + B).\nb) Resta (A - B).\nc) División (A / D).\nd) Multiplicación (A * B).\ne) Factorial (A!)\n");

	printf ("Ingresar: ");

}
