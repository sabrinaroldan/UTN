#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    //char auxName[500] = "test";
    char auxCard[17]="Test1";

    /*if(getName( "Nombre?: \n",
                "Error\n",
                2,
                10,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }*/


    if(getCreditCard(   "Numero de tarjeta: \n",
                        "Error\n",
                        16,
                        16,
                        2,
                        auxCard) == 0)
    {
        printf("OK: %s",auxCard);
    }
    else
    {
        printf("ER: %s",auxCard);
    }

    return 0;
}
