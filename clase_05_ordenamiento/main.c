#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD_NUMEROS 5
//void swap(int num1, int num2);
void printArrayInt(int* arrayResultado,int limite);

int main()
{
    //swap(); Funcion para reemplazar, cambiar de lugar

    int aNumeros[CANTIDAD_NUMEROS]={6,4,3,0,9};
    int flagSwap;
    int auxiliar;

    do{
        flagSwap=0;
        for(int i=0;i<CANTIDAD_NUMEROS-1;i++)
        {
            if (aNumeros[i] > aNumeros[i+1])
            {
                auxiliar=aNumeros[i];
                aNumeros[i]=aNumeros[i+1];
                aNumeros[i+1]=auxiliar;
                //swap(a[i],a[i+1])
                flagSwap=1;
            }
        }
    }while(flagswap);

    printArrayInt(aNumeros,CANTIDAD_NUMEROS);
    printf("%d",aNumeros);

    /*int a=1;
    int b=2;

    swap(a,b);
    printf("a:%d b:%d",a,b);*/


}

void printArrayInt(int* arrayResultado,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("%d\n",arrayResultado[i]);
    }
}

/*
void swap(int num1, int num2)
{
    int aux;

    aux=num1;
    num1=num2;
    num2=aux;

}*/
