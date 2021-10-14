
#ifndef LOCALIDAD_H_
#define LOCALIDAD_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "BibliotecaUTN.h"
#include "Cliente.h"

typedef struct
{
	int idLocalidad;
	char nombrelocalidad[100];
	char direccion[100];
	int isEmpty;

}Localidad;


int modificarLocalidad(Cli listaClientes[], Localidad listaLocalidades[]);
void inicializarLocalidad(Localidad listaLocalidad[]);



#endif /* LOCALIDAD_H_ */
