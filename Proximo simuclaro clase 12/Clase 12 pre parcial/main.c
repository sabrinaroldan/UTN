#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Asociado.h"
#include "Llamada.h"
#include "utn_strings.h"
#define LEN_LISTA 5
#define REINTENTOS 3

int main()
{
    sAsociado socios[LEN_LISTA];


       if(!aso_addAso(socios,LEN_LISTA,4,"DATO NO VALIDO\n",REINTENTOS))
       {

       printf("\n----Se dio de ALTA exitosamente!----\n");
       }



    return 0;
}
