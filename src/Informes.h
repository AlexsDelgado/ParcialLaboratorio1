#ifndef INFORMES_H_
#define INFORMES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Cliente.h"
#include "Pedido.h"
#include "BibliotecaUTN.h"
#include "Localidad.h"



int menu();
void imprimirListaPedidos(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]);
void imprimirListaClientes(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]);
void imprimirListaPedidosPendientes(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]);
void imprimirListaPedidosProcesados(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]);
void imprimirListaPedidosPorLocalidad(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]);
void imprimirPromedioPP(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]);
void imprimirClienteConMasPendientes(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]);


#endif /* INFORMES_H_ */
