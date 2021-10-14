#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Pedido.h"




void inicializarPedido(Pedido listaPedidos[])
{
    for(int i=0; i<100; i++)
    {
        listaPedidos[i].isEmpty = 0;
    }
}
int pedidoRecoleccion(int idPedido, Pedido listaPedidos[], Cli listaCliente[]){
	idPedido++;
	int idClienteSeleccionado;
	int validacionId;
	float kgRecoleccion;
	do{
		idClienteSeleccionado = ingresarEntero("Ingrese el ID del cliente para la recoleccion\n");
		validacionId=validarIdCliente(idClienteSeleccionado, listaCliente);
	}while(validacionId!=1);
		kgRecoleccion = IngresarFlotante("Ingrese la cantidad de kilos que se recolectaran del cliente \n");




	listaPedidos[idPedido].idPedido=idPedido;
	listaPedidos[idPedido].numCliente=idClienteSeleccionado;
	listaPedidos[idPedido].kgTotal=kgRecoleccion;
	listaPedidos[idPedido].kgTipoHDPE=0;
	listaPedidos[idPedido].kgTipoLDPE=0;
	listaPedidos[idPedido].kgTipoPP=0;

	listaPedidos[idPedido].estadoPedido=0;
	listaPedidos[idPedido].isEmpty=1;


	return idPedido;
}

int procesarResiduos(Pedido listaPedidos[]){


    int i;
    int idPedidoSeleccionado;
    int estadoPedido;
    estadoPedido = 0;
    float aux;
    int banderaValidacion;

    float kgPP;
    float kgHDPE;
	float kgLDPE;

    aux = 0;

    idPedidoSeleccionado = ingresarEntero("Ingrese el ID del pedido a procesar");

    for(i=0;i<1000;i++)
    {
        if(listaPedidos[i].isEmpty==1 && listaPedidos[i].idPedido==idPedidoSeleccionado)
        {
        	if(listaPedidos[i].estadoPedido==1){
        		printf("El pedido ya se encuentra procesado\n");
        	}else{
        		aux=listaPedidos[i].kgTotal;
				do{
					fflush(stdin);
					kgPP=IngresarFlotante("Ingresar cantidad de Kg Plastico PP a procesar\n");

					if(kgPP>aux){
						printf("Error, la cantidad del plastico PP a procesar no puede ser mayor al total del pedido recolectado\n");
						banderaValidacion=0;
					}else{
						banderaValidacion=1;
					}
				}while(banderaValidacion==0);
				listaPedidos[i].kgTipoPP=kgPP;
				aux=aux-kgPP;

				do{
					fflush(stdin);
					kgHDPE=IngresarFlotante("Ingresar cantidad de Kg Plastico HDPE a procesar\n");
						if(kgHDPE>aux){
							printf("Error, la cantidad del plastico HDPE a procesar no puede ser mayor al total del pedido recolectado\n");
						}
				}while(kgHDPE>aux);
				listaPedidos[i].kgTipoHDPE=kgHDPE;
				aux=aux-kgHDPE;

				do{
					kgLDPE=IngresarFlotante("Ingresar cantidad de Kg Plastico LDPE a procesar");
					if(kgLDPE>aux){
						printf("Error, la cantidad del plastico LDPE a procesar no puede ser mayor al total del pedido recolectado");
					}
				}while(kgLDPE>aux);
				listaPedidos[i].kgTipoLDPE=kgLDPE;

				estadoPedido = 1;

				listaPedidos[i].estadoPedido = estadoPedido;
				break;
        	}

        }
    }



	return estadoPedido;
}
int cantidadPedidosPendientesPorCliente(Cli listaClientes[], Pedido listaPedidos[],int id){
	int i;
	int contadorPedidosPendientes;
	contadorPedidosPendientes = 0;
	for(i=0;i<1000;i++){

		if(listaPedidos[i].numCliente == id && listaPedidos[i].isEmpty!=0 && listaPedidos[i].estadoPedido==0){
			contadorPedidosPendientes++;
		}

	}
	return contadorPedidosPendientes;
}


int contadorKgPP(Pedido listaPedidos[]){
	int i;
	float contadorKgPP;
	contadorKgPP =0;
	for(i=0;i<1000;i++){
		if(listaPedidos[i].isEmpty !=0 && listaPedidos[i].estadoPedido!=0){
			contadorKgPP=contadorKgPP+listaPedidos[i].kgTipoPP;
		}
	}
	return contadorKgPP;
}
