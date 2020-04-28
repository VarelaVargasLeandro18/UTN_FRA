// Definitions
#define MAX 15
#define TRUE 1
#define FALSE 0
#define UP 1
#define DOWN 0

//Struct type definition
struct
{

	int id;
	char name [51];
	char lastname [51];
	float salary;
	int sector;
	int isEmpty;

} typedef Employee;


/** \brief To indicate that all position in the array are empty, this function put the flag (isEmpty) in TRUE in all position of the array
* 	\param list Employee* Pointer to array of employees
* 	\param len int Array length
* 	\return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int initEmployees (Employee* list, int len);

/* (Personal Function)
 * \brief Find a Free place in employee list.
 * \param list Employee* Pointer to array of employees.
 * \param len int.
 * \return int Index where the first free place was found. -1 if there's no free place.
 */
int findFreeEmployee (Employee* list, int len);

/** \brief add in a existing list of employees the values received as parameters in the first empty position
* 	\param list employee*
* 	\param len int
* 	\param id int
* 	\param name[] char
* 	\param lastName[] char
* 	\param salary float
* 	\param sector int
* 	\return int Return (-1) if Error [Invalid length or NULL pointer or without	free space] - (0) if Ok
*/
int addEmployee (Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id and returns the index position in array.
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
*/
int findEmployeeById (Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*	\param list Employee*
*	\param len int
*	\param id int
*	\return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
*/
int removeEmployee (Employee* list, int len, int id);

/* Personal Function
 * \brief Swap two variables each other.
 * \param Employee* one Pointer to the first variable. The values stored in it will be stored in the second variable.
 * \param Employee* two Pointer to the second variable. The values stored in it will be stored in the first variable.
 * return void
 */
void swapEmployee (Employee* one, Employee* two);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortEmployees (Employee* list, int len, int order);

/** \brief print the content of employees array
* \param list Employee*
* \param length int
* \return int Amount of Employees displayed.
*/
int printEmployees (Employee* list, int length);

/* (Personal Function)
 * \brief Calculate a new and unused ID for an Employee.
 * \param list Employee*
 * \param len int
 * \return int new ID calculated. -1 if there is no place for another Employee or if list is NULL.
 */
int calculateID (Employee* list, int len);
