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
	Localidad listaLocalidades[20];

	inicializarClientes(listaClientes);
	inicializarPedido(listaPedidos);
	inicializarLocalidad(listaLocalidades);

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
				estadoAux= modificarLocalidad(listaClientes, listaLocalidades);
				if(estadoAux!=0){
					printf("Se modifico correctamente la localidad del cliente seleccionado\n");
				}else{
					printf("Error al modificar la localidad del cliente seleccionado\n");
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
				imprimirListaClientes(listaClientes,listaPedidos,listaLocalidades);
				idPedido =pedidoRecoleccion(idPedido, listaPedidos,listaClientes);
				system("pause");
				system("cls");
			break;
			case 5:
				//Procesar residuos
				imprimirListaPedidos(listaClientes, listaPedidos,listaLocalidades);
				estadoAux=procesarResiduos(listaPedidos);
				if(estadoAux!=0){
					printf("Pedido procesado corretamente!");
				}
				system("pause");
				system("cls");
			break;
			case 6:
				//Imprimir clientes
				imprimirListaPedidos(listaClientes,listaPedidos,listaLocalidades);
				system("pause");
				system("cls");
			break;
			case 7:
				//Imprimir pedidos pendientes
				imprimirListaPedidosPendientes(listaClientes,listaPedidos,listaLocalidades);
				system("pause");
				system("cls");
			break;
			case 8:
				//Imprimir pedidos procesados
				imprimirListaPedidosProcesados(listaClientes,listaPedidos,listaLocalidades);
				system("pause");
				system("cls");
			break;
			case 9:
				//Listar pedidos por localidad
				imprimirListaPedidosPorLocalidad(listaClientes,listaPedidos,listaLocalidades);
				system("pause");
				system("cls");
			break;
			case 10:
				//Listar promedio de polipropileno reciclado
				imprimirPromedioPP(listaClientes,listaPedidos,listaLocalidades);
				system("pause");
				system("cls");
			break;
			case 11:
				//Cliente con mas pedidos pendiente
				imprimirClienteConMasPendientes(listaClientes,listaPedidos,listaLocalidades);
				system("pause");
				system("cls");
			break;
			case 12:
				//Cliente con mas pedidos completados
				imprimirPromedioPP(listaClientes,listaPedidos,listaLocalidades);
				system("pause");
				system("cls");
			break;
			case 13:
				//CLiente con mas pedidos
				imprimirPromedioPP(listaClientes,listaPedidos,listaLocalidades);
				system("pause");
				system("cls");
			break;

			case 14:
				terminar=confirmar();

			break;
		}
	}while(terminar!='y');
	return EXIT_SUCCESS;
}





