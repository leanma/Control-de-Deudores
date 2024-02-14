#ifndef CADENA_H
#define CADENA_H

#include <stddef.h>


typedef struct
{
	char* inicio;
	char* fin;
}
Palabra;


void normalizar(char* cad_ori, char* cad_dest);
int sonAnagramas(char* palabra1, char* palabra2);
void invertirCadena(char* cadena);
char* reemplazarSubcad(const char* cadena, const char* subcad, const char* reemplazo, char* cadDestino, size_t tamCadDestino);


#endif // CADENA_H
