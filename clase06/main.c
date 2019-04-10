#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CANTIDAD_CARACTERES 200
/* [] ||
--{}  */
int main()
{
    char nombre[CANTIDAD_CARACTERES];
    char buffer[CANTIDAD_CARACTERES];
    int i;
    int error=-1;

    printf("\nIngrese su nombre\n");
    fgets(buffer,sizeof(buffer),stdin);

    buffer[strlen(buffer)-1]='\0';

    for(i=0;i<=sizeof(buffer);i++)
    {
        buffer[i];
        if(buffer[i]<'a' || buffer[i]>'z' && buffer[i]<'A' || buffer[i]>'Z')
        {
            printf("\nUd ha ingresado un caracter no valido\n");
            return error;
        }

        nombre[i]=buffer[i];
    }

    strncpy(nombre,buffer,strlen(buffer));
    printf("\nEl nombre ingresado es: %s", nombre);

    return 0;
}
























