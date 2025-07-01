Este programa demuestra la declaración de una estructura, el acceso a los
campos de los apuntadores de tipo estructura para lectura y escritura, y el uso de
una función que recibe un apuntador de tipo estructura como parámetro.

#include <stdio.h>
#include <string.h>
#include <stdlib.h> // Necesario para new o malloc/free, aunque el texto usa 'new'
de forma no estándar de C
struct alumno /* Declaración de la estructura. */
{
int matricula;
char nombre;
char carrera; /* Campos de la estructura alumno. */
float promedio;
char direccion;
};
void Lectura(struct alumno *); /* Prototipo de función. */
void main(void) {
struct alumno a0 = {120, ”María”, ”Contabilidad”, 8.9, ”Querétaro”};
struct alumno *a3, *a4, *a5, a6; /* Observa que las variables *a3, *a4 y *a5 se
declaran como apuntadores de ➥tipo estructura alumno. a6 es una variable de
tipo estructura alumno. */
a3 = &a0; /* En este caso al apuntador de tipo estructura alumno a3 ➥se
le asigna la dirección de la variable de tipo estructura alumno, a0. */
// Original source uses 'new (struct alumno)' which is C++ syntax.
// In C, you'd use malloc: a4 = (struct alumno *)malloc(sizeof(struct alumno));
a4 = (struct alumno *)malloc(sizeof(struct alumno));
if (a4 == NULL) { /* Handle allocation error */ return; }
strcpy(a4->nombre, ”Pedro”); // Using -> for pointer access
strcpy(a4->carrera, ”Informática”);
a4->matricula = 200;
a4->promedio = 7.8;
strcpy(a4->direccion, ”México”);
// Original source uses 'new (struct alumno)'
// In C, you'd use malloc: a5 = (struct alumno *)malloc(sizeof(struct alumno));
a5 = (struct alumno *)malloc(sizeof(struct alumno));
if (a5 == NULL) { /* Handle allocation error */ return; }
Lectura(a5); /* En este caso se pasa el apuntador de tipo estructura alumno
a5 a la función Lectura. */
Lectura(&a6); /* En este caso se pasa la variable de tipo estructura alumno a6,
➥a la función Lectura. Observa que en este caso debemos utilizar el operador de

➥dirección para preceder a la variable. */
printf(”\nDatos del alumno 3\n”); /* Observa la forma de escribir los campos de
los apuntadores de tipo ➥estructura. */
printf(”%d\t%s\t%s\t%.2f\t%s”, a3->matricula, a3->nombre, a3->carrera, a3-
>promedio, a3->direccion);
printf(”\nDatos del alumno 4\n”);
printf(”%d\t%s\t%s\t%.2f\t%s”, a4->matricula, a4->nombre, a4->carrera, a4-
>promedio, a4->direccion);
printf(”\nDatos del alumno 5\n”);
printf(”%d\t%s\t%s\t%f\t%s”, a5->matricula, a5->nombre, a5->carrera, a5-
>promedio, a5->direccion);
printf(”\nDatos del alumno 6\n”); /* Observa la forma de escribir los campos de
la variable tipo estructura. */
printf(”%d\t%s\t%s\t%.2f\t%s”, a6.matricula, a6.nombre, a6.carrera,
a6.promedio, a6.direccion);
// Free allocated memory (good practice in C)
free(a4);
free(a5);
}
void Lectura(struct alumno *a) /* Esta función permite leer los campos de un
apuntador de tipo estructura ➥alumno. */
{
printf(”\nIngrese la matrícula del alumno: ”);
scanf(”%d”, &(*a).matricula);
fflush(stdin);
printf(”Ingrese el nombre del alumno: ”);
gets(a->nombre);
fflush(stdin);
printf(”Ingrese la carrera del alumno: ”);
gets((*a).carrera);
printf(”Ingrese el promedio del alumno: ”);
scanf(”%f”, &a->promedio);
fflush(stdin);
printf(”Ingrese la dirección del alumno: ”);
gets(a->direccion);
}