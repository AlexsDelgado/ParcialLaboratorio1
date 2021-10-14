#ifndef PEDIDO_H_
#define PEDIDO_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "BibliotecaUTN.h"
#include "Cliente.h"


typedef struct
{
	int idPedido;
	int numCliente;
	int estadoPedido;
	float kgTipoPP;
	float kgTipoHDPE;
	float kgTipoLDPE;
	float kgTotal;
	int isEmpty;

}Pedido;

int cantidadPedidosPendientesPorCliente(Cli listaClientes[], Pedido listaPedidos[],int id);
int pedidoRecoleccion(int idPedido, Pedido listaPedidos[], Cli listaClientes[]);
int procesarResiduos(Pedido listaPedidos[]);
int contadorKgPP(Pedido listaPedidos[]);
void inicializarPedido(Pedido listaPedidos[]);
#endif /* PEDIDO_H_ */
