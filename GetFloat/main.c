#include <stdio.h>
#include <stdlib.h>

int getFloat (char *mensaje, char *mensajeError, float maximo, float minimo, int reintentos, int *resultado);

int main()
{
    float numeroIngresado;
    printf("Ingrese un numero\n");
    scanf("%f",numeroIngresado);
    numeroIngresado=getFloat("Ingrese un numero\n","Error\n",54,0,2,&numeroIngresado);
    return 0;
}

int isValidFloat(float numero, float maximo, float minimo)
{
    if(numero>=maximo && numero<=minimo)
    {
        return 1;
    }
    return 0;
}

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
