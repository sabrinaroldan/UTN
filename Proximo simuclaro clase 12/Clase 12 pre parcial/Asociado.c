#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asociado.h"
#include "utn_strings.h"
static int generarId(void);

int aso_initAsociado(sAsociado* pAsociado,int len)
{
    int i;
    if(pAsociado!=NULL && len>0)
    {
        for(i=0; i<len;i++)
        {
            pAsociado[i].idAsociado=-1;
            pAsociado[i].estado=0;
        }
    }
    return 0;


}


//---------------------------

int aso_addAso(sAsociado* pAsociado,int len,int pIndex,char* msgE,int tries)
{
    char bufferDni[10];
    char bufferEdad[3];
    char bufferNombre[20];
    char bufferApellido[20];
    int auxDni;
    int auxEdad;
    int retorno=-1;

    if((pAsociado!=NULL)&&(len>0))
     {
         if(((getStringLetras(bufferNombre,"\nIngrese Nombre: ",msgE,tries)==0)&&
             (getStringLetras(bufferApellido,"\nIngrese Apellido: ",msgE,tries)==0)))
         {
            if(((getStringNumeros(bufferEdad,"\nIngrese su Edad: ",msgE,tries)==0)&&
                (getDni(bufferDni,"\nIngrese su DNI: ",msgE,tries)==0)))
             {
                auxEdad=atoi(bufferEdad);
                auxDni=atoi(bufferDni);
                strncpy(pAsociado[pIndex].nombre,bufferNombre,sizeof(bufferNombre));
                strncpy(pAsociado[pIndex].apellido,bufferApellido,sizeof(bufferApellido));
                pAsociado[pIndex].edad=auxEdad;
                pAsociado[pIndex].dni=auxDni;
                pAsociado[pIndex].idAsociado=generarId();
                pAsociado[pIndex].estado=1;
                retorno=0;
             }

         }
     }

    return retorno;
}
//--------------------------------------

static int generarId(void)
{
    static int idAso=0;
    return idAso++;
}
