#include "Indice.h"

void mostrar_indice(void*indice,void*x)
{
  t_indice ind=*(t_indice*)indice;
  printf("%d\t%d\n",ind.nro_cliente,ind.nro_reg);
}


void mostrar_grabar_deudores(void*deudor,void*arbol,void*x,void*y)
{
  facturas_impagas_fuera_term deu=*(facturas_impagas_fuera_term*)deudor;
  t_arbol* pa=(t_arbol*)arbol;
  t_indice ind;
  ind.nro_cliente=deu.nro_cliente;
  cliente cli_act;

  buscar_indice(pa,&ind,sizeof(t_indice),comparar_clave);


  FILE*arch=(FILE*)x;
  fseek(arch,sizeof(cliente)*ind.nro_reg,SEEK_SET);
  fread(&cli_act,sizeof(cliente),1,arch);

  printf("%d\t%-30s\t%-4d\n",deu.nro_cliente,cli_act.nombre,deu.cant_fact_impagas_fuera_term);

  FILE*arch_txt=(FILE*)y;
  fprintf(arch_txt,"%d\t%s\t%d\n",deu.nro_cliente,cli_act.nombre,deu.cant_fact_impagas_fuera_term);
}


int comparar_clave(const void*x,const void*y)
{
  t_indice indx=*(t_indice*)x;
  t_indice indy=*(t_indice*)y;

  return indx.nro_cliente-indy.nro_cliente;
}


int comparar_fecha(const void*x,const void*y)
{
  t_fecha fx=*(t_fecha*)x;
  t_fecha fy=*(t_fecha*)y;

  if(fx.anio>fy.anio)
    return 1;
  if(fx.anio<fy.anio)
    return -1;
  if(fx.mes>fy.mes)
    return 1;
  if(fx.mes<fy.mes)
    return -1;
  if(fx.dia>fy.dia)
    return 1;
  if(fx.dia<fy.dia)
    return -1;
  return 0;
}


int comparar_clave_deu(const void*x,const void*y)
{
  facturas_impagas_fuera_term factx=*(facturas_impagas_fuera_term*)x;
  facturas_impagas_fuera_term facty=*(facturas_impagas_fuera_term*)y;

  return factx.nro_cliente-facty.nro_cliente;

}

int comparar_num(const void*x,const void*y)
{
  facturas_impagas_fuera_term factx=*(facturas_impagas_fuera_term*)x;
  facturas_impagas_fuera_term facty=*(facturas_impagas_fuera_term*)y;

  return factx.cant_fact_impagas_fuera_term-facty.cant_fact_impagas_fuera_term;
}
