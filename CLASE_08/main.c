#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define QTY_EMPLEADOS 10

/* [] {}*/

int main()
{
    char auxName[500] = "test";

    char arrayNombres [QTY_EMPLEADOS] [50];

    strncpy(arrayNombres[0],"JUAN",50);
    strncpy(arrayNombres[1],"JUAN1",50);
    strncpy(arrayNombres[2],"JUAN2",50);

    printArray (arrayNombres,3);
    insertStr (arrayNombres,3);
    //compStr (arrayNombres,3);

    /*int i;

    for(i=0;i<3;i++)
    {
        printf("%s",arrayNombres[i]);
    }*/



/*
    if(getName( "Nombre?: ",
                "Error",
                2,
                5,
                2,
                auxName) == 0)
    {
        printf("OK: %s",auxName);
    }
    else
    {
        printf("ER: %s",auxName);
    }*/

    return 0;
}
