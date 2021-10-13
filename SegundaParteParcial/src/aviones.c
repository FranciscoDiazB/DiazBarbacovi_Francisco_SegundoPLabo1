/*
 * aviones.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "aviones.h"

void inicializarAviones(eAviones aviones[], int tam){

	for(int i = 0; i < tam; i++){

	   aviones[i].isEmpty = 1;
	}
}

int validarIdModelo(int id, eAviones aviones[], int tam){

    int valido = 0;

    if(aviones != NULL && tam > 0 && id > 1950){

        for(int i = 0; i < tam; i++){
            if(aviones[i].modelo == id){
                valido = 1;
                break;
            }
        }
    }
    return valido;
}

int tenerAvionesCargados(eAviones aviones[], int tam){

	int acu = 0;

	for(int i = 0; i < tam; i++){

		if(aviones[i].isEmpty == 1){
			acu++;
		}
	}
	return acu;
}

int buscarLibreAvion(eAviones aviones[], int tam){

	int retorno = -1;

	for(int i = 0; i < tam; i++){

		if(aviones[i].isEmpty){
			retorno = i;
			break;
		}
	}
	return retorno;
}

int buscarAvion(eAviones aviones[], int tam, int id){

    int indice = -1;

    if(aviones != NULL && tam > 0){
        for(int i = 0; i < tam; i++){

            if(aviones[i].idAvion == id && aviones[i].isEmpty == 0){

                indice = i;
                break;
            }
        }
    }
    return indice;
}

void mostrarUnAvion(eAviones unAvion, eViaje viaje[] , int tamV, eMarcas marc[], int tamM){

	char descripcionViaje[20];
	char descripcionMarca[20];

	if(cargarDescripcionViaje(unAvion.idViaje, viaje, tamV, descripcionViaje) &&
	   cargarDescripcionMarca(unAvion.idMarca, marc, tamM, descripcionMarca)){

		printf("%d\t%d	\t%d	\t%-10s\t%-10s\t%d\t%d/%02d/%d\n",
				unAvion.idAvion,
				unAvion.matricula,
				unAvion.cantAsientos,
				descripcionMarca,
				descripcionViaje,
				unAvion.modelo,
				unAvion.fecha.dia,
				unAvion.fecha.mes,
				unAvion.fecha.anio);
	}

}

void mostrarAviones(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM){

	int flag = 1;

	printf("\t\t\tListado de Aviones\t\t\t\n\n");
	printf("ID\tMATRICULA\tASIENTOS	MARCA\t  	VIAJE\t 	MODELO\t FECHA\n");
	printf("------------------------------------------------------------------------------------------");
	printf("\n\n");

	ordenarAviones(aviones, tam, marc, tamM);

	for(int i = 0; i < tam; i++){

		if(aviones[i].isEmpty == 0){
			mostrarUnAvion(aviones[i], viaje, tamV, marc, tamM);
			printf("\n");
			flag = 0;
		}
	}
	if(flag){
		printf("No hay Aviones que mostrar");
    }

}

int buscarMatricula(eAviones aviones[], int tam, int id){

    int indice = -1;

    if(aviones != NULL && tam > 0){

    	for(int i = 0; i < tam; i++){

            if(aviones[i].matricula == id && aviones[i].isEmpty == 0){

                indice = i;
                break;
            }
        }
    }
    return indice;
}

int altaAviones(eAviones aviones[], int tam, eViaje viajes[] , int tamV, eMarcas marca[], int tamM, int* pId){

	int todoOK = 0;
	int indice;

	printf("\t\tAlta Aviones\n\n");
	printf("El numero de identificacion del avion es : %d", *pId);
	printf("\n\n");

	if(aviones != NULL && tam > 0 && pId != NULL && viajes != NULL && tamM > 0 && tamV > 0 && marca != NULL){

		indice = buscarLibreAvion(aviones, tam);

		if(indice == -1){
			printf("No hay lugar en el sistema\n");
		}
		else{

			printf("Ingrese Matricula (numeros mayores a 0): ");
			fflush(stdin);
			scanf("%d", &aviones[indice].matricula);
			printf("\n");
			while(aviones[indice].matricula < 1){
				printf("Invalido. Ingrese Matricula (numeros mayores a 0): ");
				fflush(stdin);
				scanf("%d", &aviones[indice].matricula);
			}

			printf("Ingrese el Anio del modelo (a partir del anio 1950): ");
			fflush(stdin);
			scanf("%d", &aviones[indice].modelo);
			printf("\n");
			while(aviones[indice].modelo < 1950){
				printf("Anio invalido. Reingrese modelo (a partir del anio 1950): ");
				fflush(stdin);
				scanf("%d", &aviones[indice].modelo);
				printf("\n");
			}

			mostrarViajes(viajes, tamV);
			printf("Ingrese Id del viaje: ");
			scanf("%d", &aviones[indice].idViaje);
			while(validarIdViajes(aviones[indice].idViaje, viajes, tamV) != 1){
				printf("Id invalido. Reingrese Id del viaje: ");
				scanf("%d", &aviones[indice].idViaje);
			}

			mostrarMarcas(marca, tamM);
			printf("Ingrese el Id de la marca: ");
			fflush(stdin);
			scanf("%d", &aviones[indice].idMarca);
			while(validarIdMarca(aviones[indice].idMarca, marca, tamM) != 1){

				printf("Invalido. Ingrese el Id de la marca: ");
				scanf("%d", &aviones[indice].idMarca);
			}
			printf("\n");

			printf("Ingrese la cantidad de asientos (mayor o igual a 5): ");
			fflush(stdin);
			scanf("%d", &aviones[indice].cantAsientos);
			printf("\n");
			while(aviones[indice].cantAsientos < 5){
				printf("Invalido. Ingrese la cantidad de asientos (mayor o igual a 5): ");
				fflush(stdin);
				scanf("%d", &aviones[indice].cantAsientos);
				printf("\n");
			}

			printf("\nIngrese la fecha, con formato DD/MM/AAAA, utilizando tambien los '/' (a partir del anio 2015/menor o igual al 2021) : ");
			fflush(stdin);
			scanf("%d/%d/%d", &aviones[indice].fecha.dia, &aviones[indice].fecha.mes, &aviones[indice].fecha.anio);
			printf("\n");
			while(aviones[indice].fecha.dia > 31 || aviones[indice].fecha.dia < 1 || aviones[indice].fecha.mes > 12 ||
					aviones[indice].fecha.mes < 1 || aviones[indice].fecha.anio < 2015 || aviones[indice].fecha.anio > 2021 )
			{
				printf("\nFecha invalida. Ingrese la fecha, con formato DD/MM/AAAA, utilizando tambien los '/' (a partir del anio 2015/4menor o igual al 2021) : ");
				fflush(stdin);
				scanf("%d/%d/%d", &aviones[indice].fecha.dia, &aviones[indice].fecha.mes, &aviones[indice].fecha.anio);
				printf("\n");
				system("pause");
				printf("\n");
			}


			aviones[indice].idAvion = *pId;
			(*pId)++;
			aviones[indice].isEmpty = 0;

			todoOK = 1;

		}
	}

	return todoOK;
}

int bajaAviones(eAviones aviones[], int tam, eViaje viajes[] , int tamV, eMarcas marca[], int tamM){

	int todoOk = 0;
	int indice = -1;
	int idAvion;
	char respuesta;

	printf("\n\t\t\tBaja Aviones\n");
	mostrarAviones(aviones, tam, viajes, tamV, marca, tamM);

	printf("\nIntroduzca numero de Matricula del avion: ");
	fflush(stdin);
	scanf("%d", &idAvion);
	printf("\n");
	while(buscarMatricula(aviones, tam, idAvion) == -1){
		printf("Dato invalido. Reintroduzca numero de Matricula: ");
		fflush(stdin);
		scanf("%d", &idAvion);
	}

	if(aviones != NULL && tam > 0 && viajes != NULL && tamV > 0 && marca !=  NULL && tamM > 0){

		indice = buscarMatricula(aviones, tam, idAvion);

		if(indice == -1){

			printf("No existe un avion con ese numero de matricula : %d", idAvion);
		}
		else{
			mostrarUnAvion(aviones[indice], viajes, tamV, marca, tamM);
			printf("\n\nEste es el avion que busca? Marque 's' para Si y 'n' para No (en minuscula).\n");
			fflush(stdin);
			respuesta = getchar();
			if(respuesta == 's'){

				aviones[indice].isEmpty = 1;
				todoOk = 1;
			}
			else{
				printf("Baja cancelada por el usuario");
			}
		}
	}
	return todoOk;
}

int modificarAvion(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marca[], int tamM){

	int todoOK = 0;
	int indice;
	int introducirId;
	char respuesta;
	int opcionModificar;

	printf("\n\t\t\tModificar Aviones\n");
	mostrarAviones(aviones, tam, viaje, tamV, marca, tamM);

	printf("\nIntroduzca numero de Matricula del avion: ");
	fflush(stdin);
	scanf("%d", &introducirId);
	if(buscarMatricula(aviones, tam, introducirId) == -1){
		printf("\n\nNo existen aviones con esa Matricula\n");
		printf("Reingrese numero de Matricula: ");
		fflush(stdin);
		scanf("%d", &introducirId);
	}
	printf("\n");

	if(aviones != NULL && tam > 0 && tamV > 0 && viaje != NULL && marca != NULL && tamM > 0){

		indice = buscarMatricula(aviones, tam, introducirId);

		if( indice == -1){
			printf("\nNo hay aviones para modificar");
		}
		else{
			mostrarUnAvion(aviones[indice], viaje, tamV, marca, tamM);

			printf("\n\nDesea seguir con la modificacion? Marque 's' para Si y 'n' para No (en minuscula).\n");
			fflush(stdin);
			respuesta = getchar();

			if(respuesta == 's'){
				printf("\n1. Modificar Modelo\n");
				printf("2. Modificar Cantidad de asientos\n");
				printf("\nIngrese el numero correspondiente a la caracteristica que desea modificar: ");
				fflush(stdin);
				scanf("%d", &opcionModificar);

				switch(opcionModificar){

				case 1:
					printf("Ingrese nuevo anio de modelo del avion (a partir de 1950): ");
					fflush(stdin);
					scanf("%d", &aviones[indice].modelo);
					while(aviones[indice].modelo < 1950){
						printf("Modelo invalido. Reingrese (a partir de 1950): ");
						fflush(stdin);
						scanf("%d", &aviones[indice].modelo);
					}
					todoOK = 1;
					break;

				case 2:
					printf("Ingrese nueva cantidad de asientos (mayores a 5): ");
					fflush(stdin);
					scanf("%d", &aviones[indice].cantAsientos);
					while(aviones[indice].cantAsientos < 5){
						printf("Cantidad Invalida. Ingrese nueva cantidad de asientos (mayores a 5): ");
						fflush(stdin);
						scanf("%d", &aviones[indice].cantAsientos);
					}
					todoOK = 1;
					break;

				default:
					printf("Dato invalido");
					break;

				}
			}
			else{
				printf("\nModificacion cancelada por el usuario");
			}
		}

	}
	return todoOK;

}

void ordenarAviones(eAviones aviones[], int tam, eMarcas marcas[], int tamM){

	eAviones aux;

	for(int i = 0; i < tam - 1; i++){

		for(int j = i + 1; j < tam; j++){

			if(aviones[i].idMarca > aviones[j].idMarca){

				aux = aviones[i];
				aviones[i] = aviones[j];
				aviones[j] = aux;
			}
			if(aviones[i].idMarca == aviones[j].idMarca && aviones[i].matricula > aviones[j].matricula){

				aux = aviones[i];
				aviones[i] = aviones[j];
				aviones[j] = aux;
			}
		}
	}

}
