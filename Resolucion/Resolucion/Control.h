#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Arbol.h"
#include "Lista.h"
#include "Indice.h"

#include "../Cadena/Cadena.h"
#include "../Fecha/Fecha.h"
#include "../Solucion/Solucion.h"

#define PATH_CLI        1
#define PATH_PAGOS      2
#define PATH_LISTADO    3

#define MEN(x,y) (x)<(y)?(x):(y)
#define TODOO_OK        1
#define ERROR_ARCH      0
#define ERROR_SIN_MEM   0


typedef struct
{
	int dia;
	int mes;
	int anio;
}t_fecha;


typedef struct
{
	int nro_cliente;
	char nombre[201];
}cliente;

typedef struct
{
	int nro_cliente;
	char nro_factura[14];
	Fecha fecha_vencimiento;
	Fecha fecha_pago;
	double importe;
}pago;


typedef struct
{
	int nro_cliente;
	int cant_fact_impagas_fuera_term;
}facturas_impagas_fuera_term;



typedef int(*Cmp) (const void*,const void*);
typedef void(*Accionn) (void*,void*);
typedef void(*Accionn2) (void*,void*,void*,void*);
typedef int(*Copiar) (void*,void*,size_t,int);


void procesarPagos_ALU(char* arch_cli,char* arch_pagos,char* arch_ind);


#endif // CONTROL_H_INCLUDED
