#include "Arbol.h"



void crear_arbol(t_arbol*pa)
{
  *pa=NULL;
}


int cargar_arbol_arch(t_arbol*pa,char*path,size_t tam)
{
  FILE*arch=fopen(path,"rb");
  if(!arch)
    return ERROR_ARCH;
  fseek(arch,0l,SEEK_END);
  int cant_reg=ftell(arch)/tam;
  rewind(arch);
  int r=cargar_arbol_gen(pa,arch,tam,0,cant_reg-1,copiar_arbol_arch);
  fclose(arch);
  return r;
}

int copiar_arbol_arch(void*dest,void*orig,size_t tam,int pos)
{
  FILE*arch=(FILE*)orig;
  fseek(arch,tam*pos,SEEK_SET);
  int r=fread(dest,tam,1,arch);
  return r;
}

int cargar_arbol_gen(t_arbol*pa,void*orig,size_t tam,int li,int ls, Copiar copiar_dato)
{
  int m=(li+ls)/2;
  int r;

  if(li>ls)
    return TODOO_OK;

  t_nodoa*nue=(t_nodoa*)malloc(sizeof(t_nodoa));
  if(!nue)
    return ERROR_SIN_MEM;
  nue->info=malloc(tam);
  if(!nue->info)
  {
    free(nue);
    return ERROR_SIN_MEM;
  }

  nue->tam=tam;
  nue->izq=nue->der=NULL;

  if((r=copiar_dato(nue->info,orig,tam,m))==0)
    return r;
  *pa=nue;
  if((r=cargar_arbol_gen(&(*pa)->izq,orig,tam,li,m-1,copiar_dato))!=TODOO_OK)
    return r;
  return cargar_arbol_gen(&(*pa)->der,orig,tam,m+1,ls,copiar_dato);
}

void recorrer_arbol_orden(t_arbol*pa,Accionn accion,void* param)
{
  if(!*pa)
    return;
  recorrer_arbol_orden(&(*pa)->izq,accion,param);
  accion((*pa)->info,param);
  recorrer_arbol_orden(&(*pa)->der,accion,param);
}


void vaciar_arbol(t_arbol*pa)
{
  if(!*pa)
    return;
  vaciar_arbol(&(*pa)->izq);
  vaciar_arbol(&(*pa)->der);
  free((*pa)->info);
  free(*pa);
  *pa=NULL;
}



void buscar_indice(t_arbol* pa,void* pd,size_t tam,Cmp cmp)
{
    if(!*pa)
    return;
  buscar_indice(&(*pa)->izq,pd,tam,cmp);
  if(cmp(pd,(*pa)->info)==0)
  {
    memcpy(pd,(*pa)->info,tam);
    return;
  }
  buscar_indice(&(*pa)->der,pd,tam,cmp);
}
