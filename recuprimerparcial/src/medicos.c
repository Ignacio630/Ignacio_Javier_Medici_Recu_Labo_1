#include "medicos.h"
#include "Consulta.h"

int HardcodeoMedicos(eMedico listaMedicos[], int size)
{
	int retorno;
	retorno = -1;
	if(listaMedicos != NULL && size > 4)
	{
		eMedico medicos[5]={
							{1,"Alberto",1000,OCUPADO},
							{2,"Pedro",1000,OCUPADO},
							{3,"Juan",1000,OCUPADO},
							{4,"Alvaro",1000,OCUPADO},
							{5,"Emmanuel",1000,OCUPADO}
		};
		for(int i=0;i<5;i++)
		{
			listaMedicos[i] = medicos [i];
		}
		retorno = 0;
	}

	return retorno;
}

int asignarMedico(eConsulta consulta ,eMedico listaMedico[],int sizeM)
{
	int retorno;
	retorno = -1;

	for(int j=0;j<sizeM;j++)
	{
		if(consulta.estado == OCUPADO && (consulta.idMedico == listaMedico[j].id))
		{
			retorno = j;
			break;
		}
	}
	return retorno;
}
