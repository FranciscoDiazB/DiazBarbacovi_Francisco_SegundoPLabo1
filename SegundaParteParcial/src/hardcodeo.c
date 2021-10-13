/*
 * hardcodeo.c
 *
 *  Created on: 13 oct. 2021
 *      Author: Asus
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "hardcodeo.h"

int idMarca[12] = {1002,1000,1001,1003,1000,1001,1001,1002,1003,1000,1000,1002};

int idViaje[12] = {104,102,100,102,104,101,100,100,103,102,103,100};

int patente[12] = {676888,456009,875980,567000,4578,9986,125,9990,8975,18750,77777,123456};

int asientos[12] = {10,50,255,80,65,357,225,89,55,14,425,90};

int modelo[12] = {2015,2018,2015,2021,1990,1999,2018,1990,2021,2001,2001,2015};

eFecha fecha[12] =
{
    {22,7,2020},
    {22,7,2020},
    {7,11,2019},
    {8,8,2021},
	{20,4,2020},
	{22,7,2020},
	{17,1,2018},
	{7,11,2019},
	{8,8,2021},
	{20,4,2020},
	{22,10,2017},
	{17,1,2018}
};

int hardcodearAviones(eAviones aviones[], int tam, int cant, int* pId){

    int cantidad = 0;

    if(aviones != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL){

        for(int i = 0; i < cant; i++){

                aviones[i].idAvion = *pId;
                (*pId)++;
                aviones[i].matricula = patente[i];
                aviones[i].idMarca = idMarca[i];
                aviones[i].idViaje = idViaje[i];
                aviones[i].modelo = modelo[i];
                aviones[i].cantAsientos = asientos[i];
                aviones[i].fecha = fecha[i];
                aviones[i].isEmpty = 0;
                cantidad++;
        }
        cantidad++;
    }

    return cantidad;
}
