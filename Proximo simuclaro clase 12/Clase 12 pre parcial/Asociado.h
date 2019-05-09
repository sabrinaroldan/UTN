#ifndef ASOCIADO_H_INCLUDED
#define ASOCIADO_H_INCLUDED

typedef struct
{
    int estado; //PENDIENTE-CUMPLIDO
    int idAsociado;
    char nombre[20];
    char apellido[20];
    int edad;
    int dni;

}sAsociado;


int pan_initAsociado(sAsociado* pAsociado,int len);
int aso_addAso(sAsociado* pAsociado,int len,int pIndex,char* msgE,int tries);








#endif // ASOCIADO_H_INCLUDED
