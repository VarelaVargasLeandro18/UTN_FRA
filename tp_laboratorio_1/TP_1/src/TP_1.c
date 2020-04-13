/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include "calculos.h"

int main(void)
{

	float OperandoUno = 0.00;
	float OperandoDos = 0.00;
	int Opcion = 0;
	float v_Suma = 0.00;
	float v_Resta = 0.00;
	float v_Multiplicacion = 0.00;
	float v_Division = 0.00;
	long long int v_Factorial = 0.00;

	do
	{

		if ( Opcion == 4 || Opcion == 0)
		{

			Imprimir_Menu (OperandoUno, OperandoDos);

		}

		printf ("Ingrese Opcion: ");

		scanf ("%d", &Opcion);

		switch (Opcion)
		{

			case 1:
			{

				printf ("Ingrese valor del Operando Uno: ");

				scanf ("%f", &OperandoUno);

				break;

			}

			case 2:
			{

				printf ("Ingrese valor del Operando Dos: ");

				scanf ("%f", &OperandoDos);

				break;

			}

			case 3:
			{

				printf ("Calculando...\n");

				v_Suma = Suma (OperandoUno, OperandoDos);

				v_Resta = Resta (OperandoUno, OperandoDos);

				v_Division = Division (OperandoUno, OperandoDos);

				v_Multiplicacion = Multiplicacion (OperandoUno, OperandoDos);

				v_Factorial = Factorial (OperandoUno);

				printf ("Terminado.\n");

				break;

			}

			case 4:
			{

				printf ("Resultado de las Operaciones:\n");

				printf ("Suma: %.2f\n", v_Suma);

				printf ("Resta: %.2f\n", v_Resta);

				if (OperandoDos == 0 && OperandoUno == 0)
				{

					printf ("División: INDETERMINACIÓN.\n");

				}
				else if (OperandoDos == 0)
				{

					printf ("División: INFINITO.\n");

				}
				else
				{

					printf ("División: %.2f\n", v_Division);

				}

				printf ("Multiplicación: %.2f\n", v_Multiplicacion);

				printf ("Factorial de %d: %lld\n", Float_a_Int (OperandoUno), v_Factorial);

				printf ("Presione una tecla y enter para continuar...");

				char continuar;

				__fpurge (stdin);

				scanf ("%c", &continuar);

				break;

			}

			case 5:
			{

				printf ("Saliendo...");

				break;

			}

			default:
			{

				printf ("Opción Invalida.\n");

			}

		}

	} while (Opcion != 5);

}
