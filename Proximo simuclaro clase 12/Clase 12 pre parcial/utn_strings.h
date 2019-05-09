#ifndef UTN_STRINGS_H_INCLUDED
#define UTN_STRINGS_H_INCLUDED


// Obtener el String
int getString (char* pStr, char* msg, char* msgE);
// Obtener Int
int getInt (int *pNum, char* msg, char* msgE);
// Obtener Float
int getFloat (float *pNum, char* msg, char* msgE);
// Tomar Int por rango
int getIntInRange (int *pNum,char *msg,char *msgE,int minimo,int maximo,int reintentos);
// Cargar un array secuencialmente por Int
int cargarArraySecuencialInt(int* pArray,int len,char* msg, char* msgE);
// Cargar un array secuencialmente por Float
int cargarArraySecuencialFloat(float* pArray,int len,char* msg, char* msgE);
// Obtener array de Letras
int getStringLetras (char* pStr, char* msg, char* msgE,int reintentos);
// Obtener array de int
int getStringNumeros (char* pStr, char* msg, char* msgE,int reintentos);
// Obtener array de Float
int getStringNumerosFloat (char* pStr, char* msg, char* msgE,int reintentos);
// Obtener array alfanumérico
int getStringAlphanumeric (char* pStr, char* msg, char* msgE,int reintentos);
// Obtener teléfono
int getTelephone (char* pStr, char* msg, char* msgE,int reintentos);
// Obtener DNI
int getDni (char* pStr, char* msg, char* msgE,int reintentos);
// Obtener CUIT
int getCuit (char* pStr, char* msg, char* msgE,int reintentos);
// Buscar espacio vacío
int findEmptyPlace (char pArray[][20],int* pIndex,int len);
// Buscar Nombre
int findName(char* name, char parray[][20], int len, int* pIndex);
// Ordenar array de mayor a menor
int ordenarArrayMayorMenor (char* pArray, int len,int limit);
// Mostrar array de Int
int showArrayInt(int* pArray,int len);
// Mostrar array de Char
int showArrayChar(char* pArray,int len);
// Validar int
int isNumber (char* pStr);
// Validar Float
int isNumberFloat (char* pStr);
// Validar Letra
int isLetter (char* pStr);
// Validar Alfanumérico
int isAlphanumeric (char* pStr);
// Validar Teléfono
int isTelephone (char* pStr);
// Validar DNI
int isDni (char* pStr);
// Validar CUIT
int isCuit (char* pStr);

#endif // UTN_STRINGS_H_INCLUDED
