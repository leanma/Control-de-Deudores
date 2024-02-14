#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arbol.h"



typedef struct s_nodo
{
  void* info;
  size_t tam;
  struct s_nodo *sig, *ant;
}t_nodo;

typedef t_nodo* t_lista;


typedef int(*Cmp) (const void*,const void*);
typedef void(*Accionn) (void*,void*);
typedef void(*Accionn2) (void*,void*,void*,void*);
typedef int(*Copiar) (void*,void*,size_t,int);

void crear_lista(t_lista*pl);
void vaciar_lista(t_lista*pl);
int poner_lista_doble_orden(t_lista*pl,void*pd,size_t tam,Cmp cmp);
void recorrer_lista(t_lista*pl,Accionn accion,void* param);
int eliminar_lista(t_lista*pl,void*pd,size_t tam,Cmp cmp);
void ordenar_lista(t_lista*pl,Cmp cmp);

#endif // LISTA_H_INCLUDED
