#include <stdio.h>
#include <stdlib.h>

int getFloat (char *mensaje, char *mensajeError, float maximo, float minimo, int reintentos, int *resultado)
{
    int retorno=-1;
    int buffer;

    if(*mensaje!=NULL && mensajeError!=NULL && maximo>=minimo && reintentos>=0 && resultado!=NULL)
    {
        do{
        printf("%s",mensaje);
        scanf("%d",&buffer);
            if(isValidFloat(buffer,maximo,minimo))
            {
            resultado=buffer;
            return 0;
            }
            else
            {
                printf("%s",*mensajeError);
            }
            reintentos--;
        }while (reintentos>0);
    }
    return retorno;
}

