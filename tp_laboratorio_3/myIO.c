#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "myIO.h"

int isonlyanum ( char* mystr )
{
    
    int PointCounter = 0;
    int Iterator = 0;
    boolean isokay = FALSE;
    
    if ( * ( mystr + Iterator ) == '-' )
    {

        Iterator++;

    }
    
    while ( *( mystr + Iterator ) != '\0'  )
    {
        
        if ( isdigit ( *(mystr + Iterator) ) != 0 )
        {
        
            Iterator++;
            
            isokay = TRUE;
        
            
        }
        else if ( ( *(mystr + Iterator) ) == '.' && PointCounter < 1 )
        {
            
            PointCounter++; 
            
            Iterator++;
            
            isokay = TRUE;
            
        }
        else
        {
         
            isokay = FALSE; 
            
            break;
        
        }
        
    }
    
    return isokay;
    
}

int isonlyalpha ( char* mystr )
{
    
    boolean isokay = FALSE;
    
    int Iterator = 0;

    while ( *( mystr + Iterator ) != '\0' )
    {
        
        if ( isalpha ( *( mystr + Iterator ) ) != 0 || *( mystr + Iterator ) == ' ' )
        {
            
            Iterator++;
            
            isokay = TRUE;
            
        }
        else
        {
            
            isokay = FALSE;
            
            break;
            
        }
        
    }
    
    return isokay;
    
}

float get_number ( char* msg, char* errormsg )
{

    char String [50];

    do
    {
        
        printf ("%s", msg);
        
        scanf ( "%s", String );
        
        if ( isonlyanum ( String ) == FALSE )
        {
            
            printf ("%s\n", errormsg);
            
        }
        
    } while ( isonlyanum ( String ) == FALSE );
    
    return ( atof (String) );

}

float get_positive_number ( char* msg, char* errormsg )
{

    char String [50];
    float myNum;

    do
    {
        
        printf ("%s", msg);
        
        scanf ( "%s", String );
        
        if ( isonlyanum ( String ) == FALSE )
        {
            
            printf ("%s\n", errormsg);
            
        }
        else
        {
            
            myNum = atof ( String );
            if ( myNum <= 0 )
            {

                printf ("%s\n", errormsg);

            }

        }
        
    } while ( isonlyanum ( String ) == FALSE || myNum <= 0 );
    
    return myNum;

}

float ask_get_number ( char* msg, char* errormsg, char* ask, char* value, int* notenteragain )
{
    
    *notenteragain = FALSE;
    char String [50];
    int keepenter = FALSE;

    do
    {
        
        printf ("%s", msg);
        
        scanf ( "%s", String );
        
        if ( isonlyanum ( String ) == FALSE )
        {
            
            printf ("%s\n", errormsg);
            
            printf ("%s", ask);
            
            scanf ( "%s", String );
            
            if ( strcmp ( String, value ) == 0 )
            {
                
                keepenter = TRUE;
                
            }
            else
            {
                
                *notenteragain = TRUE;
                keepenter = FALSE;
                
            }
            
        }
        else
        {
            
            keepenter = FALSE;
            
        }
        
    } while ( keepenter == TRUE );
    
    return ( atof (String) );
    
}

void str_eliminate (char str[], int len, char chara)
{

	for (int Iterator = 0; Iterator < len; Iterator++)
	{

		if ( str[Iterator] == chara )
		{

			str[Iterator] = '\0';

            break;

		}

	}

}

void cleanbuffer ()
{
    
    while ( (getchar()) != '\n'); 
    
}