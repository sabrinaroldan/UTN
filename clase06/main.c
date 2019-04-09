#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* [] ||
--{}  */
int main()
{
    char nombre[257];
    char buffer[257];
    int i;
    int error=-1;

    printf("\nIngrese su nombre\n");
    fgets(buffer,sizeof(buffer),stdin);

    for(i=0;i<=sizeof(buffer);i++)
    {
        buffer[i];

        if(buffer[i]=='*'||buffer[i]=='1'||buffer[i]=='2'||buffer[i]=='3'
        ||buffer[i]=='4'||buffer[i]=='5'||buffer[i]=='6'||buffer[i]=='7'
        ||buffer[i]=='8'||buffer[i]=='9'||buffer[i]=='0'||buffer[i]=='+'
        ||buffer[i]=='-')
        {
            printf("\nUd ha ingresado un caracter no valido\n");
            return error;
        }
        nombre[i]=buffer[i];
    }

    strncpy(buffer,nombre,sizeof(buffer));
    printf("\nEl nombre ingresado es: %s", nombre);

    return 0;
}
