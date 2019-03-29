#include <stdio.h>
#include <stdlib.h>

int getInt(char *mensaje,char *mensajeError, int minimo, int maximo, int reintentos, int *resultado);

int main()
{
    int numeroIngresado;
    int errorDeIngreso;
    errorDeIngreso=getInt("Ingrese un numero\n","Error",0,50,2,&numeroIngresado);

    if(errorDeIngreso)
    {
        printf("Numero de ingreso no valido");
    }else
    {
        printf("El numero ingresado es: %d",numeroIngresado);
    }
    return 0;
}

int isValidInt (int numero, int maximo, int minimo)
{
    if(numero>=minimo&&numero<=maximo)
    {
        return 1;
    }else{
        return 0;
    }

}

int getInt(char *mensaje,char *mensajeError, int minimo, int maximo, int reintentos, int *resultado)
{
    int buffer;
    int *retorno=-1;
    int i;

    if(mensaje!=NULL && mensajeError!=NULL && resultado!=NULL && maximo>=minimo && reintentos>=0)
    {
        for(i=0;i<=reintentos;i++)
        {
            printf("%s",mensaje);
            scanf("%d",&buffer);
            if(isValidInt(buffer, minimo, maximo))
            {
                *resultado=buffer;
                retorno=0;
                break;
            }else
            {
                printf("%s", mensajeError);
            }
        }
    }
    return retorno;
}
