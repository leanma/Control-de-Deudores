#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Control.h"


int main(int argc, char* argv[])
{
	generarArchivoClientes(argv[PATH_CLI]);
	generarArchivoPagos(argv[PATH_PAGOS]);

	mostrarArchivoClientes(argv[PATH_CLI]);

	char nombreIdx[201];
	reemplazarSubcad(argv[PATH_CLI], ".dat", ".idx", nombreIdx, 201);
	mostrarArchivoClientesIdx(nombreIdx);

	mostrarArchivoPagos(argv[PATH_PAGOS]);

  procesarPagos_ALU(argv[PATH_CLI], argv[PATH_PAGOS], argv[PATH_LISTADO]);

	return 0;
}


