#ifndef SOLUCION2DOPARCIALCENTROTELE
#define SOLUCION2DOPARCIALCENTROTELE

#include "../Fecha/Fecha.h"


typedef struct
{
	int nroCliente;
	char nombre[201];
}
Cliente;


typedef struct
{
	int nroCliente;
	int nroReg;
}
IndCli;


typedef struct
{
	int nroCliente;
	char nroFactura[14];
	Fecha fechaVencimiento;
	Fecha fechaPago;
	double importe;
}
Pago;


typedef struct
{
	int nroCliente;
	int cantFactImpagasFueraTerm;
}
FacturasImpagasFueraTerm;


void generarArchivoClientes(const char* path);
void generarArchivoPagos(const char* path);
void mostrarArchivoClientes(const char* path);
void mostrarArchivoClientesIdx(const char* path);
void mostrarArchivoPagos(const char* path);
void procesarPagos(const char* pathCli, const char* pathPagos, const char* pathListado);


#endif // SOLUCION2DOPARCIALCENTROTELE
