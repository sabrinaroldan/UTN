#ifndef AUTORES_H_INCLUDED
#define AUTORES_H_INCLUDED

typedef struct
{
    int isEmpty;
    int idAutor;
    char nombreAut[31];
    char apellidoAut[31];


}Autor;


int aut_initAutor(Autor* pAutor, int len);
int aut_addAutor(Autor* pAutor,int len,int pIndex,char* msgE,int tries);
int aut_alter(Autor* pAutor, int len,char* msgE,int tries);
int aut_getID (Autor* pAutor,int len,char* msgE,int tries);
int aut_findAutById(Autor* pAutor, int len, int idE);
int aut_bajaAutor(Autor* pAutor, int len,char* msgE,int tries);

#endif // AUTORES_H_INCLUDED
