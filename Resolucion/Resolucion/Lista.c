#include "Lista.h"







void crear_lista(t_lista*pl)
{
  *pl=NULL;
}

void vaciar_lista(t_lista*pl)
{
  t_nodo*elim;

  if(!*pl)
    return;

  while((*pl)->ant)
    *pl=(*pl)->ant;

  while(*pl)
  {
    elim=*pl;
    *pl=elim->sig;
    free(elim->info);
    free(elim);
  }
}

int poner_lista_doble_orden(t_lista*pl,void*pd,size_t tam,Cmp cmp)
{
  t_nodo*aux_sig=*pl;
  t_nodo*aux_ant=aux_sig?aux_sig->ant:NULL;

  while(aux_ant && cmp(pd,aux_ant->info)<0)
  {
    aux_sig=aux_ant;
    aux_ant=aux_ant->ant;
  }

  while(aux_sig && cmp(pd,aux_sig->info)>0)
  {
    aux_ant=aux_sig;
    aux_sig=aux_sig->sig;
  }

  if((aux_ant && cmp(pd,aux_ant->info)==0) || (aux_sig && cmp(pd,aux_sig->info)==0))
    return 0;

  t_nodo*nue=(t_nodo*)malloc(sizeof(t_nodo));
  if(!nue)
    return ERROR_SIN_MEM;
  nue->info=malloc(tam);
  if(!nue->info)
  {
    free(nue);
    return ERROR_SIN_MEM;
  }

  memcpy(nue->info,pd,tam);
  nue->tam=tam;
  nue->sig=aux_sig;
  nue->ant=aux_ant;

  if(aux_ant)
    aux_ant->sig=nue;
  if(aux_sig)
    aux_sig->ant=nue;
  *pl=nue;
  return TODOO_OK;
}

void recorrer_lista(t_lista*pl,Accionn accion,void* param)
{
  if(!*pl)
    return;

  while((*pl)->ant)
    *pl=(*pl)->ant;

  while(*pl)
  {
    accion((*pl)->info,param);
    *pl=(*pl)->sig;
  }
}



int eliminar_lista(t_lista*pl,void*pd,size_t tam,Cmp cmp)
{
  t_nodo*elim=*pl;

  while(elim && cmp(pd,elim->info)<0)
    elim=elim->ant;
  while(elim && cmp(pd,elim->info)>0)
    elim=elim->sig;
  if(!elim || cmp(pd,elim->info)!=0)
  {
    return 0;
  }

  if(elim->sig)
    elim->sig->ant=elim->ant;
  if(elim->ant)
    elim->ant->sig=elim->sig;
  *pl=elim->sig?elim->sig:elim->ant;

  memcpy(pd,elim->info,MEN(tam,elim->tam));
  free(elim->info);
  free(elim);
  return TODOO_OK;
}




void ordenar_lista(t_lista*pl,Cmp cmp)
{
  t_lista lord=NULL;
  t_lista*plord;
  t_nodo*nodo;
  if(!*pl)
    return;
  while((*pl)->ant)
    *pl=(*pl)->ant;
  while(*pl)
  {
    nodo=*pl;
    *pl=nodo->sig;
    plord=&lord;
    t_nodo*aux_sig=*plord;
    t_nodo*aux_ant=aux_sig?aux_sig->ant:NULL;

    while(aux_sig && cmp(nodo->info,aux_sig->info)<0)
    {
      aux_ant=aux_sig;
      aux_sig=aux_sig->sig;
    }
    nodo->sig=aux_sig;
    nodo->ant=aux_ant;
    if(aux_ant)
      aux_ant->sig=nodo;
    if(aux_sig)
      aux_sig->ant=nodo;
    *plord=nodo;
  }
  *pl=lord;
}


