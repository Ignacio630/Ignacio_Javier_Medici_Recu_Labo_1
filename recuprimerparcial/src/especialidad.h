#ifndef ESPECIALIDAD_H_
#define ESPECIALIDAD_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct{
	int id;
	char especialidad[50];
}typedef eEspecialidad;


int cargarEspecialidadMedico(eEspecialidad[], int, int, char[]);

int listarEspecialdiades(eEspecialidad[], int);

int HardcodeoEspecialidad(eEspecialidad[],int);
#endif /* ESPECIALIDAD_H_ */
