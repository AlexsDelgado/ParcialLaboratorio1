#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Informes.h"




int menu(){ //printf de las opciones y recupera la deseada
	int opcionMenu;
	printf("\n *********************************\nIngrese: \n 1_Alta de cliente\n 2_ Modificar datos cliente \n 3_ Baja de cliente \n 4_ Crear pedido recoleccion\n 5_ Procesar residuos\n 6_ Imprimir clientes\n 7_ Imprimir pedidos pendientes\n 8_ Imprimir pedidos procesados\n 9_ Pedidos pendientes por localidad\n 10_ Promedio Kg polipropileno\n 11_ Salir \n *********************************\n ");
	scanf("%d",&opcionMenu);
	fflush(stdin);
	while(opcionMenu<1 || opcionMenu>11){
		system("cls");
		printf("Error al seleccionar la opcion. \n\n *********************************\nIngrese: \n 1_Alta de cliente A\n 2_ Modificar datos cliente B\n 3_ Baja de cliente \n 4_ Crear pedido recoleccion\n 5_ Procesar residuos\n 6_ Imprimir clientes\n 7_ Imprimir pedidos pendientes\n 8_ Imprimir pedidos procesados\n 9_ Pedidos pendientes por localidad\n 10_ Promedio Kg polipropileno\n 11_ Salir \n *********************************\n");
		scanf("%d",&opcionMenu);
		fflush(stdin);
	}
	return opcionMenu;
}
void imprimirListaClientes(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]){
	int i;
	int cantidadPedidosPendientes;
	printf("ID\tNombre\t\tCUIT\t\tDireccion\t\tLocalidad\t\tPedidos pendientes\n");
	for(i=0;i<100;i++){
		if(listaClientes[i].isEmpty!=0){
			cantidadPedidosPendientes = cantidadPedidosPendientesPorCliente(listaClientes,listaPedidos,listaClientes[i].idCliente);
			printf("%d\t%-15s\t%d\t\t%-20s\t%-20s\t\t%d \n \n", listaClientes[i].idCliente, listaClientes[i].nombreEmpresa, listaClientes[i].CUIT,listaLocalidades[i].direccion, listaLocalidades[i].nombrelocalidad, cantidadPedidosPendientes);

		}
	}
}
void imprimirListaPedidos(Cli listaClientes[], Pedido listaPedidos[],Localidad listaLocalidades[]){
	//
	int i;
	int idForeignKey;
	int banderaVacio;
	banderaVacio=0;
	char estadoPedido[50] ={};

	for(i=0;i<1000;i++){
		if(listaPedidos[i].isEmpty!=0){
			banderaVacio=1;
			idForeignKey = listaPedidos[i].numCliente;
			if(listaPedidos[i].estadoPedido==0){
				 strcpy(estadoPedido, "Se encuentra pendiente");
			}else{
				strcpy(estadoPedido, "Pedido ya procesado");
			}

			printf("Pedido n° %d \n",listaPedidos[i].idPedido);
			printf("\t\t%-15s\t%.2f kg\t%s \n",listaClientes[idForeignKey].nombreEmpresa,listaPedidos[i].kgTotal,estadoPedido);
		}
	}
	if(banderaVacio==0){
		printf("No hay pedidos generados \n");
	}
}

void imprimirListaPedidosPendientes(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]){
	int i;
	int idForeignKey;
	int banderaVacio;
	banderaVacio=0;
	printf("Los pedidos pendientes son: \n");
	for(i=0;i<1000;i++){
		idForeignKey = listaPedidos[i].numCliente;
		if(listaPedidos[i].isEmpty!=0 && listaPedidos[i].estadoPedido==0){
			printf("CUIT: %d\tDireccion %-15s\t%.2f Kg Totales\n",listaClientes[idForeignKey].CUIT,listaLocalidades[idForeignKey].direccion,listaPedidos[i].kgTotal);
			banderaVacio=1;
		}
	}
	if(banderaVacio==0){
		printf("No se encontraron pedidos pendentes!\n");
	}
}

void imprimirListaPedidosProcesados(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]){

	//
	int i;
	int idForeignKey;
	int idForeignKeyLocalidad;
	int banderaVacio;
	banderaVacio = 0;
	for(i=0;i<1000;i++){
		if(listaPedidos[i].isEmpty!=0){
			banderaVacio=1;
			idForeignKey = listaPedidos[i].numCliente;
			idForeignKeyLocalidad = listaClientes[idForeignKey].idLocalidad;
			if(listaPedidos[i].estadoPedido==1){
				printf("Pedido n° %d \n",listaPedidos[i].idPedido);
				printf("\t\tCUIT: %d\tDir: %s\tPP: %.2f kg\tHDPE: %.2f kg\tLDPE: %.2f kg \n",listaClientes[idForeignKey].CUIT,
						listaLocalidades[idForeignKeyLocalidad].direccion,
												listaPedidos[i].kgTipoPP,
												listaPedidos[i].kgTipoHDPE,
												listaPedidos[i].kgTipoLDPE
												);
			}
		}
	}
	if(banderaVacio == 0){
		printf("No hay ningun pedido procesado\n");
	}
}

void imprimirListaPedidosPorLocalidad(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]){
	int i;
	int foreignKey;
	int foreignKeyLocalidad;
	char localidad[100];
	int contadorLocalidad;
	contadorLocalidad=0;
	int auxComparar;
    getString(localidad,"Ingresar la localidad deseada", 100);

	for(i=0;i<1000;i++){
		foreignKey= listaPedidos[i].numCliente;
		foreignKeyLocalidad = listaClientes[foreignKey].idLocalidad;
		if(listaPedidos[i].isEmpty!=0){
			//&& listaPedidos[i].estadoPedido==0
			auxComparar=strcmp(listaLocalidades[foreignKeyLocalidad].nombrelocalidad, localidad);
			if(auxComparar==0 && listaPedidos[i].estadoPedido==0 ){
				contadorLocalidad++;
			}
		}
	}
	printf("Cantidad de pedidos pendientes en la localidad de %s : %d \n",localidad,contadorLocalidad);

}
void imprimirPromedioPP(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]){
	int contClientes;
	int contKgPP;
	float promedio;
	contClientes=0;
	contKgPP=0;
	contClientes=contadorClientes(listaClientes);
	contKgPP = contadorKgPP(listaPedidos);

	if(contClientes==0&&contKgPP==0){
		printf("No se puede calcular, primero genere los clientes y pedidos \n");
	}else{
		promedio = (float)(contKgPP/contClientes);
		printf("La cantidad de kilos de polipropileno reclicado promedio por cliente: %.2f\n",promedio);
	}
}

void imprimirClienteConMasPendientes(Cli listaClientes[], Pedido listaPedidos[], Localidad listaLocalidades[]){
	int i;
	int foreignKey;
	int contadorPedidos;
	contadorPedidos=0;
	for(i=0;i<1000;i++){
		foreignKey = listaPedidos[i].numCliente;
		if(listaPedidos[i].estadoPedido==0 && listaClientes[i].idCliente==foreignKey){
			contadorPedidos
		}
	}


	printf("Cantidad de pedidos pendientes en la localidad de %s : %d \n",localidad,contadorLocalidad);

}

