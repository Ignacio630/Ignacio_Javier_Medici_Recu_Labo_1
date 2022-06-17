//INCLUDE
#include "utn_funciones.h"
#include "Consulta.h"
#include "menuConsulta.h"
#include "diagnostico.h"
#include "especialidad.h"
#include "medicos.h"
#include "listar.h"
//DEFINE
#define TAM 20
#define TAM_M 5
#define TAM_D 3
#define TAM_E 3
//CUERPO
int main(void)
{
	setbuf(stdout,NULL);
	int opciones;
	int contadorConsulta;
	contadorConsulta = 0;

	///Se crea el vector de la estructura
	eConsulta listaConsulta[TAM];
	eMedico listaMedico[TAM_M];
	eFecha listaFecha[TAM];
	eDiagnostico listaDiagnostico[TAM_D];
	eEspecialidad listaEspecialidades[TAM_E];
	///Se inicializan todos los campos en 0
	iniciarEstructura(listaConsulta, TAM);

	HardcodeoMedicos(listaMedico, TAM_M);
	HardcodeoEspecialidad(listaEspecialidades,TAM_E);
	HardcodeoDiagnostico(listaDiagnostico, TAM_D);
	///Menu de opciones
	do
	{
		///Menu
		opciones = PedirOpciones("1.ALTA CONSULTA\n2.MODIFICAR CONSULTA\n3.CANCELAR CONSULTA\n4.DIAGNOSTICAR\n5.LISTAR\n6.SALIR\nIngrese una opcion:", "Opcion invalida!!\n");
		///Funcionalidad Menu
		switch (opciones) {
			case 1:
			///Alta Consulta
				if(!altaConsulta(listaConsulta ,listaMedico ,listaEspecialidades ,listaFecha ,TAM,TAM_M))
				{
					puts("Se dio de alta correctamente!\n");
					contadorConsulta++;
				}
				else
				{
					puts("Error, no se pudo dar de alta!\n");
				}

			break;
			case 2:
			///Modificar Consulta
			if(contadorConsulta > 0)
			{
				modificarConsulta(listaConsulta ,listaMedico ,listaFecha ,TAM ,TAM_M ,listaConsulta->id );
			}
			else
			{
				puts("No se ingreso ningun dato!!");
			}
			break;
			case 3:
			///Cancelar Consulta
			if(contadorConsulta > 0)
			{
				if(!eliminarConsulta(listaConsulta, TAM))
				{
					puts("Se elimino el pasajero correctamente");
					contadorConsulta--;
				}
				else
				{
					puts("Error, ID incorrecto o inexistente");
				}
			}
			else
			{
				puts("No se ingreso ningun dato!!");
			}
			break;

			case 4:
			///Diagnosticar Consulta
			if(contadorConsulta > 0)
			{
				diagnosticarConsulta(listaDiagnostico, TAM_D, listaConsulta.idDiagnostico, listaDiagnostico.diagnostico);
				puts("Se ingreso el diagnostico con exito!!");
			}
			else
			{
				puts("No se ingreso ningun dato!!");
			}
			break;
			case 5:
			///Listar
			if(contadorConsulta > 0)
			{
				switch (menuConsulta()) {
					case 'a':
						listarMedicos(listaMedico, TAM_M);
						break;
					case 'b':
						listarConsulta(listaConsulta, listaMedico, listaFecha, TAM, TAM_M);
						break;
					case 'c':
						listarDiagnosticos(listaDiagnostico, TAM_D);
						break;
					case 'd':

						break;
					case 'e':

						break;
					case 'f':

						break;
					case 'g':

						break;
					case 'h':

						break;
					case 'i':

						break;
					case 'j':

						break;
					case 'm':

						break;
					default:
						puts("Ups! Opcion invalida!!\n");
						break;
				}
			}
			else
			{
				puts("No se ingreso ningun dato!!");
			}
			break;
			case 6:
			///Salida Del Programa
				puts("Gracias por usar mi app!! :)\n");
			break;
		}
		system("cls");
	}while(opciones != 6);


	return EXIT_SUCCESS;
}
