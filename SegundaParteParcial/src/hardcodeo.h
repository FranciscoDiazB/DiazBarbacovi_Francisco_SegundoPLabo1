/*
 * hardcodeo.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Asus
 */
#include "aviones.h"

#ifndef HARDCODEO_H_
#define HARDCODEO_H_

/*
 * la funcion lo que hace es recorre el array de aviones haciendo un ingreso automatico de datos, como para
 * que haya datos ingresados sin necesidad de hacer el alta. Cambia su campo isEmty a 0. Devuelve la
 * cantidad aviones que se pudieron cargar.
 */
int hardcodearAviones(eAviones aviones[], int tam, int cant, int* pId);



#endif /* HARDCODEO_H_ */
