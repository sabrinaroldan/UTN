#include <stdio.h>
#include <stdlib.h>
int sumar (void);

int main()
{
    sumar();

    return 0;
}

int sumar (void){
    int num1;
    int num2;

   printf("Ingrese un numero");
   scanf("%d",&num1);
   printf("Ingrese un numero");
   scanf("%d",&num2);

   int resultado=num1+num2;

   printf("El resultado de la suma es: %d",resultado);
    return 0;
}



int calcularPromedio(void){
    int num;
    int suma=0;
    int promedio=0;
    int cont=0;

#define CANTIDAD_NUMEROS 3

    for(int i=1;i>=3;i++){
        printf("Ingrese un numero");
        scanf("%d",&num);
        suma+=num;
        cont++;
    }

    promedio=suma/cont;

    printf("El promedio de los numeros ingresados es: %d",cont);
}
