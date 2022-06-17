#include "listar.h"

void listarConsulta(eConsulta consulta[],eMedico medico[],eEspecialidad listaEspecialidad[],eFecha fecha[],int size,int sizeM, int sizeD)
{
	int idMedico;
	printf("|Id   |Nombre\t |Fecha\t    |Nombre Medico |Especialidad  |\n");
	for(int i = 0;i<size;i++)
	{
		idMedico = asignarMedico(consulta[i], medico, sizeM);
		if(idMedico > -1)
		{
			if(consulta[i].estado == OCUPADO)
			{
				printf("|%-5d|%-10s|%d/%d/%-4d|%-14s|%-14s|\n", consulta[i].id,consulta[i].nombre,fecha[i].dia,fecha[i].mes,fecha[i].anio,medico[idMedico].nombre,listaEspecialidad[i].especialidad);
			}
		}
	}
}
void listarMedicos(eMedico medicos[],eEspecialidad especialidad[], int size)
{
	if(medicos != NULL && size >0)
	{
		puts("|-----------------------MEDICOS-----------------------|");
		for(int i=0;i<size;i++)
		{
			printf("|ID:%5d|Nombre:%10s|Especialidad: %12s|\n",medicos[i].id,medicos[i].nombre,especialidad[i].especialidad);
		}
	}
}
