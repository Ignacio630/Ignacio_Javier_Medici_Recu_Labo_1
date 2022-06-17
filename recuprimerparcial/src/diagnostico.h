#ifndef DIAGNOSTICO_H_
#define DIAGNOSTICO_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct
{
	int id;
	char diagnostico[20];
}typedef eDiagnostico;

int cargarDiagnosticoConsulta(eDiagnostico[], int, int, char[]);

int listarDiagnosticos(eDiagnostico[], int);

int HardcodeoEspecialidad(eDiagnostico[],int);
#endif /* DIAGNOSTICO_H_ */
