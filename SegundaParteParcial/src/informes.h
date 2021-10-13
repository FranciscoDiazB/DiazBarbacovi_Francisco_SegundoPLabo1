/*
 * informes.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Asus
 */
#include "aviones.h"

#ifndef INFORMES_H_
#define INFORMES_H_

int listarAvionesBoeing(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM);

int listarAvionesMarca(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM);

int listarAvionesNeuquen(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM);

int kmsTotalesATR(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM);

int cantidadAsientosPorModelo(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM);

int promedioKmsEnFecha(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM);


#endif /* INFORMES_H_ */
