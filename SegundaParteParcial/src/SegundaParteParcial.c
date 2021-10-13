/*
 ============================================================================
 Name        : SegundaParteParcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aviones.h"
#include "hardcodeo.h"
#include "informes.h"

#define TAMA 15
#define	TAMM 4
#define	TAMV 5

int menu();

int menuInformes();

int main(void) {

	setbuf(stdout, NULL);

	eMarcas marcas[TAMM] = {
			{1000, "Boeing"},
			{1001, "Airbus"},
			{1002, "ATR"},
			{1003, "Bombardier"}};

	eViaje viajes[TAMV] = {
			{100, "Salta", 1462.5},
			{101, "Tucuman", 1247.6},
			{102, "Neuquen", 1139.4},
			{103, "Corrientes", 670},
			{104, "Chubut", 1735.8}};

	eAviones aviones[TAMA];

	char respuesta = 'n';
	int idAviones = 1;
	inicializarAviones(aviones, TAMA);
	hardcodearAviones(aviones, TAMA, 12, &idAviones);

	do {

		switch(menu()){

		case 1:
			if(altaAviones(aviones, TAMA, viajes, TAMV, marcas, TAMM, &idAviones)){
				printf("\nAlta exitosa");
			}
			else{
				printf("\nHubo un problema");
			}
			printf("\n\n");
			system("pause");
			break;

		case 2:
			if(tenerAvionesCargados(aviones, TAMA) != TAMA){
				if(modificarAvion(aviones, TAMA, viajes, TAMV, marcas, TAMM)){
					printf("\nModificacion exitosa");
				}
				else{
					printf("\nHubo un problema");
				}
			}
			else{
				printf("\nSe deben ingresar aviones primero, antes de poder realizar modificaciones");
			}
			printf("\n\n");
			system("pause");
			break;

		case 3:
			if(tenerAvionesCargados(aviones, TAMA) != TAMA){
				if(bajaAviones(aviones, TAMA, viajes, TAMV, marcas, TAMM)){
					printf("\nBaja exitosa");
				}
				else{
					printf("\nHubo un problema");
				}
			}
			else{
				printf("\nSe deben ingresar aviones primero, antes de poder realizar bajas");
			}
			printf("\n\n");
			system("pause");
			break;

		case 4:
			if(tenerAvionesCargados(aviones, TAMA) != TAMA){
				printf("\n");
				mostrarAviones(aviones, TAMA, viajes, TAMV, marcas, TAMM);
			}
			else{
				printf("\nSe deben ingresar aviones primero, antes de poder listarlos");
			}
			printf("\n\n");
			system("pause");
			break;

		case 5:
			printf("\n");
			mostrarViajes(viajes, TAMV);
			printf("\n\n");
			system("pause");
			break;

		case 6:
			printf("\n");
			mostrarMarcas(marcas, TAMM);
			printf("\n\n");
			system("pause");
			break;

		case 7:
			if(tenerAvionesCargados(aviones, TAMA) != TAMA){

				switch(menuInformes())
				{
				case 1:
					if(listarAvionesBoeing(aviones, TAMA, viajes, TAMV, marcas, TAMM) == 0){
						printf("\nHubo un problema\n");
					}

					break;

				case 2:
					if(listarAvionesMarca(aviones, TAMA, viajes, TAMV, marcas, TAMM) == 0){
						printf("\nHubo un problema");
					}
					break;

				case 3:
					if(listarAvionesNeuquen(aviones, TAMA, viajes, TAMV, marcas, TAMM) == 0){
						printf("\nHubo un problema");
					}
					break;

				case 4:
					if(kmsTotalesATR(aviones, TAMA, viajes, TAMV, marcas, TAMM) == 0){
						printf("\nHubo un problema");
					}
					break;

				case 5:
					if(cantidadAsientosPorModelo(aviones, TAMA, viajes, TAMV, marcas, TAMM) == 0){
						printf("\nHubo un problema");
					}
					break;

				case 6:
					if(promedioKmsEnFecha(aviones, TAMA, viajes, TAMV, marcas, TAMM) == 0){
						printf("\nHubo un problema");
					}
					break;

				default:
					printf("\n");
					printf("Dato invalido. Reingrese numero de opcion\n");
				}
			}
			else{
				printf("\nSe debe hacer el alta de por lo menos un avion, antes de poder realizar informes");
			}
			printf("\n\n");
			system("pause");
			break;

		case 8:
			printf("\nEsta seguro que desea salir? Oprima la tecla 's' desea salir\n");
			printf("De lo contrario oprima la tecla 'n' (minuscula)");
			fflush(stdin);
			respuesta = getchar();
			printf("\n\n");
			break;

		default:
			printf("\n");
			printf("Dato invalido. Reingrese letra (en mayuscula)\n");
			system("pause");

		}

	} while(respuesta == 'n');

	return EXIT_SUCCESS;
}

int menu(){

	int opcion;

	printf("\n");
	printf("\t\t**** ABM ****");
	printf("\n\n\n");
	printf("1. ALTA AVION\n");
	printf("2. MODIFICAR AVION\n");
	printf("3. BAJA AVION\n");
	printf("4. LISTAR AVIONES\n");
	printf("5. LISTAR VIAJES\n");
	printf("6. LISTAR MARCAS\n");
	printf("7. INFORMES\n");
	printf("8. SALIR\n\n\n");

	printf("Ingrese la opcion correspondiente: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;

}

int menuInformes()
{

	int opcion;

	printf("\n");
	printf("\t\t**** INFORMES COMPLEMENTARIOS****");
	printf("\n\n\n");
	printf("1. MOSTRAR TODOS LOS AVIONES BOEING\n");
	printf("2. MOSTRAR AVIONES DE UNA MARCA SELECCIONADA\n");
	printf("3. MOSTRAR MATRICULA Y MARCA DE LOS AVIONES QUE VIAJARON A NEUQUEN\n");
	printf("4. INFORMAR LOS KMS TOTALES RECORRIDOS EN AVIONES ATR\n");
	printf("5. INFORMAR CANTIDAD TOTAL DE ASIENTOS PARA UN MODELO DE AVION SELECCIONADO\n");
	printf("6. PROMEDIO DE KMS PARA LOS AVIONES QUE VIAJARON EN UNA FECHA SELECCIONADA\n\n\n");

	printf("Ingrese el numero de la opcion correspondiente: ");
	fflush(stdin);
	scanf("%d", &opcion);

	return opcion;
}
