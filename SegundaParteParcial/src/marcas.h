/*
 * marcas.h
 *
 *  Created on: 13 oct. 2021
 *      Author: Asus
 */

#ifndef MARCAS_H_
#define MARCAS_H_

typedef struct{

	int id;
	char descripcion[20];

} eMarcas;

/*
 * mostrarMarcas recibe array de marcas y el tamanio. Se encarga de mostrar las marcas ya hardcodeadas.
 */
void mostrarMarcas(eMarcas marcas[], int tam);

/*
 *  mostrarUnaMarca recibe de las estructuras eMarcas, solo una posicion. Se encarga de mostrar las marcas
 *  en esa posicion
 */
void mostrarUnaMarca(eMarcas unaMarca);

/*
 * validarIdMarca es una funcion de validacion. Si el id que recibe por parametros es valido, devuelve 1
 * sino devuelve 0.
 */
int validarIdMarca(int id, eMarcas marca[], int tam);

/*
 * cargarDescripcion marca utiliza el ID que recibe por parametro, para copiar la descripcion de ese mismo
 * ID en una variable de tipo string, que tambien es un parametro y la guarda ahi. Devuelve 1 si pudo, 0 si
 * no pudo hacerlo.
 */
int cargarDescripcionMarca(int id, eMarcas marca[], int tam, char descr[]);

int validarDescripcionMarca(char descripcion[], eMarcas marca[], int tam);

int cargarIdPorDescripcion(char descr[], eMarcas marca[], int tam, int* idMarca);


#endif /* MARCAS_H_ */
