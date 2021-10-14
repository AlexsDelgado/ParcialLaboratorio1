#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "Localidad.h"
#include "Cliente.h"

void inicializarLocalidad(Localidad listaLocalidad[])
{
    for(int i=0; i<100; i++)
    {
        listaLocalidad[i].isEmpty = 0;
    }
}


int modificarLocalidad(Cli listaClientes[], Localidad listaLocalidades[]){
    int i;
    int idClienteSeleccionado;
    int estadoModificacion;
    estadoModificacion = 0;

    idClienteSeleccionado = ingresarEntero("Ingrese el ID del cliente a modificar");

    for(i=0;i<100;i++)
    {
        if(listaClientes[i].isEmpty==1 && listaClientes[i].idCliente==idClienteSeleccionado)
        {
			getString(listaLocalidades[i].direccion,"Ingresar la nueva direccion de la empresa", 100);
			getString(listaLocalidades[i].nombrelocalidad,"Ingresar la nueva localidad de la empresa", 100);
			estadoModificacion = 1;
			break;
        }
    }
    return estadoModificacion;
}
