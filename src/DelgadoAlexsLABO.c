#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Localidad.h"
#include "Cliente.h"
#include "Pedido.h"
#include "informes.h"
#include "BibliotecaUTN.h"


int main(void) {
	setbuf (stdout, NULL);
	int idCliente;
	int idPedido;
	idCliente = 0;
	idPedido = 0;
	int estadoAux;
	Cli listaClientes[100];
	Pedido listaPedidos[1000];
	Localidad listaLocalidad[20];
	inicializarClientes(listaClientes);
	inicializarPedido(listaPedidos);
	inicializarLocalidad(listaLocalidad);
	int opcionMenu;
	char terminar='n';
	do{
		opcionMenu = menu();
		switch(opcionMenu){
			case 1:
				//Alta cliente
				idCliente=altaCliente(listaClientes,idCliente);
				if(idCliente!=0){
					printf("Se agrego el cliente %d correctamente\n", idCliente);
				}else{
					printf("Error al dar de alta al cliente. \n");
				}
				system("pause");
				system("cls");
			break;
			case 2:
				//Modificar datos cliente
				estadoAux=modificarCliente(listaClientes);
				if(estadoAux!=0){
					printf("Se modifico correctamente el cliente seleccionado\n");
				}else{
					printf("Error al modificar el cliente seleccionado\n");
				}

				system("pause");
				system("cls");
			break;
			case 3:
				//Baja de cliente
				estadoAux=bajaCliente(listaClientes);
				if(estadoAux!=0){
					printf("Se elimino correctamente el cliente seleccionado\n");
				}else{
					printf("Error al eliminar el cliente seleccionado\n");
				}
				system("pause");
				system("cls");
			break;
			case 4:
				//Crear pedido recoleccion
				imprimirListaClientes(listaClientes,listaPedidos);
				idPedido =pedidoRecoleccion(idPedido, listaPedidos,listaClientes);
				system("pause");
				system("cls");
			break;
			case 5:
				//Procesar residuos
				imprimirListaPedidos(listaClientes, listaPedidos);
				estadoAux=procesarResiduos(listaPedidos);
				if(estadoAux!=0){
					printf("Pedido procesado corretamente!");
				}
				system("pause");
				system("cls");
			break;
			case 6:
				//Imprimir clientes
				imprimirListaPedidos(listaClientes,listaPedidos);
				system("pause");
				system("cls");
			break;
			case 7:
				//Imprimir pedidos pendientes
				imprimirListaPedidosPendientes(listaClientes,listaPedidos);
				system("pause");
				system("cls");
			break;
			case 8:
				//Imprimir pedidos procesados
				imprimirListaPedidosProcesados(listaClientes,listaPedidos);
				system("pause");
				system("cls");
			break;
			case 9:
				//Listar pedidos por localidad
				imprimirListaPedidosPorLocalidad(listaClientes,listaPedidos);
				system("pause");
				system("cls");
			break;
			case 10:
				//Listar promedio de polipropileno reciclado
				imprimirPromedioPP(listaClientes,listaPedidos);
				system("pause");
				system("cls");
			break;
			case 11:
				terminar=confirmar();

			break;
		}
	}while(terminar!='y');
	return EXIT_SUCCESS;
}





