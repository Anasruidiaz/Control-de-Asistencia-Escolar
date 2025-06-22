#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Alumno {
	int dni;
	char nombre[30];
	char apellido[30];
	int presentes;
	int ausentes;
	struct Alumno *sig;
} Alumno;

typedef struct AsistenciaDia {
	int dni;
	char fecha[11]; // formato YYYY-MM-DD
	char estado;    // 'P' o 'A'
	struct AsistenciaDia *sig;
} AsistenciaDia;

Alumno* lista = NULL;
AsistenciaDia* asistencias = NULL;

// Crear nuevo alumno
Alumno* crearAlumno(int dni, char nombre[], char apellido[]) {
	Alumno* nuevo = (Alumno*)malloc(sizeof(Alumno));
	nuevo->dni = dni;
	strcpy(nuevo->nombre, nombre);
	strcpy(nuevo->apellido, apellido);
	nuevo->presentes = 0;
	nuevo->ausentes = 0;
	nuevo->sig = NULL;
	return nuevo;
}

// Agregar alumno a la lista
void agregarAlumno() {
	int dni;
	char nombre[30], apellido[30];
	printf("DNI: "); scanf("%d", &dni);
	printf("Nombre: "); scanf("%s", nombre);
	printf("Apellido: "); scanf("%s", apellido);
	Alumno* nuevo = crearAlumno(dni, nombre, apellido);
	nuevo->sig = lista;
	lista = nuevo;
	printf("Alumno agregado.\n");
}

// Buscar alumno por DNI
Alumno* buscarAlumno(int dni) {
	Alumno* aux = lista;
	while (aux != NULL) {
		if (aux->dni == dni) return aux;
		aux = aux->sig;
	}
	return NULL;
}

// Registrar asistencia por fecha
void registrarAsistenciaPorFecha() {
	int dni;
	char fecha[11], estado;
	printf("DNI del alumno: "); scanf("%d", &dni);
	Alumno* alumno = buscarAlumno(dni);
	if (!alumno) {
		printf("Alumno no encontrado.\n");
		return;
	}
	printf("Fecha (YYYY-MM-DD): "); scanf("%s", fecha);
	printf("Estado (P = Presente, A = Ausente): "); scanf(" %c", &estado);
	
	if (estado == 'P' || estado == 'p') alumno->presentes++;
	else if (estado == 'A' || estado == 'a') alumno->ausentes++;
	else {
		printf("Estado invalido.\n");
		return;
	}
	
	AsistenciaDia* nueva = (AsistenciaDia*)malloc(sizeof(AsistenciaDia));
	nueva->dni = dni;
	strcpy(nueva->fecha, fecha);
	nueva->estado = estado;
	nueva->sig = asistencias;
	asistencias = nueva;
	
	printf("Asistencia registrada.\n");
}




