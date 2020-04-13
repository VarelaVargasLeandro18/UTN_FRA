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
#include <stdlib.h>
#include "calculos.h"

int main(void) {

	float OperandoUno = 0.00;
	float OperandoDos = 0.00;

	Imprimir_Menu (OperandoUno, OperandoDos);

	scanf ("%f", &OperandoUno);

	scanf ("%f", &OperandoDos);

	printf ("%d", Float_a_Int (OperandoUno));

	printf ("\n%.2f", Suma (OperandoUno, OperandoDos));

	printf ("\n%f", Resta (OperandoUno, OperandoDos));

	printf ("\n%f", Multiplicacion (OperandoUno, OperandoDos));

	printf ("\n%f", Division (OperandoUno, OperandoDos));

	printf ("\n%lld", Factorial (OperandoUno));


}
