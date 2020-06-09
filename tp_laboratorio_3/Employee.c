#include "Employee.h"
#include "myIO.h"
#include <string.h>
#include <stdlib.h>

/** \brief Crear un nuevo empleado vacío.
 *  \return Employee* -> Puntero al empleado creado.
 */
Employee* employee_new()
{

    Employee* new = ( Employee* ) malloc ( 1 * sizeof ( Employee ) );

    return new;

}

/** \brief Crear un nuevo empleado con ciertos valores ingresados.
 *  \param idStr char* -> id del empleado.
 *  \param nombreStr char* -> nombre del empleado.
 *  \param horasTrabajadasStr char* -> Horas Trabajadas del empleado.
 *  \return Employee* -> Devuelve un empleado con los datos cargados.
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    
    Employee* new = employee_new();
    
    if ( new != NULL && isonlyanum ( idStr ) == TRUE && isonlyanum ( horasTrabajadasStr ) && isonlyalpha (nombreStr) )
    {
        
        new->id = atoi ( idStr );
        
        strcpy ( new->nombre, nombreStr );
        
        new->horasTrabajadas = atoi ( horasTrabajadasStr );
        
    }
    else
    {
        
        new = NULL;
        
    }
    
    return new;
    
}

/** \brief Borrar un empleado,
 *  \param this Employee* 
 *  \return void
 */
void employee_delete(Employee* this)
{
    
    free (this);
    
}

/** \brief Establecer un ID a un empleado.
 *  \param this Employee* 
 *  \param id int 
 *  \return int -> devuelve -1 si algo salió mal.
 */
int employee_setId(Employee* this,int id)
{
    
    boolean isokay = FALSE;
    
    if ( this != NULL && id > 0 )
    {
        
        this->id = id;
        
        isokay = TRUE;
        
    }
    
    return isokay;
    
}

/** \brief Obtener el ID de un empleado.
 *  \param this Employee* 
 *  \param id int* 
 *  \return int -> devuelve -1 si algo salió mal.
 */
int employee_getId(Employee* this,int* id)
{
    
    boolean isokay = FALSE;
    
    if ( this != NULL && id != NULL )
    {
        
        isokay = TRUE;
        
        *id = this->id;
        
    }
    
    return isokay;
    
}

/** \brief Establece el nombre de un empleado.
 *  \param this Employee* 
 *  \param nombre char* 
 *  \return int -> devuelve -1 si algo salió mal.
 */
int employee_setNombre(Employee* this, char* nombre)
{
    
    boolean isokay = FALSE;
    
    if ( this != NULL && nombre != NULL && isonlyalpha (nombre) == TRUE )
    {
        
        isokay = TRUE;
        
        strcpy ( this->nombre, nombre );
        
    }
    
    return isokay;
    
}

/** \brief Obtener el nombre de un empleado
 *  \param this Employee* 
 *  \param nombre char* 
 *  \return int -> devuelve -1 si algo salió mal.
 */
int employee_getNombre(Employee* this,char* nombre)
{
    
    boolean isokay = FALSE;
    
    if ( this != NULL && nombre != NULL )
    {
        
        isokay = TRUE;
        
        strcpy ( nombre, this->nombre );
        
    }
    
    return isokay;
    
}


/** \brief Establece las Horas Trabajadas de un empleado.
 *  \param this Employee* 
 *  \param horasTrabajadas int 
 *  \return int -> devuelve -1 si algo salió mal.
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    
    boolean isokay = FALSE;
    
    if ( this != NULL )
    {
        
        isokay = TRUE;
        
        this->horasTrabajadas = horasTrabajadas;
        
    }
    
    return isokay;
    
}

/** \brief Obtener las Horas Trabajadas de un empleado.
 *  \param this Employee*
 *  \param horasTrabajadas int* 
 *  \return int -> devuelve -1 si algo salió mal.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    
    boolean isokay = FALSE;
    
    if ( this != NULL && horasTrabajadas != NULL )
    {
        
        isokay = TRUE;
        
        *horasTrabajadas = this->horasTrabajadas;
        
    }
    
    return isokay;
    
}


/** \brief Establecer el sueldo de un empleado.
 *  \param this Employee* 
 *  \param sueldo int 
 *  \return int -> devuelve -1 si algo salió mal.
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    
    boolean isokay = FALSE;
    
    if ( this != NULL )
    {
        
        isokay = TRUE;
        
        this->sueldo = sueldo;
        
    }
    
    return isokay;
    
}

/** \brief Obtener el sueldo de un empleado.
 *  \param this Employee* 
 *  \param sueldo int* 
 *  \return int -> devuelve -1 si algo salió mal.
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    
    boolean isokay = FALSE;
    
    if ( this != NULL && sueldo != NULL )
    {
        
        isokay = TRUE;
        
        *sueldo = this->sueldo;
        
    }
    
    return isokay;
    
}

int employee_comparebyName ( void* One, void* Two )
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

int employee_comparebyID ( void* One, void* Two )
{

    int toreturn;

    if ( One != NULL && Two != NULL )
    {

        if ( ( ( Employee* ) One )->id > ( ( Employee* ) Two )->id  )
        {

            toreturn = 1;
        
        }

        if ( ( ( Employee* ) One )->id < ( ( Employee* ) Two )->id  )
        {

            toreturn = -1;

        }

    }    

    return toreturn;

}

int employee_comparebyhorasTrabajadas ( void* One, void* Two )
{

    int toreturn;

    if ( One != NULL && Two != NULL )
    {

        if ( ( ( Employee* ) One )->horasTrabajadas > ( ( Employee* ) Two )->horasTrabajadas  )
        {

            toreturn = 1;
        
        }

        if ( ( ( Employee* ) One )->horasTrabajadas < ( ( Employee* ) Two )->horasTrabajadas  )
        {

            toreturn = -1;

        }

    }    

    return toreturn;

}

int employee_comparebysueldo ( void* One, void* Two )
{

    int toreturn;

    if ( One != NULL && Two != NULL )
    {

        if ( ( ( Employee* ) One )->sueldo > ( ( Employee* ) Two )->sueldo  )
        {

            toreturn = 1;
        
        }

        if ( ( ( Employee* ) One )->sueldo < ( ( Employee* ) Two )->sueldo  )
        {

            toreturn = -1;

        }

    }    

    return toreturn;

}