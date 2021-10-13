/*
 * viaje.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "viaje.h"

void mostrarViajes(eViaje viajes[], int tam){

    printf("\n\t\tViajes\n\n");
    printf("\tID \t\tViaje\t\t     Kilometros\n");
    printf("\t--------------------------------------------------\n\n");

    for(int i = 0; i < tam; i++){

       mostrarUnViaje(viajes[i]);
       printf("\n");
    }
    printf("\n\n");
}

void mostrarUnViaje(eViaje unViaje){

    printf("\t%d\t\t%-10s\t\t%.2fKms", unViaje.idViaje, unViaje.descripcion, unViaje.kms);

}

int validarIdViajes(int id, eViaje viajes[], int tam){

    int valido = 0;

    if(viajes != NULL && tam > 0 && id >= 100 && id <= 104){

        for(int i = 0; i < tam; i++){
            if(viajes[i].idViaje == id){
                valido = 1;
                break;
            }
        }
    }
    return valido;
}


int cargarDescripcionViaje(int id, eViaje viajes[], int tam, char descr[]){

    int todoOK = 0;

    if(viajes != NULL && tam > 0 && descr != NULL && id >= 100 && id <= 104){

        for(int i = 0; i < tam; i++){
            if(viajes[i].idViaje == id){
                strcpy(descr, viajes[i].descripcion);
                todoOK = 1;
                break;
            }
        }
    }

    return todoOK;
}


