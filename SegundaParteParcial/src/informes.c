/*
 * informes.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "informes.h"

int listarAvionesBoeing(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM){

    int idMarca = 1000;
    int todoOK = 0;
    int flag = 1;
    char descripcionMarca[20];

    cargarDescripcionMarca(idMarca, marc, tamM, descripcionMarca);

    printf("\n\t\t\tListado de Aviones de Marca: %s\t\t\t\n\n", descripcionMarca);
    printf("ID\tMATRICULA\tASIENTOS	MARCA\t  	VIAJE\t 	MODELO\t FECHA\n");
    printf("------------------------------------------------------------------------------------------");
    printf("\n\n");

    if(aviones != NULL && viaje != NULL && marc != NULL && tam > 0 && tamV > 0 && tamM > 0){

        for(int i = 0; i < tam; i++){

        	if(aviones[i].idMarca == idMarca && aviones[i].isEmpty == 0){

        		mostrarUnAvion(aviones[i], viaje, tamV, marc, tamM);
        		printf("\n");
        		todoOK = 1;
        		flag = 0;
        	}
        }
        if(flag){
            printf("\nNo hay aviones ingresados de marca : %s", descripcionMarca);
            todoOK = 1;
        }
    }
    return todoOK;
}

int listarAvionesMarca(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM){

    int idMarca;
    int todoOK = 0;
    char ingresoDescripcion[20];
    int flag = 1;

    mostrarMarcas(marc, tamM);
    printf("\nIngrese el ID de la marca para mostrar los aviones de esa marca: ");
    fflush(stdin);
    scanf("%d", &idMarca);
    while(validarIdMarca(idMarca, marc, tamM) != 1){
        printf("\nID invalido. Reingrese ID de la marca: ");
        fflush(stdin);
        scanf("%d", &idMarca);
    }
    printf("\n\n");

    cargarDescripcionMarca(idMarca, marc, tamM, ingresoDescripcion);

    printf("\n\t\t\tListado de Aviones de Marca: %s\t\t\t\n\n", ingresoDescripcion);
    printf("ID\tMATRICULA\tASIENTOS	MARCA\t  	VIAJE\t 	MODELO\t FECHA\n");
    printf("------------------------------------------------------------------------------------------");
    printf("\n\n");

    if(aviones != NULL && viaje != NULL && marc != NULL && tam > 0 && tamV > 0 && tamM > 0){

        for(int i = 0; i < tam; i++){

        	if(aviones[i].idMarca == idMarca && aviones[i].isEmpty == 0){

        		mostrarUnAvion(aviones[i], viaje, tamV, marc, tamM);
        		printf("\n");
        		todoOK = 1;
        		flag = 0;
        	}
        }
        if(flag){
            printf("\nNo hay aviones ingresados de marca : %s", ingresoDescripcion);
            todoOK = 1;
        }
    }
    return todoOK;
}

int listarAvionesNeuquen(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM){

    int todoOK = 0;
    char descripcion[20];
    int flag = 1;
    char descripcionMarca[20];


    cargarDescripcionViaje(102, viaje, tamV, descripcion);

    printf("\t\t\t\nListado de Aviones que viajaron a: %s\t\t\t\n\n", descripcion);
    printf("\tMATRICULA\t MARCA\t\n");
    printf("\t------------------------------");
    printf("\n\n");


    if(aviones != NULL && viaje != NULL && marc != NULL && tam > 0 && tamV > 0 && tamM > 0){

        for(int i = 0; i < tam; i++){

            if(aviones[i].idViaje == 102 && aviones[i].isEmpty == 0){

            	cargarDescripcionMarca(aviones[i].idMarca, marc, tamM, descripcionMarca);

            	printf("\t%d 		%s", aviones[i].matricula, descripcionMarca);
                printf("\n");
                todoOK = 1;
                flag = 0;
            }
        }
        if(flag){
            printf("\nNo hay aviones ingresados que viajen a: %s", descripcion);
            todoOK = 1;
        }
    }
    printf("\n");
    return todoOK;
}

int kmsTotalesATR(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM){

	int todoOK = 0;
	float acuKilometros = 0;
	float totalATR;
	int flag = 0;
	char descripcionMarca[20];

	if(aviones != NULL && tam > 0 && tamV > 0 && viaje != NULL && marc != NULL && tamM > 0){

		for(int a = 0; a < tam; a++){

			if(aviones[a].idMarca == 1002 && aviones[a].isEmpty == 0){

				for(int v = 0; v < tamV; v++){

					if(aviones[a].idViaje == viaje[v].idViaje){

						acuKilometros += viaje[v].kms;
						flag = 1;
						todoOK = 1;
					}
				}
			}
			totalATR = acuKilometros;
		}

		cargarDescripcionMarca(1002, marc, tamM, descripcionMarca);

		if(flag){

			printf("\n-------------------------------------------------------------\n");
			printf("Marca que recorrio los kilometros: ");
			printf("%s\n", descripcionMarca);
			printf("Kilometros recorridos: %.2f Kms", totalATR);
			printf("\n-------------------------------------------------------------\n");
			printf("\n");
		}
		else{
			printf("\nNo hay ningun avion para mostrar de marca ATR");
			todoOK = 1;
		}
	}
	return todoOK;
}

int cantidadAsientosPorModelo(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM){

	int todoOK = 0;
	int acuAsientos = 0;
	int flag = 0;
	int idModelo;

	mostrarAviones(aviones, tam, viaje, tamV, marc, tamM);
	printf("\nIngrese el anio de modelo del avion: ");
	fflush(stdin);
	scanf("%d", &idModelo);
	while(validarIdModelo(idModelo, aviones, tam) == 0){
		printf("\nModelo no existente. Reingrese modelo del avion: ");
		fflush(stdin);
		scanf("%d", &idModelo);
	}

	if(aviones != NULL && tam > 0 && tamV > 0 && viaje != NULL && marc != NULL && tamM > 0){

		for(int a = 0; a < tam; a++){

			if(aviones[a].isEmpty == 0 && aviones[a].modelo == idModelo){

				acuAsientos += aviones[a].cantAsientos;
				todoOK = 1;
				flag = 1;

			}
		}

		if(flag){

			printf("\nLa cantidad total de asientos de los aviones del modelo %d es: %d asientos\n\n", idModelo, acuAsientos);
		}
		else{
			printf("\nNo existen aviones del modelo %d", idModelo);
		}
	}
	return todoOK;

}

int promedioKmsEnFecha(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM){

	int todoOK = 0;
	float acuKilometros = 0;
	float promedioKilometros = 0;
	int contAviones = 0;
	int flag = 0;
	int cantidad = 0;
	eFecha fecha;

	mostrarAviones(aviones, tam, viaje, tamV, marc, tamM);
	printf("\nIngrese una fecha, con formato DD/MM/AAAA, utilizando los '/': ");
	fflush(stdin);
	cantidad = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
	while(cantidad != 3){

		printf("\nIngrese una fecha, con formato DD/MM/AAAA, utilizando los '/': ");
		fflush(stdin);
		cantidad = scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
	}

	if(aviones != NULL && tam > 0 && tamV > 0 && viaje != NULL && marc != NULL && tamM > 0){



		for(int a = 0; a < tam; a++){

			if(aviones[a].fecha.dia == fecha.dia && aviones[a].fecha.mes == fecha.mes && aviones[a].fecha.anio == fecha.anio &&
					aviones[a].isEmpty == 0){

				for(int v = 0; v < tamV; v++){

					if(aviones[a].idViaje == viaje[v].idViaje){

						acuKilometros += viaje[v].kms;
						contAviones++;
						flag = 1;
						todoOK = 1;
					}
				}
			}
		}

		promedioKilometros = (float) acuKilometros / contAviones;

		if(flag){

			printf("\n\n-------------------------------------------------------------------------\n");
			printf("El promedio de Kilometros recorridos en la fecha %d/%02d/%d: %.2f Kms", fecha.dia, fecha.mes, fecha.anio, promedioKilometros);
			printf("\nSe realizaron %d viajes en esa fecha.", contAviones);
			printf("\n-------------------------------------------------------------------------\n");
		}

		else{
			printf("\nNo existe ningun avion con fecha de viaje %d/%02d/%d", fecha.dia, fecha.mes, fecha.anio);
			todoOK = 1;
		}
	}
	return todoOK;
}
