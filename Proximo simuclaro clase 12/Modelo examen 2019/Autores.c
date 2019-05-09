#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_strings.h"
#include "Autores.h"
static int generarId(void);

//INICIALIZAR--------------------------------
int aut_initAutor(Autor* pAutor, int len)
{
    int i;
    if(pAutor!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pAutor[i].idAutor=-1;
            pAutor[i].isEmpty=1;
        }
    }
    return 0;
}

//ALTA----------------------------------
int aut_addAutor(Autor* pAutor,int len,int pIndex,char* msgE,int tries)
{
    char bufferNombre[31];
    char bufferApellido[31];
    int retorno = -1;

    if((pAutor!=NULL)&&(len>0))
    {
        if(((getStringLetras(bufferNombre,"\nIngrese Nombre: ",msgE,tries)==0)&&
        (getStringLetras(bufferApellido,"\nIngrese Apellido: ",msgE,tries)==0)))
        {
            strncpy(pAutor[pIndex].nombreAut,bufferNombre,sizeof(bufferNombre));
            strncpy(pAutor[pIndex].apellidoAut,bufferApellido,sizeof(bufferApellido));
            pAutor[pIndex].idAutor=generarId();
            pAutor[pIndex].isEmpty=0;
            retorno=0;

        }

    }

    return retorno;
}

//MODIFICAR-------------------------
int aut_alter(Autor* pAutor, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int opcion=0;
    char bufferNombre[31];
    char bufferApellido[31];
    int retorno = -1;

    if((pAutor!=NULL)&&(len>0))
    {
        auxID=aut_getID(pAutor,len,msgE,tries);

         if(auxID>=0)
         {
            posOfID=aut_findAutById(pAutor,len,auxID);

            if(posOfID>=0)
            {
                while(opcion!=3)
                {
                 printf("\n1- Modificar Nombre\n");
                 printf("2- Modificar Apellido\n");
                 printf("3- Atras (Menu Principal)\n");
                 getIntInRange(&opcion,"\n   INGRESE OPCION (Menu Modificacion): ",msgE,1,3,tries);

                 switch(opcion)
                 {
                    case 1:
                      {
                        if(!getStringLetras(bufferNombre,"\nIngrese NUEVO Nombre: ",msgE,tries))
                        {
                        strncpy(pAutor[posOfID].nombreAut,bufferNombre,sizeof(bufferNombre));
                        retorno=0;
                        }
                        break;
                      }
                       case 2:
                      {
                        if(!getStringLetras(bufferApellido,"\nIngrese NUEVO Nombre: ",msgE,tries))
                        {
                        strncpy(pAutor[posOfID].apellidoAut,bufferApellido,sizeof(bufferApellido));
                        retorno=0;
                        }
                        break;
                      }
                 }

                }

             }

            else
            {
                printf("\n----No se encontro el ID!-----\n");
            }
         }


    }

    return retorno;
}
//BAJA------------------------------------------
int aut_bajaAutor(Autor* pAutor, int len,char* msgE,int tries)
{
    int auxID;
    int posOfID;
    int retorno=-1;

    if(pAutor!=NULL && len>0)
    {
        auxID=aut_getID(pAutor,len,msgE,tries);

        if(auxID>=0)
        {
            posOfID=aut_findAutById(pAutor,len,auxID);
            if(posOfID>=0)
            {
               pAutor[posOfID].isEmpty=1;
               retorno=0;

            }



        }



    }

    return retorno;
}


//GET ID-------------------------------------
int aut_getID (Autor* pAutor,int len,char* msgE,int tries)
{
    int retorno=-1;
    char bufferID[20];
    int auxID;

    if(pAutor!=NULL && len>0)
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
int aut_findAutById(Autor* pAutor, int len, int idE)
{
    int i;
    int ret=-1;
    for(i=0;i<len;i++)
    {
        if(pAutor[i].idAutor==idE)
        {
            ret=i;
            break;
        }
    }
    return ret;
}



//GENERAR ID-----------------------
static int generarId(void)
{
    static int idAut=0;
    return idAut++;
}

