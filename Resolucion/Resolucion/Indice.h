#ifndef INDICE_H_INCLUDED
#define INDICE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Control.h"


typedef struct
{
	int nro_cliente;
	int nro_reg;
}t_indice;

void mostrar_indice(void*indice,void*x);
void mostrar_grabar_deudores(void*deudor,void*arbol,void*x,void*y);
int comparar_clave(const void*,const void*);
int comparar_fecha(const void*,const void*);
int comparar_clave_deu(const void*,const void*);
int comparar_num(const void*,const void*);


#endif // INDICE_H_INCLUDED
