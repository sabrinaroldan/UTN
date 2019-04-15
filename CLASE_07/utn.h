#define TRUE 1
#define FALSE 0

int getString ( char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);
//-------------------------------------

int getName (   char* msg,
                char* msgError,
                int minimo,
                int maximo,
                int reintentos,
                char* resultado);


int isValidName (char* cadena);

int isValidNum (char* cadena);

int getCreditCard ( char* msg,
                    char* msgError,
                    int minimo,
                    int maximo,
                    int reintentos,
                    char* resultado);




