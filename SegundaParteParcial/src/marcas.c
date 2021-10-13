/*
 * marcas.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "marcas.h"

void mostrarMarcas(eMarcas marcas[], int tam){

    printf("\n\t\tMarcas\n\n");
    printf("\tID Marca\t\tDescripcion\n");
    printf("\t--------------------------------------------------\n\n");

    for(int i = 0; i < tam; i++){

       mostrarUnaMarca(marcas[i]);
       printf("\n");
    }
    printf("\n\n");
}

void mostrarUnaMarca(eMarcas unaMarca){

    printf("\t%d\t\t\t%-10s", unaMarca.id, unaMarca.descripcion);

}

int validarIdMarca(int id, eMarcas marca[], int tam){

    int valido = 0;

    if(marca != NULL && tam > 0 && id >= 1000 && id <= 1003){

        for(int i = 0; i < tam; i++){
            if(marca[i].id == id){
                valido = 1;
                break;
            }
        }
    }
    return valido;
}

int cargarDescripcionMarca(int id, eMarcas marca[], int tam, char descr[]){

    int todoOK = 0;

    if(marca != NULL && tam > 0 && descr != NULL && id >= 1000 && id <= 1003){

        for(int i = 0; i < tam; i++){
            if(marca[i].id == id){
                strcpy(descr, marca[i].descripcion);
                todoOK = 1;
                break;
            }
        }
    }

    return todoOK;
}

int validarDescripcionMarca(char descripcion[], eMarcas marca[], int tam){

	int valido = 0;

	if(marca != NULL && tam > 0 && descripcion != NULL){

		for(int i = 0; i < tam; i++){

			if(stricmp(marca[i].descripcion, descripcion) == 0){
				valido = 1;
				break;
			}
		}
	}
	return valido;

}

int cargarIdPorDescripcion(char descr[], eMarcas marca[], int tam, int* idMarca){

	int valido = 0;

	if(marca != NULL && tam > 0 && descr != NULL){

		for(int i = 0; i < tam; i++){

			if(stricmp(marca[i].descripcion, descr) == 0){

				*idMarca = marca[i].id;
				valido = 1;
				break;
			}
		}
	}
	return valido;

}
