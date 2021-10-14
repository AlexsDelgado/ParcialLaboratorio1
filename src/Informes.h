#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Cliente.h"
#include "Pedido.h"
#include "BibliotecaUTN.h"



int menu();
void imprimirListaPedidos(Cli listaClientes[], Pedido listaPedidos[]);
void imprimirListaClientes(Cli listaClientes[], Pedido listaPedidos[]);
void imprimirListaPedidosPendientes(Cli listaClientes[], Pedido listaPedidos[]);
void imprimirListaPedidosProcesados(Cli listaClientes[], Pedido listaPedidos[]);
void imprimirListaPedidosPorLocalidad(Cli listaClientes[], Pedido listaPedidos[]);
void imprimirPromedioPP(Cli listaClientes[], Pedido listaPedidos[]);

#endif /* INFORMES_H_ */
