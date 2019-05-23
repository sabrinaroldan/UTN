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
