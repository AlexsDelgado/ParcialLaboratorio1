#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ingresarEntero(char mensaje[]){   //ok pide operando
	int entero;
	printf("%s",mensaje);
	do{
		scanf("%d",&entero);
		fflush(stdin);
	}while(isdigit(entero));
	return entero;
}

int getString(char cadena[], char mensaje[], int tam)
{
	char auxiliarString[1000];
	int retorno;
	retorno = 0;
	if (cadena != NULL && mensaje != NULL)
	{
		retorno = 1;
		printf(mensaje);
		fflush(stdin);
		gets(auxiliarString);
		while (strlen(auxiliarString) > tam)
		{
			printf("Reingrese: ");
			fflush(stdin);
			gets(auxiliarString);
		}
		strcpy(cadena, auxiliarString);
	}
	return retorno;
}

float IngresarFlotante(char mensaje[])
{
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}

char confirmar(){//menu opc de salir
	char salir;
		fflush(stdin);
		printf("¿Desea confirmar esta accion? (Y/N)\n");
		scanf("%c",&salir);
		fflush(stdin);
	while(salir!='y' && salir!='n'){
		printf("Error al seleccionar una opcion.\n ¿Desea confirmar esta accion? (Y/N)\n");
		scanf("%c",&salir);
		fflush(stdin);
	}
	return salir;
}

