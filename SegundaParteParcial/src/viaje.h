/*
 * viaje.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Asus
 */

#ifndef VIAJE_H_
#define VIAJE_H_

typedef struct{

	int idViaje;
	char descripcion[25];
	float kms;

} eViaje;

/*
 * mostrarViajes recibe el array de viajes y el tamanio, y muestra los viejes hardcodeados
 */
void mostrarViajes(eViaje viajes[], int tam);

/*
 *  mostrarUnViaje recibe una unica posicion de tipo eViaje la cual se va a mostrar
 */
void mostrarUnViaje(eViaje unViaje);

/*
 *  validarIdViajes recibe un parametro de ID, el cual recorriendo el array que tambien recibe junto con
 *  su tamanio, va a verificar si pertence a un ID existente. Devuelve 1 si se encontro, 0 si no.
 */
int validarIdViajes(int id, eViaje viajes[], int tam);

/*
 *  cargarDescripcion recibe parametro de ID, el cual recorriendo el array que tambien recibe junto con su
 *  tamanio, va a cargar la descripcion en otra variable de tipo string que recibe la funcion. Devuelve 1 si
 *  se pudo, 0 si no se pudo.
 */
int cargarDescripcionViaje(int id, eViaje viajes[], int tam, char descr[]);


#endif /* VIAJE_H_ */
