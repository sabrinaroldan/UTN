#include <stdio.h>
#include <stdlib.h>
#include "empleado.h"

int main()
{
    Empleado *pArrayEmpleado[1000];
    int ultimoElementoArrayEmpleado = 0;
    int indiceActual;
    int auxInt;
    char auxChar;

    indiceActual = ultimoElementoArrayEmpleado;
    pArrayEmpleado[indiceActual] =  Emp_new();


    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if(!Emp_setId(pArrayEmpleado[indiceActual],14))
        {
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            printf("\nEl id del empleado es: %d\n",auxInt);

        }

    }

    if(pArrayEmpleado[indiceActual] != NULL)
    {
        ultimoElementoArrayEmpleado++;
        printf("OK");
        if((!Emp_setId(pArrayEmpleado[indiceActual],21)) && (!Emp_setNombre(pArrayEmpleado[indiceActual],Roberto)))
        {
            Emp_getId(pArrayEmpleado[indiceActual], &auxInt);
            Emp_getNombre(pArrayEmpleado[indiceActual], &auxChar);
            printf("\nEl id del empleado es: %d y su nombre es: %c\n",auxInt, auxChar);

        }

    }


    return 0;
}
