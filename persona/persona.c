#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

Persona* Persona_new(void)
{
    return (Persona*) malloc(sizeof(Persona));
}

int Persona_delete(Persona* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

int Persona_setId(Persona* this, int id)
{
    int retorno = -1;
    if(this != NULL && id >= 0)
    {
        this->id = id;
        retorno = 0;
    }
    return retorno;
}

int Persona_getId(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->id;
        retorno = 0;
    }
    return retorno;
}

int Persona_setNombre(Persona* this, char nombre)
{
    int retorno = -1;
    if(this != NULL)
    {
        //this->nombre = nombre;
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

int Persona_getNombre(Persona* this, char* resultado)
{
    int retorno = -1;
    char bufferStr[50];
    if(this != NULL && resultado != NULL)
    {
        //*resultado = this->nombre;
        strcpy(resultado,bufferStr);
        //strcpy(*resultado,this->nombre);
        retorno = 0;
    }
    return retorno;
}

int Persona_setApellido(Persona* this, char apellido)
{
    int retorno = -1;
    if(this != NULL)
    {
        //this->nombre = nombre;
        strcpy(this->apellido,apellido);
        retorno = 0;
    }
    return retorno;
}

int Persona_getApellido(Persona* this, char* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        //*resultado = this->nombre;
        strcpy(*resultado,this->apellido);
        retorno = 0;
    }
    return retorno;
}

int Persona_setEstado(Persona* this, int estado)
{
    int retorno = -1;
    if(this != NULL && estado >= 0)
    {
        this->estado = estado;
        retorno = 0;
    }
    return retorno;
}

int Persona_getEstado(Persona* this, int* resultado)
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
        *resultado = this->estado;
        retorno = 0;
    }
    return retorno;
}

/*int parseData(char* fileName,Persona* arrayPersonas, int len)
{
    Persona personas[len];
    int len,i;

    for(i=0; i<len; i++)
    {
        printf("id:%d nombre:%s apellido:%s edad:%d\n",personas[i].id,personas[i].nombre,
        personas[i].apellido,personas[i].estado);
    }
 exit(EXIT_SUCCESS);
}
*/

int parseData(char* fileName,Persona* arrayPersonas, int len)
{
     FILE *pFile;
     int r,i=0;
     char var1[50],var3[50],var2[50],var4[50];
     pFile = fopen(fileName,"r");

     if(pFile == NULL)
     {
        return -1;
     }

     do
     {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
        if(r==4)
        {
             arrayPersonas[i].id = atoi(var1);
             strncpy(arrayPersonas[i].nombre,var2,sizeof(arrayPersonas[i].nombre));
             strncpy(arrayPersonas[i].apellido,var3,sizeof(arrayPersonas[i].apellido));
             arrayPersonas[i].estado = atoi(var4);
             i++;
         }
         else
         {
         break;
         }
     }while(!feof(pFile) && i<len);
     fclose(pFile);
     return i;
}

Persona* Persona_newStr(char* id,char* nombre,char* apellido,char* estado)
{
    Persona* retorno=NULL;
    Persona* pAuxPersona;

    if(id!=NULL && nombre!=NULL && apellido!=NULL && estado!=NULL)
    {
        pAuxPersona=Persona_new();
        if(pAuxPersona!=NULL)
        {
            if( (!Persona_setNombre(pAuxPersona,nombre))&&
                (!Persona_setApellido(pAuxPersona,apellido))&&
                (!Persona_setIdStr(pAuxPersona,id))&&
                (!Persona_setEstadoStr(pAuxPersona,estado)))
                {
                    retorno=pAuxPersona;
                }
                else
                {
                    Persona_delete(pAuxPersona);
                }
        }
    }


}

int Persona_setId(Persona* this, char* id)
{
    int retorno = -1;
    if(this != NULL && id !=NULL && !iValidNumber(id))
    {
        Persona_setId(this,atoi(id));
    }
    return retorno;
}


int Persona_getIdStr(Persona* this, char* resultado)
{
    int retorno = -1;
    int bufferInt;
    if(this != NULL && resultado != NULL)
    {
        Persona_getId(this,&bufferInt);
        sprintf(resultado,"%d",;
        retorno = 0;
    }
    return retorno;
}








/*int Persona_compararNombre (Persona* this a, Persona* this b)//comparar y ordenar dos empleados por nombre
{
    int retorno = -1;

    if(this != NULL && this != NULL)
    {

    }
    return retorno;
}

int Persona_Alta (Persona* this)//va a llamar al new y a todos los sets. Es un constructor con parametros
{
    int retorno = -1;
    if(this != NULL && resultado != NULL)
    {
    }
    return retorno;
}*/
