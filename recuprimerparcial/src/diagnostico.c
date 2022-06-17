#include "diagnostico.h"

int cargarDiagnosticoConsulta(eDiagnostico listaDiagnosticos[], int size, int idDiagnostico, char diagnostico[])
{
	int retorno;
	retorno = -1;

	if(listaDiagnosticos != NULL && size > 0)
	{
		for(int i=0;i<size;i++)
		{
			if(listaDiagnosticos[i].id == idDiagnostico)
			{
				strcpy(diagnostico, listaDiagnosticos[i].diagnostico);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}
int listarDiagnosticos(eDiagnostico listaDiagnosticos[], int size)
{
	int retorno;
	retorno = -1;

	if(listaDiagnosticos != NULL && size > 0)
	{
		puts("|------------LISTA-DIAGNOSTICO------------|\n");
		puts("|ID:   |Diagnostico:\t");
		for(int i=0;i<size;i++)
		{
			printf("|%-5d|%-15s|\n",listaDiagnosticos[i].id,listaDiagnosticos[i].diagnostico);
		}
	}
	return retorno;
}

int HardcodeoDiagnostico(eDiagnostico listaDiagnostico[], int size)
{
	int retorno;
	retorno = -1;
	if(listaDiagnostico != NULL && size > 4)
	{
		eDiagnostico diagnosticos[3]={
							{1,"COVID-19"},
							{2,"PRE-INFARTO"},
							{3,"GRIPE-A"}
		};
		for(int i=0;i<5;i++)
		{
			listaDiagnostico[i] = diagnosticos[i];
		}
		retorno = 0;
	}

	return retorno;
}
