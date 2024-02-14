#include "Control.h"

void recorrer_lista_2(t_lista*pl,Accionn2 accion,t_arbol*pa,void* param,void*param2);

void procesarPagos_ALU(char* path_cl,char* path_pa,char* path_lis)
{
  int r;
  t_fecha f_impaga;
  f_impaga.dia=1;
  f_impaga.mes=1;
  f_impaga.anio=1900;

  char path_cli_idx[strlen(path_cl)];
  strcpy(path_cli_idx,path_cl);
  char* punto = strchr(path_cli_idx,'.');
  *punto = '\0';
  strcat(path_cli_idx,".idx");


  t_arbol arbol;
  t_lista lista;
  crear_arbol(&arbol);
  crear_lista(&lista);

  r=cargar_arbol_arch(&arbol,path_cli_idx,sizeof(t_indice));
  if(r!=TODOO_OK)
    return;


  FILE*arch_cli=fopen(path_cl,"rb");
  if(!arch_cli)
    return;
  FILE*arch_pago=fopen(path_pa,"rb");
  if(!arch_pago)
  {
    fclose(arch_cli);
    return;
  }
  FILE*arch_lis=fopen(path_lis,"wt");
  if(!arch_lis)
  {
    fclose(arch_cli);
    fclose(arch_pago);
    return;
  }


  pago pago_act;
  t_indice ind_act;
  facturas_impagas_fuera_term deu_act;

  fread(&pago_act,sizeof(pago),1,arch_pago);

  while(!feof(arch_pago))
  {
    ind_act.nro_cliente=pago_act.nro_cliente;
    ind_act.nro_reg=-1;
    buscar_indice(&arbol,&ind_act,sizeof(t_indice),comparar_clave);

    if(ind_act.nro_reg!=-1)
    {
      if(comparar_fecha(&pago_act.fecha_pago,&f_impaga)==0 || comparar_fecha(&pago_act.fecha_pago,&pago_act.fecha_vencimiento)>0)
      {
        deu_act.cant_fact_impagas_fuera_term=1;
        deu_act.nro_cliente=ind_act.nro_cliente;
        if(eliminar_lista(&lista,&deu_act,sizeof(facturas_impagas_fuera_term),comparar_clave_deu)==TODOO_OK)
        {
          deu_act.cant_fact_impagas_fuera_term++;
          poner_lista_doble_orden(&lista,&deu_act,sizeof(facturas_impagas_fuera_term),comparar_clave_deu);
        }
        else
        {
          poner_lista_doble_orden(&lista,&deu_act,sizeof(facturas_impagas_fuera_term),comparar_clave_deu);
        }
      }
    }
    fread(&pago_act,sizeof(pago),1,arch_pago);
  }

  ordenar_lista(&lista,comparar_num);
  ordenar_lista(&lista,comparar_num);

  printf("\nNro. cliente\t Nombre\t\t Factura en mora.\n");

  recorrer_lista_2(&lista,mostrar_grabar_deudores,&arbol,arch_cli,arch_lis);


  vaciar_arbol(&arbol);
  vaciar_lista(&lista);
  fclose(arch_cli);
  fclose(arch_pago);
  fclose(arch_lis);
}




void recorrer_lista_2(t_lista*pl,Accionn2 accion,t_arbol*pa,void* param,void*param2)
{
  if(!*pl)
    return;

  while((*pl)->ant)
    *pl=(*pl)->ant;

  while(*pl)
  {
    accion((*pl)->info,pa,param,param2);
    *pl=(*pl)->sig;
  }
}

