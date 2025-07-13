#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
int matricula;
char nombre[50];
float promedio;
} Alumno;

void GuardaAlumnos(FILE *arch);
void CargaAlumnos(FILE *arch, Alumno alu[], int *n);
void ImprimeAlumnos(const Alumno alu[], int n);
void OrdenaPorNombre(Alumno alu[], int n);
void OrdenaPorPromedio(Alumno alu[], int n);

void main() {
FILE *archAlumnos;
Alumno listaAlumnos[100];
int numAlumnos = 0;
int opcion;

do {
printf("\n--- GESTION DE ALUMNOS ---\n");
printf(" 1. Guardar nuevos alumnos\n");
printf(" 2. Cargar alumnos existentes del archivo\n");
printf(" 3. Imprimir alumnos (orden original de carga)\n");
printf(" 4. Imprimir alumnos (orden alfabetico por nombre)\n");
printf(" 5. Imprimir alumnos (orden por promedio)\n");
printf(" 0. Salir del programa\n");
printf("Ingrese su opcion: ");
scanf("%d", &opcion);
fflush(stdin);

switch (opcion) {
case 1:
archAlumnos = fopen("alumnos.dat", "wb");
if (archAlumnos == NULL) {
printf("No se pudo abrir el archivo para escritura.\n");
} else {
GuardaAlumnos(archAlumnos);
fclose(archAlumnos);
printf("Alumnos guardados en 'alumnos.dat'.\n");
}
break;

case 2:
numAlumnos = 0;
archAlumnos = fopen("alumnos.dat", "rb");
if (archAlumnos == NULL) {
printf("El archivo 'alumnos.dat' no existe o no se pudo abrir.\n");
} else {
CargaAlumnos(archAlumnos, listaAlumnos, &numAlumnos);
fclose(archAlumnos);
printf("Se cargaron %d alumnos del archivo.\n", numAlumnos);
}
break;

case 3:
if (numAlumnos > 0) {
ImprimeAlumnos(listaAlumnos, numAlumnos);
} else {
printf("No hay alumnos cargados. Primero cargue el archivo (opcion 2).\n");
}
break;

case 4:
if (numAlumnos > 0) {
OrdenaPorNombre(listaAlumnos, numAlumnos);
printf("\n--- LISTADO DE ALUMNOS ORDENADOS POR NOMBRE ---\n");
ImprimeAlumnos(listaAlumnos, numAlumnos);
} else {
printf("No hay alumnos para ordenar. Cargue el archivo primero (opcion 2).\n");
}
break;

case 5:
if (numAlumnos > 0) {
OrdenaPorPromedio(listaAlumnos, numAlumnos);
printf("\n--- LISTADO DE ALUMNOS ORDENADOS POR PROMEDIO ---\n");
ImprimeAlumnos(listaAlumnos, numAlumnos);
} else {
printf("No hay alumnos para ordenar. Cargue el archivo primero (opcion 2).\n");
}
break;

case 0:
printf("Finalizando el programa. !Hasta pronto!\n");
break;

default:
printf("Opcion no valida. Por favor, intente de nuevo.\n");
}
} while (opcion != 0);
}

void GuardaAlumnos(FILE *arch) {
Alumno unAlumno;
char resp;

printf("\n--- INGRESAR NUEVOS ALUMNOS ---\n");
do {
printf("Matricula: ");
scanf("%d", &unAlumno.matricula);
fflush(stdin);

printf("Nombre: ");
fgets(unAlumno.nombre, sizeof(unAlumno.nombre), stdin);
unAlumno.nombre[strcspn(unAlumno.nombre, "\n")] = '\0';

printf("Promedio: ");
scanf("%f", &unAlumno.promedio);
fflush(stdin);

fwrite(&unAlumno, sizeof(Alumno), 1, arch);

printf("?Desea ingresar otro alumno? (s/n): ");
scanf(" %c", &resp);
fflush(stdin);
} while (resp == 's' || resp == 'S');
}
