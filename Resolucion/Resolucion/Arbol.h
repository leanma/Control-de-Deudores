#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Control.h"

typedef struct s_nodoa
{
  void* info;
  size_t tam;
  struct s_nodoa *izq, *der;
}t_nodoa;

typedef t_nodoa* t_arbol;

typedef int(*Cmp) (const void*,const void*);
typedef void(*Accionn) (void*,void*);
typedef void(*Accionn2) (void*,void*,void*,void*);
typedef int(*Copiar) (void*,void*,size_t,int);

void crear_arbol(t_arbol*pa);
void vaciar_arbol(t_arbol*pa);
int cargar_arbol_arch(t_arbol*pa,char*path,size_t tam);
int copiar_arbol_arch(void*dest,void*orig,size_t tam,int pos);
int cargar_arbol_gen(t_arbol*pa,void*orig,size_t tam,int li,int ls, Copiar copiar_dato);
void recorrer_arbol_orden(t_arbol*pa,Accionn accion,void* param);
void buscar_indice(t_arbol* pa,void* pd,size_t tam,Cmp cmp);

#endif // ARBOL_H_INCLUDED
