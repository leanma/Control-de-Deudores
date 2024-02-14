#ifndef FECHA_H
#define FECHA_H


typedef struct
{
	int dia;
	int mes;
	int anio;
}
Fecha;


typedef struct
{
	int mes;
	int anio;
}
Mes;


int esFechaValida(const Fecha* f);
Fecha sumarDiasAFecha(const Fecha* f, unsigned dias);
void sumarDiasAFechaInSitu(Fecha* f, unsigned dias);
int difEnDiasEntreFechas(const Fecha* f1, const Fecha* f2);
int diaDelAnio(const Fecha* f);
int cmpFechas(const Fecha* f1, const Fecha* f2);
int cmpMeses(const Mes* mes1, const Mes* mes2);
Mes getMes(const Fecha* f);
Mes strToMes(const char* str);
int cantDiasMes(int mes, int anio);


#endif // FECHA_H
