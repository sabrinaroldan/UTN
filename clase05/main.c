#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define CANTIDAD_ALUMNOS 5000

int main()
{
    /*int* pEdades;//Declarar puntero. Puntero a "int pEdades".
    int bufferEdad;
    int aEdades[CANTIDAD_ALUMNOS];*/
    /*float aPesos[CANTIDAD_ALUMNOS];
    char aLetraNombre[CANTIDAD_ALUMNOS];*/
    /*aEdades[100]=22;
    bufferEdad=aEdades[100];
    //pEdades=&aEdades[0]; //Más simple de escribir que lo de abajo. Significa lo mismo.

    pEdades=aEdades; //Es lo mismo que lo de arriba, el compilador sabe que queremos la primera posición del array.
    pEdades[88]=11;
    bufferEdad=pEdades[188];

    *(pEdades+88)=11;//En la posición que tenìa estoy pidiendo que se mueva 88 lugares de la posición base.
    bufferEdad=*pEdades+188;//En este caso sumaria el elemento de la primera posición y sumando lo que hay en la posición 188.
    bufferEdad=*(pEdades+188);
    //Siempre el tipo de dato del array tiene que ser el mismo tipo que el del puntero.

    int getInt(char* msg,
                char *msgError,
                int maximo,
                int minimo,
                int reintentos,
                int* resultado)

    int getArrayInt(    char* msg,
                        char *msgError,
                        int maximo,
                        int minimo,
                        int reintentos,
                        int* arrayResultado,//array resultado
                        int limite) //Declarar variable buffer. Posición i.
                        //devolver array de resultados y cantidad de elementos.*/

    int aEdades[CANTIDAD_ALUMNOS];
    getArrayInt("Ingrese edad","Edad ingresada invalida",110,0,5,aEdades,CANTIDAD_ALUMNOS);


}

