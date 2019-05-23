#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    int estado;
}Persona;
#endif

Persona* Persona_new(void);
int Persona_delete(Persona* this);

int Persona_setId(Persona* this, int id);
int Persona_getId(Persona* this, int* resultado);
int Persona_setNombre(Persona* this, char nombre);
int Persona_getNombre(Persona* this, char* resultado);
int Persona_setApellido(Persona* this, char apellido);
int Persona_getApellido(Persona* this, char* resultado);
int Persona_setEstado(Persona* this, int estado);
int Persona_getEstado(Persona* this, int* resultado);
int Persona_Alta (Persona* this);
