#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "Cliente.h"

void inicializarClientes(Cli listaClientes[])
{
    for(int i=0; i<100; i++)
    {
        listaClientes[i].isEmpty = 0;
    }
}


int altaCliente(Cli listaClientes[],int id){
    id++;
    if(id>100 || listaClientes[id].isEmpty==1){
    	printf("No se pueden generar clientes");
    	return 0;
    }else{
    	listaClientes[id].idCliente=id;
        getString(listaClientes[id].nombreEmpresa,"Ingresar nombre de la empresa", 100);
        listaClientes[id].CUIT= ingresarEntero("Ingresa el CUIT de la empresa");

    	//getString(listaClientes[id].direccion,"Ingresar direccion de la empresa", 100);
    	//getString(listaClientes[id].localidad,"Ingresar localidad de la empresa", 100);

    	listaClientes[id].isEmpty = 1;

    	return id;
    }

}


int bajaCliente(Cli listaClientes[]){
    int i;
    int idClienteSeleccionado;
    int estadoBaja;
    char confirmacionUsuario;
    estadoBaja = 0;

    idClienteSeleccionado = ingresarEntero("Ingrese el ID del cliente a eliminar");

    for(i=0;i<100;i++)
    {
        if(listaClientes[i].isEmpty==1 && listaClientes[i].idCliente==idClienteSeleccionado)
        {
        	confirmacionUsuario=confirmar();
        	if(confirmacionUsuario=='y'){
        		listaClientes[i].isEmpty=0;
        		estadoBaja = 1;
        	}
        	break;
        }
    }
    return estadoBaja;
}

int validarIdCliente(int id, Cli listaCliente[]){
	int i;
	int estadoValidacion;
	estadoValidacion = 0;
	for(i=0;i<100;i++){
		if(listaCliente[i].idCliente == id){
			estadoValidacion=1;
			break;
		}
	}
	return estadoValidacion;
}

int contadorClientes(Cli listaClientes[]){
	int i;
	float contadorClientes;
	contadorClientes =0;
	for(i=0;i<100;i++){
		if(listaClientes[i].isEmpty !=0){
			contadorClientes++;
		}
	}
	return contadorClientes;
}
