#ifndef LIBROS_H_INCLUDED
#define LIBROS_H_INCLUDED

typedef struct
{   int isEmpty;
    int idLibro;
    int idAutor;
    char titulo[51];



}libro;

int lib_initLibro(libro* pLibro, int len);
int lib_addLibro(libro* pLibro,int len,int pIndex,char* msgE,int tries);
int lib_alter(libro* pLibro, int len,char* msgE,int tries);
int lib_getID (libro* pLibro,int len,char* msgE,int tries);

#endif // LIBROS_H_INCLUDED
