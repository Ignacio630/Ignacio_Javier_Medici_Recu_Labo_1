#include "especialidad.h"


int cargarEspecialidadMedico(eEspecialidad listaEspecialidades[], int size, int idEspecialidad, char especialidad[])
{
	int retorno;
	retorno = -1;


	if(listaEspecialidades != NULL && size > 0)
	{
		for(int i=0;i<size;i++)
		{
			if(listaEspecialidades[i].id == idEspecialidad)
			{
				strcpy(especialidad, listaEspecialidades[i].especialidad);
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int listarEspecialdiades(eEspecialidad listaEspecialidades[], int size)
{
	int retorno;
	retorno = -1;

	if(listaEspecialidades != NULL && size > 0)
	{
		puts("|------------LISTA-ESPECIALIDADES------------|\n");
		puts("|ID:   |Especialidades:\t");
		for(int i=0;i<size;i++)
		{
			printf("|%-5d|%-15s|\n",listaEspecialidades[i].id,listaEspecialidades[i].especialidad);
		}
	}

	return retorno;
}


int HardcodeoEspecialidad(eEspecialidad listaEspecialidades[],int size)
{
	int retorno;
	retorno = -1;
	if(listaEspecialidades != NULL && size > 4)
	{
		eEspecialidad especialidad[3]={
							{100,"Cardiologo"},
							{101,"Clinico"},
							{102,"Neumonologo"}
		};
		for(int i=0;i<5;i++)
		{
			listaEspecialidades[i] = especialidad [i];
		}
		retorno = 0;
	}

	return retorno;
}
