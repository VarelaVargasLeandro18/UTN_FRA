#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

//Includes personales:
#include "myIO.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

void printMenu ();

int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
////////////////////////////////////////////////////////
    //int controller_loadFromText( char* path , LinkedList* pArrayListEmployee )

    if ( controller_addEmployee ( listaEmpleados ) == TRUE )
    {

        printf ("H");

    }
    else
    {
        printf ("G");
    }
    
    if ( controller_ListEmployee ( listaEmpleados ) == TRUE )
    {

        printf ("L\n");

    }

    if ( controller_removeEmployee ( listaEmpleados ) == TRUE)
    {

        controller_ListEmployee ( listaEmpleados );

    }
    
    ll_deleteLinkedList ( listaEmpleados );

////////////////////////////////////////////////////////
    /*do{

    	printMenu();

    	option = get_number("", " ");

    	printf ("Ingrese: ");



    	switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;


        }

    } while(option != 10);*/

    return 0;
}

void printMenu ()
{

	printf ("%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n\t%s\n", 	"Menu",
																					"1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).",
																					"2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).",
																					"3. Alta de empleado.",
																					"4. Modificar datos de empleado.",
																					"5. Baja de empleado.",
																					"6. Listar empleados.",
																					"7. Ordenar empleados.",
																					"8. Guardar los datos de los empleados en el archivo data.csv (modo texto).",
																					"9. Guardar los datos de los empleados en el archivo data.csv (modo binario).",
																					"10. Salir."
																									);

}
