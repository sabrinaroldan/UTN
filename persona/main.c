#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "utn.h"

// {}  []

int main()
{

    FILE *pFile=NULL;
    FILE *pFileBkp=NULL;

    pFile=fopen("data.csv","r");
    pFileBkp=fopen("data_bkp.csv","w");

    char bufferId [4096];
    char bufferNombre [4096];
    char bufferApellido [4096];
    char bufferEstado [4096];

    if(pFile!=NULL && pFileBkp!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,]%[^\n]\n",
            bufferId,bufferNombre,bufferApellido,bufferEstado);

            Persona* Persona_new();

            printf("%s, %s\n",bufferApellido,bufferNombre);
        }
    }
    fclose(pFile);
    fclose(pFileBkp);










/*
    Persona *pArrayPersona[1113];
    int ultimoElementoArrayPersona = 0;
    int indiceActual;
    int auxInt;
    char auxChar;

    indiceActual = ultimoElementoArrayPersona;
    pArrayPersona[indiceActual] =  Persona_new();


    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("OK");
        if(!Persona_setId(pArrayPersona[indiceActual],14))
        {
            Persona_getId(pArrayPersona[indiceActual], &auxInt);
            printf("\nEl id de la persona es: %d\n",auxInt);
        }

    }

    if(pArrayPersona[indiceActual] != NULL)
    {
        ultimoElementoArrayPersona++;
        printf("OK");
        if((!Persona_setId(pArrayPersona[indiceActual],21)) && (!Persona_setNombre(pArrayPersona[indiceActual],"Roberto")) &&
        (!Persona_setApellido(pArrayPersona[indiceActual],"Roldan")))
        {
            Persona_getId(pArrayPersona[indiceActual], &auxInt);
            Persona_getNombre(pArrayPersona[indiceActual], &auxChar);
            Persona_getApellido(pArrayPersona[indiceActual], &auxChar);
            printf("\nEl id del persona es: %d y su nombre y apellido es: %s\n",auxInt, &auxChar, &auxChar);
        }
    }
*/
    return 0;
}

// {}  []


/*
    FILE *pFile=NULL; //buena practica asignarle null al principio
    FILE *pFileBkp=NULL;

    pFile=fopen("data.csv","r"); // permiso para leer: r
    pFileBkp=fopen("data_bkp.csv","w"); // permiso para escribir: w

    devuelve null sino lo leyó bien
    char bufferId [4096];
    char bufferNombre [4096];
    char bufferApellido [4096];
    char bufferEstado [4096];
    si el archivo tiene 1000 lineas vamos a leerlo mil veces.

    if(pFile!=NULL && pFileBkp!=NULL)
    {
        while(!feof(pFile)) //funcion que avisa cuando termina el archivo
        fscanf(pFile,"%s",bufferStr) //como leer una linea, confirmar cual es el archivo, pasar el puntero a file
                                     //si escribo en vez de pFile=stdin es lo mismo, es un puntero
        //printf("%s\n",bufferStr); //Imprime una sola linea

        fprint(pFileBkp,"%s\n",bufferStr);
    }
    fclose(pFile);
    fclose(pFileBkp);

    //parseo, atoi, atof y token (buscar para hacer funciones)

    //stdin stdout punteros a archivos

-------------------------------------------------------------------------------------------------

    construir mascaras para scanf

        while(!feof(pFile)) //funcion que avisa cuando termina el archivo [^,] agarra todo lo que no sea una coma
        {
            fscanf(pFile,"%[^,],%[^,].%[^,],%[^\n]\n",bufferStr) //mas facil es negar lo que no se quiere que aclarar lo que admitimos en el file
            fprint(pFileBkp,"%s\n",bufferStr);
        }
            fscanf(pFile,"%[^-]-%[^,].%[^,],%[^*]*" //se pone el mismo parametro cuando se quiere separar. y si la persona esta
                                                    dividida por * poner al final.

    hola+chau+22-juan+pedro+44
    %[^+]+%[^+]

-------------------------------------------------------------------------------------------------

    FILE *pFile=NULL; //buena practica asignarle null al principio
    FILE *pFileBkp=NULL;

    pFile=fopen("data.csv","r"); // permiso para leer: r
    pFileBkp=fopen("data_bkp.csv","w"); // permiso para escribir: w

    devuelve null sino lo leyó bien
    char bufferId [4096];
    char bufferNombre [4096];
    char bufferApellido [4096];
    char bufferEstado [4096];
    si el archivo tiene 1000 lineas vamos a leerlo mil veces.

    if(pFile!=NULL && pFileBkp!=NULL)
    {
        while(!feof(pFile))
        {
            fscanf(pFile,"%[^,],%[^,],%[^,]%[^\n]\n",bufferId,bufferNombre,bufferApellido,bufferEstado)
            crear un empleado
            fprint(pFileBkp,"%s\n",bufferStr);
        }
    }
    fclose(pFile);
    fclose(pFileBkp);

    crear constructor que reciba todo como string


    sprintf(bufferid,"%d",id); // en vez de alir por pantalla hace el camino inverso.




*/






