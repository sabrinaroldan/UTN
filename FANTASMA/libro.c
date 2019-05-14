#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "libro.h" //cambiar por nombre entidad


/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param array libro Array of libro
* \param size int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int libro_Inicializar(Libro array[], int size)                                    //cambiar libro
{
    int retorno=-1;
    if(array!= NULL && size>0)
    {
        for(;size>0;size--)
        {
            array[size-1].isEmpty=1;
        }
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Buscar
//Int
/** \brief Busca el primer lugar vacio en un array
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra un lugar vacio o Error [Invalid length or NULL pointer] - (0) si encuentra una posicion vacia
*
*/
int libro_buscarEmpty(Libro array[], int size, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0 && posicion!=NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarID(Libro array[], int size, int valorBuscado, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idUnico==valorBuscado)                                                   //cambiar campo ID
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}
/** \brief Busca un int en un array y devuelve la posicion en que se encuentra
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarInt(Libro array[], int size, int valorBuscado, int* posicion)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(array[i].idLibro==valorBuscado)                                                   //cambiar campo idLibro
            {
                retorno=0;
                *posicion=i;
                break;
            }
        }
    }
    return retorno;
}

//String
/** \brief Busca un string en un array
* \param array libro Array de libro
* \param size int Tamaño del array
* \param posicion int* Puntero a la posicion del array donde se encuentra el valor buscado
* \return int Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int libro_buscarString(Libro array[], int size, char* valorBuscado, int* indice)                    //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else if(strcmp(array[i].titulo,valorBuscado)==0)                                        //cambiar campo titulo
            {
                *indice=i;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

//*****************************************
//Alta
/** \brief Solicita los datos para completar la primer posicion vacia de un array
* \param array libro Array de libro
* \param size int Tamaño del array
* \param contadorID int* Puntero al ID unico que se va a asignar al nuevo elemento
* \return int Return (-1) si Error [largo no valido o NULL pointer o no hay posiciones vacias] - (0) si se agrega un nuevo elemento exitosamente
*
*/
int libro_alta(Libro array[], int size, int* contadorID)                          //cambiar libro
{
    int retorno=-1;
    int posicion;
    if(array!=NULL && size>0 && contadorID!=NULL)
    {
        if(libro_buscarEmpty(array,size,&posicion)==-1)                          //cambiar libro
        {
            printf("\nNo hay lugares vacios");
        }
        else
        {
            (*contadorID)++;
            array[posicion].idUnico=*contadorID;                                                       //campo ID
            array[posicion].isEmpty=0;
            utn_getUnsignedInt("\nIngrese el ID: ","\nError",1,sizeof(int),1,10,1,&array[posicion].idLibro);           //mensaje + cambiar campo idLibro
            //utn_getFloat("\ngetFloat: ","\nError",1,sizeof(float),0,1,1,&array[posicion].varFloat);             //mensaje + cambiar campo varFloat
            utn_getName("\nIngrese el titulo: ","\nError",1,TEXT_SIZE,1,array[posicion].titulo);                      //mensaje + cambiar campo titulo
            utn_getTexto("\nIngrese el autor: ","\nError",1,TEXT_SIZE,1,array[posicion].idAutor);                 //mensaje + cambiar campo idAutor
            printf("\n Posicion: %d\n ID: %d\n idLibro: %d\n titulo: %s\n idAutor: %s",
                   posicion, array[posicion].idUnico,array[posicion].idLibro,array[posicion].titulo,array[posicion].idAutor);
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Baja valor unico
/** \brief Borra un elemento del array por ID
* \param array libro Array de libro
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libro_baja(Libro array[], int sizeArray)                                      //cambiar libro
{
    int retorno=-1;
    int posicion;
    int id;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a cancelar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);          //cambiar si no se busca por ID
        if(libro_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            array[posicion].isEmpty=1;
            array[posicion].idUnico=0;                                                                   //cambiar campo id
            array[posicion].idLibro=0;                                                             //cambiar campo varFloat
            strcpy(array[posicion].titulo,"");                                                   //cambiar campo titulo
            strcpy(array[posicion].idAutor,"");                                               //cambiar campo idAutor
            retorno=0;
        }
    }
    return retorno;
}

//Baja valor repetido
/** \brief Borra todos los elemento del array que contengan el valor buscado
* \param array libro Array de libro
* \param size int Tamaño del array
* \param valorBuscado int Valor a buscar en el array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se elimina el elemento exitosamente
*
*/
int libro_bajaValorRepetidoInt(Libro array[], int sizeArray, int valorBuscado) //cuando hay que dar de baja todas las posiciones en las que se encuentra ese int
{
    int retorno=-1;
    int i;
    if(array!=NULL && sizeArray>0)
    {
        for(i=0;i<sizeArray;i++)
        {
            if(array[i].idUnico==valorBuscado)                                                        //cambiar si no se busca por ID
            {
                array[i].isEmpty=1;
                array[i].idUnico=0;                                                                   //cambiar campo id
                array[i].idLibro=0;                                                              //cambiar campo varFloat
                strcpy(array[i].titulo,"");                                                   //cambiar campo titulo
                strcpy(array[i].idAutor,"");                                               //cambiar campo idAutor
            }
        }
        retorno=0;
    }
    return retorno;
}



//*****************************************
//Modificar
/** \brief Busca un elemento por ID y modifica sus campos
* \param array libro Array de libro
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer o no encuentra elementos con el valor buscado] - (0) si se modifica el elemento exitosamente
*
*/
int libro_modificar(Libro array[], int sizeArray)                                //cambiar libro
{
    int retorno=-1;
    int posicion;
    int id;                                                                                         //cambiar si no se busca por ID
    char opcion;
    if(array!=NULL && sizeArray>0)
    {
        utn_getUnsignedInt("\nID a modificar: ","\nError",1,sizeof(int),1,sizeArray,1,&id);         //cambiar si no se busca por ID
        if(libro_buscarID(array,sizeArray,id,&posicion)==-1)                                   //cambiar si no se busca por ID
        {
            printf("\nNo existe este ID");                                                          //cambiar si no se busca por ID
        }
        else
        {
            do
            {       //copiar printf de alta
                printf("\n Posicion: %d\n ID: %d\n idLibro: %d\n titulo: %s\n idAutor: %s",
                   posicion, array[posicion].idUnico,array[posicion].idLibro,array[posicion].titulo,array[posicion].idAutor);
                utn_getChar("\n\nModificar: \n\tA: Codigo del libro \n\tB: Titulo \n\tC: Autor \n\tS: Salir\n","\nError",'A','Z',1,&opcion);
                switch(opcion)
                {
                    case 'A':
                        utn_getUnsignedInt("\nCodigo del libro: ","\nError",1,sizeof(int),0,1,1,&array[posicion].idLibro);           //mensaje + cambiar campo idLibro
                        break;
                    case 'B':
                        utn_getName("\nTitulo: ","\nError",1,TEXT_SIZE,1,array[posicion].titulo);                      //mensaje + cambiar campo titulo
                        break;
                    case 'C':
                        utn_getTexto("\nAutor: ","\nError",1,TEXT_SIZE,1,array[posicion].idAutor);             //mensaje + cambiar campo idAutor
                        break;
                    case 'S':
                        break;
                    default:
                        printf("\nOpcion no valida");
                }
            }while(opcion!='S');
            retorno=0;
        }
    }
    return retorno;
}

//*****************************************
//Ordenar
/** \brief Ordena por campo XXXXX los elementos de un array ante la igualdad de estos ordena por el campo ZZZZZZ
* \param array libro Array de libro
* \param size int Tamaño del array
* \param orderFirst int Determina si el orden del primer criterio es ascendete o descendente
* \param orderSecond int Determina si el orden del segunbdo criterio es ascendete o descendente
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se ordena exitosamente
*
*/
int libro_ordenarPorDobleCriterio(Libro array[],int size, int orderFirst, int orderSecond)                              //cambiar libro
{
    int retorno=-1;
    int i;
    Libro buffer;
    int flagSwap;

    if(array!=NULL && size>=0)
    {
        do
        {
            flagSwap=0;
            for (i = 1; i < size-1; i++)
            {
                if( ((strcmp(array[i].titulo,array[i+1].titulo) < 0) && orderFirst) ||
                    ((strcmp(array[i].titulo,array[i+1].titulo) > 0) && !orderFirst) )
                {
                    flagSwap=1;
                    buffer = array[i];
                    array[i] = array[i+1];
                    array[i+1] = buffer;
                }

            }
        }while(flagSwap);
        retorno=0;
    }
    return retorno;
}

//*****************************************
//Listar
/** \brief Lista los elementos de un array
* \param array libro Array de libro
* \param size int Tamaño del array
* \return int Return (-1) si Error [largo no valido o NULL pointer] - (0) si se lista exitosamente
*
*/
int libro_listar(Libro array[], int size)                      //cambiar libro
{
    int retorno=-1;
    int i;
    if(array!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
                continue;
            else
                printf("\n ID: %d\n idLibro: %d\n titulo: %s\n idAutor: %s",
                       array[i].idUnico,array[i].idLibro,array[i].titulo,array[i].idAutor);      //cambiar todos
        }
        retorno=0;
    }
    return retorno;
}


void libro_mock(Libro arrayLibro[], int size,int *contadorIdLibro)                      //cambiar libro
{
    //*******************************************************************
    arrayLibro[0].idUnico=0;
    arrayLibro[0].isEmpty=0;
    arrayLibro[0].idLibro=0;
    strcpy(arrayLibro[0].idAutor,"CCCCC");
    strcpy(arrayLibro[0].titulo,"CCCCC");
    contadorIdLibro++;

    arrayLibro[1].idUnico=1;
    arrayLibro[1].isEmpty=0;
    arrayLibro[1].idLibro=0;
    strcpy(arrayLibro[1].idAutor,"AAAAA");
    strcpy(arrayLibro[1].titulo,"AAAAA");
    contadorIdLibro++;

    arrayLibro[2].idUnico=2;
    arrayLibro[2].isEmpty=0;
    arrayLibro[2].idLibro=0;
    strcpy(arrayLibro[2].idAutor,"BBBBB");
    strcpy(arrayLibro[2].titulo,"BBBBBB");
    contadorIdLibro++;

    arrayLibro[3].idUnico=3;
    arrayLibro[3].isEmpty=0;
    arrayLibro[3].idLibro=0;
    strcpy(arrayLibro[3].idAutor,"BBBBB");
    strcpy(arrayLibro[3].titulo,"BBBBBB");
    contadorIdLibro++;
}
