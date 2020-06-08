#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "Controller.h"
#include "Employee.h"

//Includes personales:
#include "myIO.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText( char* path , LinkedList* pArrayListEmployee )
{

    boolean isokay = FALSE;

    FILE* pFile;

    pFile = fopen ( path, "r" );

    if ( pFile != NULL )
    {

        isokay = parser_EmployeeFromText ( pFile, pArrayListEmployee );

    }

    return isokay;

}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

    boolean isokay = FALSE;

    FILE* pFile;

    pFile = fopen ( path, "rb" );

    if ( pFile != NULL )
    {

        isokay = parser_EmployeeFromBinary ( pFile, pArrayListEmployee );

    }

    return isokay;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    boolean isokay = FALSE;

    Employee* myEmployee = employee_new();

    int AuxIdEmployee;
    char AuxnombreEmployee [128];
    int AuxHorasTrabajadasEmployee;
    int AuxSueldoEmployee;
    
    if ( myEmployee != NULL )
    {

        AuxIdEmployee = (int) get_positive_number ( "Ingrese el ID del empleado: ", "NO ES UN ID VALIDO. RECUERDE: ¡SOLO ID POSITIVOS!" );
        
        do
        {
            
            printf ("Ingrese el Nombre del Empleado: ");

            cleanbuffer ();

            fgets ( AuxnombreEmployee, 128, stdin );

            str_eliminate ( AuxnombreEmployee, 128, '\n' );

            if ( isonlyalpha ( AuxnombreEmployee ) == FALSE )
            {

                printf ("¡UN NOMBRE SOLO CONTIENE LETRAS!\n");

            }
        
        } while ( isonlyalpha ( AuxnombreEmployee ) == FALSE );

        AuxHorasTrabajadasEmployee = (int) get_positive_number ( "Ingrese la cantidad de Horas Trabajadas del empleado: ", "NO ES UN VALOR VALIDO. RECUERDE: ¡SOLO VALORES POSITIVOS!" );
        AuxSueldoEmployee = (int) get_positive_number ( "Ingrese el sueldo del empleado: $", "NO ES UN VALOR VALIDO. RECUERDE: ¡SOLO VALORES POSITIVOS!" );

        if ( 
            employee_setId ( myEmployee, AuxIdEmployee ) == TRUE && 
            employee_setNombre ( myEmployee, AuxnombreEmployee ) == TRUE &&
            employee_setHorasTrabajadas ( myEmployee, AuxHorasTrabajadasEmployee ) == TRUE &&
            employee_setSueldo ( myEmployee, AuxSueldoEmployee ) == TRUE
                                                                            )
        {

            isokay = TRUE;

            ll_add ( pArrayListEmployee, ( Employee* ) myEmployee );

        }

    }

    return isokay;
    
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{

    boolean isokay = TRUE;

    int AuxIdEmployee;
    int option;
    int notenter;

    Employee* myEmployee = NULL;

    char AuxnombreEmployee [128];
    int AuxHorasTrabajadasEmployee;
    int AuxSueldoEmployee;

    AuxIdEmployee = get_positive_number ( "Ingrese el Id del empleado que desea editar: ", "NO ES UN ID VALIDO. RECUERDE: ¡SOLO ID POSITIVOS!" );

    for ( int Index = 0; Index < ll_len ( pArrayListEmployee ); Index++ )
    {

        int LookForEmployeeId;

        Employee* Aux = ( Employee* ) ll_get ( pArrayListEmployee, Index );

        employee_getId ( Aux , &LookForEmployeeId );

        if ( AuxIdEmployee ==  LookForEmployeeId )
        {

            myEmployee = ( Employee* ) ll_get ( pArrayListEmployee, Index );

        }

    }

    if ( myEmployee != NULL )
    {

        isokay = TRUE;

        do
        {
            
            printf ( "%s\n%s\n%s\n%s\n",  "0. Salir.",
                                            "1. Nombre.",
                                            "2. HorasTrabajadas.",
                                            "3. Sueldo."                                      
                                                                    );

            option = (int) get_number ( "Ingrese su opcion: ", "Solo numeros positivos." );

            switch ( option )
            {
                case 0:
                    printf ("Hasta luego.\n");
                    break;

                case 1:
                    {
                    
                        printf ("-------Cambiar Nombre del Empleado-------\n");
                        do
                        {
                            
                            printf ("Ingrese el Nombre del Empleado: ");

                            cleanbuffer ();

                            fgets ( AuxnombreEmployee, 128, stdin );

                            str_eliminate ( AuxnombreEmployee, 128, '\n' );

                            if ( isonlyalpha ( AuxnombreEmployee ) == FALSE )
                            {

                                printf ("¡UN NOMBRE SOLO CONTIENE LETRAS!\n");

                            }
                        
                        } while ( isonlyalpha ( AuxnombreEmployee ) == FALSE );

                        isokay = employee_setNombre ( myEmployee, AuxnombreEmployee );
                    
                        break;
                    
                    }

                case 2:
                    {
                        printf ("-------Cambiar Horas Trabajadas del Empleado-------\n");
            
                        AuxHorasTrabajadasEmployee = (int) get_positive_number ( "Ingrese la cantidad de Horas Trabajadas del empleado: ", "NO ES UN VALOR VALIDO. RECUERDE: ¡SOLO VALORES POSITIVOS!" );
            
                        isokay = employee_setHorasTrabajadas ( myEmployee, AuxHorasTrabajadasEmployee );

                        break;
                    }

                case 3:
                    {
                        printf ("-------Cambiar Sueldo del Empleado-------\n");
                        
                        AuxSueldoEmployee = (int) get_positive_number ( "Ingrese el sueldo del empleado: $", "NO ES UN VALOR VALIDO. RECUERDE: ¡SOLO VALORES POSITIVOS!" );

                        isokay = employee_setSueldo ( myEmployee, AuxSueldoEmployee );

                        break;
                    }

                default:
                    printf ("OPCIÓN INCORRECTA.\n");
                    break;
            }

        } while ( option != 0 && isokay == TRUE );

    }

    return isokay;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

    boolean isokay = FALSE;

    int AuxIdEmployee;
    int EmployeeIndex;

    AuxIdEmployee = get_positive_number ( "Ingrese el Id del empleado que desea borrar: ", "NO ES UN ID VALIDO. RECUERDE: ¡SOLO ID POSITIVOS!" );

    for ( int Index = 0; Index < ll_len ( pArrayListEmployee ); Index++ )
    {

        int LookForEmployeeId;

        Employee* Aux = ( Employee* ) ll_get ( pArrayListEmployee, Index );

        employee_getId ( Aux , &LookForEmployeeId );

        if ( AuxIdEmployee ==  LookForEmployeeId )
        {

            ll_remove ( pArrayListEmployee, Index );

            isokay = TRUE;

            break;

        }

    }

    return isokay;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    boolean isokay = TRUE;

    int AuxIdEmployee;
    char AuxnombreEmployee [128];
    int AuxHorasTrabajadasEmployee;
    int AuxSueldoEmployee;

    Employee* myEmployee = NULL;

    if ( pArrayListEmployee != NULL && ll_isEmpty ( pArrayListEmployee ) == TRUE )
    {

        isokay = TRUE;

        printf ("ID\tNombre\t\t\t\tHoras Trabajadas\tSueldo\n");

        for ( int Index = 0; Index < ll_len ( pArrayListEmployee ); Index++ )
        {

            myEmployee = ll_get ( pArrayListEmployee, Index );

            if (
                employee_getId ( myEmployee, &AuxIdEmployee ) == TRUE &&
                employee_getNombre ( myEmployee, AuxnombreEmployee ) == TRUE &&
                employee_getHorasTrabajadas ( myEmployee, &AuxHorasTrabajadasEmployee ) == TRUE &&
                employee_getSueldo ( myEmployee, &AuxSueldoEmployee ) == TRUE &&
                myEmployee != NULL
                                                                        )
            {

                printf ("%-8d%-32s%-24d$%-8d\n",   
                                                AuxIdEmployee,
                                                AuxnombreEmployee,
                                                AuxHorasTrabajadasEmployee,
                                                AuxSueldoEmployee
                                                                        );

            }
            else
            {
                
                isokay = FALSE;

            }
            
        }

    }

    return isokay;

}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    boolean isokay = FALSE;

    int Order;

    do
    {
        
        printf ("%s\n%s\n",     "0. Orden Descendente.",
                                "1. Orden Ascendente."
                                                        );

        Order = (int) get_number ( "Ingrese el orden en el que se ordenarán los empleados : ", "NO ES UN VALOR VALIDO." );

        if ( Order > 1 || Order < 0 )
        {

            printf ("NO ES UN VALOR VALIDO.\n");

        }    
    
    } while ( Order > 1 || Order < 0 );

    isokay = ll_sort ( pArrayListEmployee, sort_employee, Order );    

    return isokay;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    boolean isokay = FALSE;

    Employee* myEmployee = NULL;

    int AuxIdEmployee;
    char AuxnombreEmployee [128];
    int AuxHorasTrabajadasEmployee;
    int AuxSueldoEmployee;

    FILE* pFile;

    pFile = fopen ( path, "w" );

    if ( pFile != NULL )
    {

        isokay = TRUE;

        fprintf ( pFile, "%s,%s,%s,%s\n",   "id",
                                    "nombre",
                                    "horasTrabajadas",
                                    "sueldo"
                                            );

        for ( int Index = 0; Index < ll_len ( pArrayListEmployee ); Index++ )
        {

            myEmployee = ll_get ( pArrayListEmployee, Index );

            if ( myEmployee != NULL )
            {

                employee_getId ( myEmployee, &AuxIdEmployee );
                employee_getNombre ( myEmployee, AuxnombreEmployee );
                employee_getHorasTrabajadas ( myEmployee, &AuxHorasTrabajadasEmployee );
                employee_getSueldo ( myEmployee, &AuxSueldoEmployee );

                fprintf ( pFile, "%d,%s,%d,%d\n",   AuxIdEmployee,
                                            AuxnombreEmployee,
                                            AuxHorasTrabajadasEmployee,
                                            AuxSueldoEmployee
                                                                );

            }

        }

    }

    fclose ( pFile );

    return isokay;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{

    boolean isokay = FALSE;

    FILE* pFile;

    pFile = fopen ( path, "wb" );

    if ( pFile != NULL )
    {

        for ( int Index = 0; Index < ll_len ( pArrayListEmployee ); Index++ )
        {

            if ( fwrite ( ll_get ( pArrayListEmployee, Index ), sizeof ( Employee ), 1, pFile ) == 1 )
            {

                isokay = TRUE;

            }
            else
            {
                
                isokay = FALSE;

                break;
            
            }
            
        }

    }

    fclose ( pFile );

    return isokay;
}

int sort_employee ( void* One, void* Two )
{

    int toreturn;

    if ( One != NULL && Two != NULL )
    {

        if ( strcmp ( ( ( Employee* ) One )->nombre, ( (Employee*) Two )->nombre ) > 0 )
        {

            toreturn = 1;
        
        }

        if ( strcmp ( ( ( Employee* ) One )->nombre, ( (Employee*) Two )->nombre ) < 0 )
        {

            toreturn = -1;

        }

    }    

    return toreturn;

}