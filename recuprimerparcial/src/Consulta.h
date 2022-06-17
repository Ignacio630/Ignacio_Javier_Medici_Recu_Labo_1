#ifndef CONSULTA_H_
#define CONSULTA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "utn_funciones.h"
#include "diagnostico.h"
#include "especialidad.h"
#include "medicos.h"
#include "listar.h"
///Define
#define LIBRE 0
#define OCUPADO 1

///Estructura
struct
{
	int dia;
	int mes;
	int anio;
}typedef eFecha;
struct
{
	int id;
	char nombre[50];
	eFecha fecha;
	int estado;
	int idDiagnostico;
	int idMedico;
}typedef eConsulta;
///Funcionalidad
void iniciarEstructura(eConsulta [], int);
int BuscarLibre(eConsulta [], int );
int BuscarPorIDMedico(eMedico[], int , int );

int HardcodeConsultas(eConsulta [], int);
int HardcodeoMedicos(eMedico [], int);
void menuDiagnostico(eConsulta [], int );

/// ABM
int altaConsulta(eConsulta[] ,eMedico[],eEspecialidad[] ,eFecha[] ,int ,int );
int modificarConsulta(eConsulta[] ,eMedico[],eEspecialidad[] ,eFecha[] ,int ,int ,int );
int eliminarConsulta(eConsulta [], int);
int diagnosticarConsultas();
#endif /* CONSULTA_H_ */
