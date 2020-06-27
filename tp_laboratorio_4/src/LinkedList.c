#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = ( LinkedList* ) malloc ( 1 * sizeof ( LinkedList ) );

    if ( this != NULL )
    {

    	this->pFirstNode = NULL;
        this->size = 0;

    }

    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if ( this != NULL )
    {

    	returnAux = this->size;

    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{

	int Index = 0;
	Node* pmyNode = NULL;

	if ( this != NULL && nodeIndex >= 0 && ll_len ( this ) > nodeIndex )
	{

		pmyNode = this->pFirstNode;
		Index++;

		while ( nodeIndex >= Index && pmyNode->pNextNode != NULL )
		{

			Index++;
			pmyNode = pmyNode->pNextNode;

		}

	}

    return pmyNode;

}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pnewNode = NULL;
    Node* pprevNode = NULL;
    Node* pnextNode = NULL;

    if ( this != NULL && nodeIndex >= 0 && ll_len ( this ) >= nodeIndex )
    {

    	pnewNode = ( Node* ) malloc ( 1 * sizeof ( Node ) );

    	pnewNode->pElement = pElement;

    	pnextNode = getNode ( this, nodeIndex );
    	// El nuevo nodo tomará la posicion 'nodeIndex', por consiguiente el elemento que esté allí será el siguiente al nuevo nodo.

    	pnewNode->pNextNode = pnextNode;
    	// getNode devuelve nulo si en la posicion requerida supera al largo de la lista, por consiguiente no precisa una verifición.

    	if ( nodeIndex == 0 )
    	{

    		this->pFirstNode = pnewNode;

    	}
    	else
    	{

    		pprevNode = getNode ( this, ( nodeIndex - 1 ) );
    		pprevNode->pNextNode = pnewNode;

    	}

    	this->size += 1;
    	returnAux = 0;

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if ( this != NULL )
    {

    	if ( addNode ( this, ll_len ( this ), pElement ) == 0 )
    	{

    		returnAux = 0;

    	}

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pmyNode = NULL;

    if ( this != NULL )
    {

    	pmyNode = getNode ( this, index );

    	if ( pmyNode != NULL )
    	{

    		returnAux = pmyNode->pElement;

    	}

    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pmyNode = NULL;

	if ( this != NULL )
	{

		pmyNode = getNode ( this, index );

		if ( pmyNode != NULL )
		{

			pmyNode->pElement = pElement;

			returnAux = 0;

		}

	}

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{

	int returnAux = -1;
	Node* pmyNode = NULL;
    Node* pnextNode = NULL;
    Node* pprevNode = NULL;

	if ( this != NULL && index < ll_len ( this ) )
	{

		if ( index == 0 )
		{

			pnextNode = getNode ( this, ( index + 1 ) );
			this->pFirstNode = pnextNode;
			returnAux = 0;

		}
		else
		{

			pnextNode = getNode ( this, ( index + 1 ) );
			pmyNode = getNode ( this, index );
			pprevNode = getNode ( this, ( index - 1 ) );

			if ( pmyNode != NULL && pprevNode != NULL )
			{

				pprevNode->pNextNode = pnextNode;
				returnAux = 0;

			}

		}

		this->size -= 1;

	}

    return returnAux;

}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    if ( this != NULL )
    {

    	this->pFirstNode = NULL;
    	this->size = 0;
    	returnAux = 0;

    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if ( this != NULL )
    {

    	free ( this );
    	returnAux = 0;

    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int Index = 0;
    void* pAuxElement = NULL;

    if ( this != NULL )
    {

    	while ( ll_len ( this ) > Index )
    	{

			pAuxElement = ll_get ( this, Index );

    		if ( pElement == pAuxElement )
    		{

    			returnAux = Index;
    			break;

    		}

    		Index++;

    	}

    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if ( this != NULL )
    {

    	if ( this->size == 0 && this->pFirstNode == NULL )
    	{

    		returnAux = 1;

    	}
    	else
    	{

    		returnAux = 0;

    	}

    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    returnAux = addNode ( this, index, pElement );
    //add_Node realiza todas las comprobaciones necesarias: this!=NULL, index < this->size y index >= 0

    return returnAux;

}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if ( this != NULL )
    {

    	returnAux = ll_get ( this, index );

        if ( returnAux != NULL )
        {

        	ll_remove ( this, index );

        }

    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if ( this != NULL  )
    {

    	if ( ll_indexOf ( this, pElement ) >= 0 )
    	{

    		returnAux = 1;

    	}
    	else
    	{

    		returnAux = 0;

    	}

    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{

	int returnAux = -1;

    int CountOkay = 0;
    int len2;

    if ( this != NULL && this2 != NULL )
    {

    	returnAux = 0;

    	len2 = ll_len ( this2 );

    	for ( int Index = 0; Index < ll_len ( this ); Index++ )
    	{

    		if ( ll_contains ( this2, ll_get ( this, Index ) ) == 1 )
    		{

    			CountOkay++;

    		}

    		if ( CountOkay == len2 )
    		{

    			returnAux = 1;
    			break;

    		}

    	}

    }

    return returnAux;

}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* subList = NULL;

    if ( this != NULL && from >=0 && from < ll_len ( this ) && to <= ll_len ( this ) && to > from )
    {

    	subList = ll_newLinkedList ();

    	if ( subList != NULL )
    	{

    		for ( int Index = from; Index < to; Index++  )
			{

				ll_add ( subList, ll_get ( this, Index ) );

			}

    	}

    }

    return subList;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* clonedList = NULL;

    clonedList = ll_subList ( this, 0, ll_len ( this ) );
    // ll_subList ya realiza las comprobaciones necesarias.

    return clonedList;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;

    int AuxOrder;
    int pFuncreturn;
    void* pElementfirst = NULL;
    void* pElementsecond = NULL;
    int Index;
    int Index2;

    if ( this != NULL && pFunc != NULL && ( ( order == 0 ) || ( order == 1 ) ) )
    {

    	AuxOrder = ( order == 0 ) ? -1 : 1;
    	returnAux = 0;

    	for ( Index = 0; Index < ( ll_len ( this ) ); Index++ )
    	{

    		for ( Index2 =  ( Index + 1 ); Index2 < ( ll_len ( this ) ); Index2++ )
    		{

    			pElementfirst = ll_get ( this, Index );
    			pElementsecond = ll_get ( this, Index2 );

    			pFuncreturn = pFunc ( ll_get ( this, Index ), ll_get ( this, Index2 ) );

    			if ( pFuncreturn == AuxOrder )
    			{

    				// Swap
    				ll_remove ( this, Index ); // Remuevo el primer elemento.
    				ll_push ( this, ( Index2 - 1 ), pElementfirst ); // Lo coloco en el lugar del segundo elemento.
    				ll_remove ( this, Index2 ); // Remuevo el segundo elemento.
    				ll_push ( this, Index, pElementsecond ); // Lo coloco en el lugar anterior del primero.

    			}

    		}

    	}

    }

    return returnAux;

}

