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

    char BorrarLista [5];

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{

    	printMenu();

    	option = get_number( "Ingrese su opción: ", "NO ES UN NÚMERO VÁLIDO." );

        switch(option)
        {
            case 1:
            {

                printf ( "\n-----Cargando Empleados desde data.csv-----\n" );

                if ( ll_isEmpty ( listaEmpleados ) == 0 )
                {

                    printf ("\nYa hay datos cargados en la lista anteriormente. ¿Desea eliminarlos? ('s' para sí): ");

                    cleanbuffer ();

                    fscanf ( stdin, "%s", BorrarLista );

                    str_eliminate ( BorrarLista, 5, '\n' );

                    if ( BorrarLista [0] == 's' || BorrarLista [0] == 'S' )
                    {

                        ll_clear ( listaEmpleados );

                        printf ("\nDATOS BORRADOS.\n");

                    }

                }

                if ( controller_loadFromText ( "data.csv", listaEmpleados ) == TRUE )
                {

                    printf ("\nCargado Correctamente.\n\n");

                }
                else
                {
                    printf ("\nSe ha producido un error durante la carga.\n\n");
                }
                
                break;

            }

            case 2:
            {

                printf ( "\n-----Cargando Empleados desde data.bin-----\n" );

                if ( ll_isEmpty ( listaEmpleados ) == 0 )
                {

                    printf ("\nYa hay datos cargados en la lista anteriormente. ¿Desea eliminarlos? ('s' para sí): ");

                    cleanbuffer ();

                    fscanf ( stdin, "%s", BorrarLista );

                    str_eliminate ( BorrarLista, 5, '\n' );

                    if ( BorrarLista [0] == 's' || BorrarLista [0] == 'S' )
                    {

                        ll_clear ( listaEmpleados );

                        printf ("\nDATOS BORRADOS.\n");

                    }

                }

                if ( controller_loadFromBinary ( "data.bin", listaEmpleados ) == TRUE )
                {

                    printf ("\nCargado Correctamente.\n\n");

                }
                else
                {
                   
                    printf ("\nSe ha producido un error durante la carga.\n\n");
                
                }
                
                break;

            }

            case 3:
            {

                printf ("\n-----Ingresando un nuevo empleado-----\n");

                if ( controller_addEmployee ( listaEmpleados ) == TRUE )
                {

                    printf ("\nSe ha agregado el empleado correctamente.\n\n");

                }
                else
                {

                    printf ("\nSe ha producido un error.\n\n"); 
                
                }
                
                break;

            }

            case 4:
            {

                printf ("\n-----Modificar Datos de un empleado-----\n");
                if ( controller_editEmployee ( listaEmpleados ) == TRUE )
                {

                    printf ("\nSe ha editado el empleado correctamente.\n\n");

                }
                else
                {

                    printf ("\nSe ha producido un error.\n\n"); 
                
                }
                
                break;

            }

            case 5:
            {

                printf ("\n-----Dar de Baja un Empleado-----\n");
                if ( controller_removeEmployee ( listaEmpleados ) == TRUE )
                {

                    printf ("\nSe ha borrado el empleado de la lista correctamente.\n\n");

                }
                else
                {

                    printf ("\nSe ha producido un error.\n\n"); 
                
                }

                break;

            }

            case 6:
            {

                printf ("\n-----Listar Empleados-----\n");
                if ( controller_ListEmployee ( listaEmpleados ) == FALSE )
                {

                    printf ("\nSe ha producido un error.\n\n"); 

                }

                break;

            }

            case 7:
            {

                printf ("\n-----Ordenar Empleados-----\n");
                if ( controller_sortEmployee ( listaEmpleados ) == TRUE )
                {

                    printf ("\nLos empleados han sido ordenados correctamente.\n\n");

                }
                else
                {
                    
                    printf ("\nSe ha producido un error al ordenar los empleados.\n\n");

                }
                
                break;

            }

            case 8:
            {

                printf ("\n-----Guardado de datos en data.csv-----");
                if ( controller_saveAsText ( "data.csv", listaEmpleados ) == TRUE )
                {

                    printf ("\nLa lista de empleados ha sido guardada.\n\n");

                }
                else
                {
                    
                    printf ("\nSe ha producido un error al guardar los datos.\n\n");

                }
                
                break;

            }

            case 9:
            {

                printf ("\n-----Guardado de datos en data.bin-----");
                if ( controller_saveAsBinary ( "data.bin", listaEmpleados ) == TRUE )
                {

                    printf ("\nLa lista de empleados ha sido guardada.\n\n");

                }
                else
                {
                    
                    printf ("\nSe ha producido un error al guardar los datos.\n\n");
                    
                }
                
                break;

            }

            case 10:
            {

                printf ("\nHasta luego.\n\n");

                break;

            }

            default:
            {

                printf ("\nNO ES UNA OPCIÓN VÁLIDA.\n\n");

            }

        }

    } while(option != 10);

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
																					"9. Guardar los datos de los empleados en el archivo data.bin (modo binario).",
																					"10. Salir."
																									);

}
