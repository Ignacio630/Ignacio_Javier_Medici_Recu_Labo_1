#include "menuConsulta.h"

int menuConsulta()
{
	char opciones;

	printf("a.Todos los médicos.\n");
	printf("b.Todas las consultas.\n");
	printf("c.Todos los médicos con consultas diagnosticadas.\n");
	printf("d.Listado de consultas ordenadas por fecha, desde la más reciente hasta la más antigua.\n");
	printf("e.Listado de consultas que ya fueron diagnosticadas.\n");
	printf("f.Listado de las consultas diagnosticadas con covid-19 desde el inicio de la pandemia hasta la actualidad. Pero solo de una especialidad ingresada\n");
	printf("g.Listado de consultas ordenadas por especialidad alfabéticamente\n");
	printf("h.Listado de todas las consultas entre el mes de abril y julio para una especialidad determinada.\n");
	printf("i.Porcentaje de consultas diagnosticadas que atiende cada médico en función del total de diagnósticos.\n");
	printf("j.La enfermedad menos diagnosticada.\n");
	printf("k.La especialidad más estudiada por los médicos.\n");
	printf("l.\n");
	printf("m.Salir");

	printf("Ingresar una opcion: ");
	fflush(stdin);
	scanf("%c", &opciones);
	return opciones;
}




