/*
 * aviones.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Asus
 */

#include "marcas.h"
#include "viaje.h"

#ifndef AVIONES_H_
#define AVIONES_H_

typedef struct{

	int dia;
	int mes;
	int anio;

} eFecha;

typedef struct{

	int idAvion;
	int matricula;
	eFecha fecha;
	int idViaje;
	int idMarca;
	int modelo;
	int cantAsientos;
	int isEmpty;

} eAviones;

int validarIdModelo(int id, eAviones aviones[], int tam);

/*
 *  inicializa los campos isEmptys en 1.
 */
void inicializarAviones(eAviones aviones[], int tam);

/*
 *  recorre y cuenta los espacios que estan vacios en el array de aviones. la utilizo como condicion de que
 *  haya datos cargados para que se puedan realizar algunas funciones (mostrar, baja, etc). Devuelve un
 *  contador.
 */
int tenerAvionesCargados(eAviones aviones[], int tam);

/*
 *  recorre y encuentra espacio libre en el array de aviones. Devuelve la posicion habia espacio, sino devuelve
 *  -1
 */
int buscarLibreAvion(eAviones aviones[], int tam);

/*
 *  sinceramente esta no la uso, pero lo que hace es busca un avion en el array de aviones, por medio de un
 *  id que recibe por parametro. Si existe el avion, devuelve el indice, sino devuelve -1.
 */
int buscarAvion(eAviones aviones[], int tam, int id);

/*
 *  primero se fija si hay espacio libre en el array de aviones. Si lo hay, da opcion de ingreso de datos y
 *  le pasa al usuario un numero de identificador dado por el sistema. Al final de todo, cambia el campo
 *  isEmpty de la posicion libre a 0. devuel 1 si se pudo, 0 si no se pudo.
 */
int altaAviones(eAviones aviones[], int tam, eViaje viajes[] , int tamV, eMarcas marca[], int tamM, int* pId);

/*
 *  esta seria la version igual a buscarAvion, pero la que termino utilizando en todas las funciones.
 *  Busca el avion en el array de aviones por medio de la matricula que recibe como parametro. Si existe
 *  el avion devuelve el indice, sino 0.
 */
int buscarMatricula(eAviones aviones[], int tam, int id);

/*
 *  pide el ingreso de una matricula y llama a la funcion buscarMatricula. Si la matricula ingresada existe,
 *  primero te muestra el avion en la posicion esa y te pregunta si quiere seguir con la baja. Si usted
 *  continua con la baja, lo que hace es cambiar el campo isEmpty del avion en el indice ese a 1.
 *  Devuelve 1 si se pudo, sino 0.
 */
int bajaAviones(eAviones aviones[], int tam, eViaje viajes[] , int tamV, eMarcas marca[], int tamM);

/*
 *  pide el ingreso de una matricula y llama a la funcion buscarMatricula. Si la matricula ingresada existe,
 *  primero te muestra el avion en la posicion esa y te pregunta si quiere seguir con la modificacion. Si
 *  usted continua, le da dos opciones de ingreso de datos. Devuelve 1 si se pudo, sino 0.
 */
int modificarAvion(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marca[], int tamM);

/*
 *  recorre el array de aviones y los ordena utilizando un doble criterio de ordenamiento. Primero por
 *  marca y despues por numero de matricula
 */
void ordenarAviones(eAviones aviones[], int tam, eMarcas marcas[], int tamM);

/*
 *  mostrarAviones recorre el array de aviones, y llama a la funciones mostrarUnAvion. Se van a mostrar
 *  todos los aviones que haya cargados, con su descripcion de marca, viaje, id, asientos, etc.
 */
void mostrarAviones(eAviones aviones[], int tam, eViaje viaje[] , int tamV, eMarcas marc[], int tamM);

/*
 *  muestraUnAvion solo en una posicion. Se va a mostrar un avione que haya cargado, en una posicion,
 *  con su descripcion de marca, viaje, id, asientos, etc.
 */
void mostrarUnAvion(eAviones unAvion, eViaje viaje[] , int tamV, eMarcas marc[], int tamM);

#endif /* AVIONES_H_ */
