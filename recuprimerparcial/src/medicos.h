#ifndef MEDICOS_H_
#define MEDICOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "especialidad.h"
struct
{
	int id;
	char nombre[50];
	int idEspecialidad;
	int estado;
}typedef eMedico;

int HardcodeoMedicos(eMedico [], int );

int asignarMedico(eConsulta ,eMedico[],int );
#endif /* MEDICOS_H_ */
