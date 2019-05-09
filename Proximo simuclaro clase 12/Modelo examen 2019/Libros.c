#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_strings.h"
#include "Libros.h"

//INICIALIZAR---------------------------
int lib_initLibro(libro* pLibro, int len)
{
    int i;
    if(pLibro!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pLibro[i].idLibro=-1;
            pLibro[i].isEmpty=1;
        }
    }
    return 0;
}
//ALTA--------------------------------
int lib_addLibro(libro* pLibro,int len,int pIndex,char* msgE,int tries)
{
    char bufferTitulo[51];
    //me falta enlazar los ID

    if((pLibro!=NULL)&&(len>0))
    {
        if(((getStringLetras(bufferTitulo,"\nIngrese Titulo: ",msgE,tries)==0)
        {
            strncpy(pLibro[pIndex].titulo,bufferTitulo,sizeof(bufferTitulo));
             pLibro[pIndex].idLibro=generarId();
             pLibro[pIndex].isEmpty=0;
             retorno=0;

        }
    }
    return retorno;
}

//MODIFICAR--------------------------------------
int lib_alter(libro* pLibro, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferTitulo[51];
    int retorno = -1;

    if((pLibro!=NULL)&&(len>0))
    {
        auxID=lib_getID(pLibro,len,msgE,tries);

        if(auxID>=0)
        {
            posOfID=lib_findLibById(pLibro,len,auxID);

            if(posOfID>=0)
            {
                while(opcion!=3)
                {
                 printf("\n1- Modificar Nombre\n");
                 printf("2- Modificar Codigo de Autor\n");
                 printf("3- Atras (Menu Principal)\n");
                 getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",msgE,1,3,tries);
                }
            }
        }

    }



}

//GET ID-------------------------------------
int lib_getID (libro* pLibro,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;

    if(pLibro!=NULL && len>0)
    {
        if(!getStringNumeros(bufferID,"\nIngrese ID: ",msgE,tries))
        {
            auxID=atoi(bufferID);
            retorno=auxID;
        }
    }
    return retorno;
}
//BUSCAR POR ID---------------------------
int lib_findLibById(libro* pLibro, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pLibro[i].idAutor==idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}
