#ifndef CLIENTE_H_
#define CLIENTE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "BibliotecaUTN.h"


typedef struct
{
	int idCliente;
	char nombreEmpresa[100];
	int CUIT;
	int idLocalidad;

	int isEmpty;

}Cli;

/// \fn int altaCliente(Cli[], int)
/// \brief Inicializa la estructura Cli en una posicion del array
/// \param listaClientes array de la estructura
/// \param id primary Key autoincremental
/// \return retorna el ID primary Key autoincremental o 0 en el caso de error
int altaCliente(Cli listaClientes[],int id);

/// \fn void inicializarClientes(Cli[])
/// \brief Inicializa el campo isEmpty de la estructura Cli en todo el array
/// \param listaClientes array de la estructura
void inicializarClientes(Cli listaClientes[]);
/// \fn int modificarCliente(Cli[])
/// \brief se pide un id y se lo busca dentro del array para reemplazar campos de la estructura seleccionada
/// \param listaClientes array de la estructura
/// \return retorna 1 en el caso de completar la tarea correctamente
int modificarCliente(Cli listaClientes[]);
/// \fn int bajaCliente(Cli[])
/// \brief se pide id y se lo busca dentro del array para reemplazar el campo isEmpty a 0.
/// \param listaClientes array de la estructura
/// \return re
int bajaCliente(Cli listaClientes[]);
int validarIdCliente(int id, Cli listaCliente[]);
int contadorClientes(Cli listaClientes[]);

#endif /* CLIENTE_H_ */
