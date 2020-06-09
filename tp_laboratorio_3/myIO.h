#ifndef myIO_H_INCLUDED
#define myIO_H_INCLUDED
typedef enum boolean { FALSE = -1, TRUE } boolean;

/** \brief Comprueba si una cadena de caracteres corresponde a un formato tipo float.
 *  \param char* mystr
 *  \return int -> Devuelve -1 si es falso.
 */ 
int isonlyanum ( char* mystr );

/** \brief Comprueba si una cadena de caracteres contiene unicamente caracteres alfabéticos.
 *  \param char* mystr
 *  \return -> Devuelve -1 si es falso
 */
int isonlyalpha ( char* mystr );

/** \brief Pide un número hasta que se ingrese el número requerido.
 *  \param char* msg -> Mensaje a mostrar a la hora de pedir un número.
 *  \param char* errormsg -> Mensaje a mostrar en caso de que haya un error.
 *  \return float -> Devuelve el número ingresado.
 */ 
float get_number ( char* msg, char* errormsg );

/** \brief Pide un número positivo hasta que se ingrese el número requerido.
 *  \param char* msg -> Mensaje a mostrar a la hora de pedir un número.
 *  \param char* errormsg -> Mensaje a mostrar en caso de que haya un error.
 *  \return float -> Devuelve el número ingresado.
 */
float get_positive_number ( char* msg, char* errormsg );

/** \brief Pide un número al usuario y si hay un error le pregunta si desea seguir ingresándolo.
 *  \param msg char* -> Mensaje a mostrar a la hora de pedir un número.
 *  \param erromsg char* -> Mensaje a mostrar en caso de que haya un error.
 *  \param ask char* -> Mensaje a mostrar para preguntarle al usuario si desea volver a ingresar otro número.
 *  \param value char* -> Valor a comparar para saber si el usuario desea seguir ingresando.
 *  \param notenteragain int* -> Variable donde se almacenará si el usuario quizo seguir ingresando. -1 si el usuario ingresó igualmente, 1 si no deseó seguir ingresando.
 *  \return float -> Devuelve el número ingresado.
 */
float ask_get_number ( char* msg, char* errormsg, char* ask, char* value, int* notenteragain );

/** \brief Elimina un caracter en un String y los siguientes.
 *  \param str char* -> to search for the character.
 *  \param chara char -> character to remove.
 *  \return void
 */
void str_eliminate (char str[], int len, char chara);

/** \brief Limpia el buffer de entrada.
 *  \param void
 *  \return void
 */
void cleanbuffer ();

#endif // myIO_H_INCLUDED