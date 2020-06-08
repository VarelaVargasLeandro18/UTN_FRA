#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

//Includes personales:
#include "myIO.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    boolean isokay = FALSE;

    Employee* myEmployee = NULL;

    char Auxid [30];
    char AuxNombre [128];
    char AuxHorasTrabajadas [30];
    char AuxSueldo [30];
    char buffer [128];
    
    if ( pFile != NULL && pArrayListEmployee != NULL )
    {

        fscanf( pFile, "%*[^,],%*[^,],%*[^,],%*[^\n]\n" );
    
        int qread = 0;

        while ( !feof ( pFile ) )
        {

            qread = fscanf ( pFile, "%[^,],%[^,],%[^,],%[^\n]\n", Auxid, AuxNombre, AuxHorasTrabajadas, AuxSueldo );

            if ( qread == 4 && isonlyanum ( Auxid ) == TRUE && isonlyalpha ( AuxNombre ) == TRUE && isonlyanum ( AuxHorasTrabajadas ) == TRUE && isonlyanum ( AuxSueldo ) == TRUE )
            {

                myEmployee = employee_new ();

                if ( myEmployee != NULL )
                {

                    myEmployee->id = atoi ( Auxid );

                    strcpy ( myEmployee->nombre, AuxNombre );

                    myEmployee->horasTrabajadas = atoi ( AuxHorasTrabajadas );

                    myEmployee->sueldo = atoi ( AuxSueldo );

                    if ( ll_add ( pArrayListEmployee , myEmployee ) == TRUE )
                    {

                        isokay = TRUE;

                    }
                    else
                    {
                        
                        isokay = FALSE;

                        break;

                    }
                    
                }
                else
                {

                    isokay = FALSE;

                    break;
                    
                }
                
            }
            
        }

    }

    fclose ( pFile );
        
    return isokay;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    boolean isokay = FALSE;

    Employee* myEmployee = NULL;

    if ( pFile != NULL && pArrayListEmployee != NULL )
    {

        while ( !feof ( pFile ) )
        {

            myEmployee = employee_new ();

            if ( myEmployee != NULL )
            {

                if ( fread ( myEmployee, sizeof ( Employee ), 1, pFile ) == 1 )
                {

                    if ( ll_add ( pArrayListEmployee, myEmployee ) == TRUE )
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
