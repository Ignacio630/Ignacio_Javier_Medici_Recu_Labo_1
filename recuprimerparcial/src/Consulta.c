#include "Consulta.h"
static int IdConsultas();
static int IdConsultas(){
	static int idIncremental = 1000;
	return idIncremental++;
}

void iniciarEstructura(eConsulta* consulta, int tam)
{
	int i;
	if(consulta != NULL && tam > 0)
	{
		for(i=0; i<tam;i++)
		{
			consulta[i].estado = LIBRE;
		}
	}
}
int BuscarLibre(eConsulta consulta[], int tam)
{
	int i;
	int index;
	index = -1;

	for (i=0;i<tam;++i)
	{
		if(consulta[i].estado == LIBRE)
		{
			index = i;
			break;
		}
	}
	return index;
}
int BuscarPorID(eConsulta consulta[], int tam, int id)
{
	int retorno;
	int i;

	retorno  = -1;
	if (consulta != NULL && tam > 0)
	{
		for (i = 0; i < tam; i++)
		{
			if (consulta[i].id == id && consulta[i].estado == OCUPADO)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int altaConsulta(eConsulta consulta[],eMedico medico[],eEspecialidad listaEspecialidad[],eFecha fecha[],int size, int sizeM)
{
	int retorno;
	int flagConsulta;
	int i;
	retorno = -1;
	flagConsulta = BuscarLibre(consulta, size);
	if(consulta != NULL && size > 0)
	{
		for(i=0;i<size;i++)
		{
			if(flagConsulta >= 0)
			{
				consulta[flagConsulta].id = IdConsultas();
				PedirCadena(consulta[flagConsulta].nombre, "Ingrese el nombre del paciente:");
				utn_GetEntero(&fecha[flagConsulta].dia, "Ingresa el dia de la consulta: ", "Error Dia o tipo de dato incorrecto\n", 1, 31, 99);
				utn_GetEntero(&fecha[flagConsulta].mes, "Ingresa el mes de la consulta: ", "Error mes o tipo de dato incorrecto\n", 1, 12, 99);
				utn_GetEntero(&fecha[flagConsulta].anio, "Ingresa el año de la consulta: ", "Error año o tipo de dato incorrecto\n", 0, 4000, 99);
				listarMedicos(medico,listaEspecialidad ,sizeM);
				utn_GetEntero(&consulta[flagConsulta].idMedico, "Ingrese el ID del medico:", "Error, ID o tipo de dato invalido!\n", 1, 5, 99);
				consulta[flagConsulta].estado = OCUPADO;
				retorno = 0;
				printf("ID %d", consulta[flagConsulta].idMedico);
				break;
			}
		}
	}
	return retorno;
}
int modificarConsulta(eConsulta consulta[], eMedico medico[],eEspecialidad listaEspecialidad[] ,eFecha fecha[], int size, int sizeM, int id)
{
	int retorno;
	int opciones;
	retorno = -1;

	utn_GetEntero(&id, "Ingrese el ID de la consulta que desea modificar: ", "Error, ID o tipo de dato incorrecto\n", 1000, 100000,99);
	for(int i=0;i<size;i++)
	{
		if(consulta != NULL && medico != NULL && size > 0 && sizeM > 0)
		{
			if(consulta[i].estado == OCUPADO && consulta[i].id == id)
			{
				do
				{
					opciones = PedirOpciones("|--------MODIFICAR-CONSULTA---------|\n|1.Modificar el nombre del paciente\n|2.Modificar la fecha de la consulta\n|3.Modificar el medico\n|4.Salir\n->Ingrese una opcion: ", "Ups! Opcion invalida!!");

					switch (opciones)
					{
						case 1:
							PedirCadena(consulta[i].nombre, "Ingrese el nombre de modificado: ");
							break;
						case 2:
							utn_GetEntero(&fecha[i].dia, "Ingresa el dia de la consulta: ", "Error Dia o tipo de dato incorrecto\n", 1, 31, 99);
							utn_GetEntero(&fecha[i].mes, "Ingresa el mes de la consulta: ", "Error mes o tipo de dato incorrecto\n", 1, 12, 99);
							utn_GetEntero(&fecha[i].anio, "Ingresa el año de la consulta: ", "Error año o tipo de dato incorrecto\n", 0, 4000, 99);
							break;
						case 3:
							listarMedicos(medico,listaEspecialidad ,sizeM);
							utn_GetEntero(&consulta[i].idMedico, "Ingresar el ID del medico que quiere modificar: ", "Error, ID o tipo de dato incorrecto\n",1,5,99);
							break;
						case 4:
							puts("Saliendo..");
							break;
						default:

							break;
					}
				}while(opciones != 4);
			}
		}
	}

	return retorno;
}
int eliminarConsulta(eConsulta consulta[], int len)
{

	int i;
	char opcion;
	int retorno;
	int id;

	retorno = -1;
	utn_GetEntero(&id, "Ingrese el ID de la consulta que quiere eliminar :", "Error, ID o tipo de dato invalido\n", 1000, 2000, 99);
	if(consulta!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(id == consulta[i].id && consulta[i].estado == OCUPADO)
			{
				printf("Esta seguro que desea eliminar esta consulta?? s/n: ");
				fflush(stdin);
				scanf("%c", &opcion);
				while(opcion != 's' && opcion != 'n')
				{
					printf("Ingrese s si queire eliminar o n si no quiere: ");
					fflush(stdin);
					scanf("%c", &opcion);
				}
				if(opcion == 's')
				{
					consulta[i].estado = LIBRE;
					retorno = 0;
				}
			}
		}
	}
	return retorno;
}

